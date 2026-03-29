// xor_nn_tuned.cpp
#include <bits/stdc++.h>
using namespace std;

// stable sigmoid
static inline double sigmoid(double x){
    if (x >= 0) {
        double z = exp(-x);
        return 1.0 / (1.0 + z);
    } else {
        double z = exp(x);
        return z / (1.0 + z);
    }
}
static inline double dsigmoid_from_sig(double s){ return s * (1.0 - s); }

// Xavier uniform initializer
double xavier_uniform(int fan_in, int fan_out, std::mt19937 &rng) {
    double limit = sqrt(6.0 / (fan_in + fan_out));
    std::uniform_real_distribution<double> unif(-limit, limit);
    return unif(rng);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.setf(std::ios::fixed); cout<<setprecision(6);

    // XOR dataset
    vector<array<double,2>> X = {{0,0},{0,1},{1,0},{1,1}};
    vector<int> Y = {0,1,1,0};
    const int N = 4;

    // hyperparams (tuned)
    const double lr = 0.02;          // base learning rate for Adam
    const double weight_decay = 1e-5;
    const int epochs = 30000;
    const int print_every = 500;
    const double grad_clip_norm = 100.0; // gradient clipping
    const double eps = 1e-8;
    const double beta1 = 0.9, beta2 = 0.999;

    // rng
    std::mt19937 rng(123456);

    // model params (2 hidden neurons, same as original)
    double W1[2][2], b1[2];   // hidden x input
    double W2[2]; double b2;  // output weights (1x2) and bias

    // Xavier init
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++) W1[i][j] = xavier_uniform(2, 2, rng);
        b1[i] = 0.0;
    }
    for (int i=0;i<2;i++) W2[i] = xavier_uniform(2, 1, rng);
    b2 = 0.0;

    // Adam moments (same shapes)
    double mW1[2][2] = {{0,0},{0,0}}, vW1[2][2] = {{0,0},{0,0}};
    double mb1[2] = {0,0}, vb1[2] = {0,0};
    double mW2[2] = {0,0}, vW2[2] = {0,0};
    double mb2 = 0.0, vb2 = 0.0;
    int t = 0;

    cout << "[TRAIN START] lr="<<lr<<" weight_decay="<<weight_decay<<" epochs="<<epochs<<"\n";

    for (int e=1; e<=epochs; ++e){
        // zero grads
        double dW1[2][2] = {{0,0},{0,0}};
        double db1[2] = {0,0};
        double dW2[2] = {0,0};
        double db2 = 0.0;
        double loss = 0.0;

        // forward-backward over full batch (4 samples)
        for (int i=0;i<N;i++){
            double x0 = X[i][0], x1 = X[i][1];
            int y = Y[i];

            // forward hidden (sigmoid as original code)
            double z1_0 = W1[0][0]*x0 + W1[0][1]*x1 + b1[0];
            double a1_0 = sigmoid(z1_0);
            double z1_1 = W1[1][0]*x0 + W1[1][1]*x1 + b1[1];
            double a1_1 = sigmoid(z1_1);

            // output
            double z2 = W2[0]*a1_0 + W2[1]*a1_1 + b2;
            double a2 = sigmoid(z2);

            // BCE loss (stable)
            double a2_clamped = min(max(a2, 1e-15), 1.0 - 1e-15);
            loss += -( y * log(a2_clamped) + (1 - y) * log(1 - a2_clamped) );

            // gradient of BCE w.r.t z2 when using sigmoid output => delta2 = a2 - y
            double delta2 = a2 - y;

            // grads W2, b2
            dW2[0] += delta2 * a1_0;
            dW2[1] += delta2 * a1_1;
            db2 += delta2;

            // backprop to hidden
            double delta1_0 = (W2[0] * delta2) * dsigmoid_from_sig(a1_0);
            double delta1_1 = (W2[1] * delta2) * dsigmoid_from_sig(a1_1);

            dW1[0][0] += delta1_0 * x0;
            dW1[0][1] += delta1_0 * x1;
            db1[0] += delta1_0;

            dW1[1][0] += delta1_1 * x0;
            dW1[1][1] += delta1_1 * x1;
            db1[1] += delta1_1;
        }

        // average
        loss /= N;
        for (int i=0;i<2;i++){
            dW1[i][0] /= N; dW1[i][1] /= N; db1[i] /= N;
            dW2[i] /= N;
        }
        db2 /= N;

        // weight decay (L2) on weights (not biases)
        for (int i=0;i<2;i++){
            dW2[i] += weight_decay * W2[i];
            dW1[i][0] += weight_decay * W1[i][0];
            dW1[i][1] += weight_decay * W1[i][1];
        }

        // gradient clipping (global norm)
        double sqsum = 0.0;
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++) sqsum += dW1[i][j]*dW1[i][j];
            sqsum += db1[i]*db1[i];
            sqsum += dW2[i]*dW2[i];
        }
        sqsum += db2*db2;
        double gnorm = sqrt(sqsum);
        if (gnorm > grad_clip_norm){
            double scale = grad_clip_norm / gnorm;
            for (int i=0;i<2;i++){
                for (int j=0;j<2;j++) dW1[i][j] *= scale;
                db1[i] *= scale;
                dW2[i] *= scale;
            }
            db2 *= scale;
        }

        // Adam update
        t++;
        double b1t = pow(beta1, t);
        double b2t = pow(beta2, t);

        // W1
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                double g = dW1[i][j];
                mW1[i][j] = beta1 * mW1[i][j] + (1 - beta1) * g;
                vW1[i][j] = beta2 * vW1[i][j] + (1 - beta2) * g * g;
                double mhat = mW1[i][j] / (1 - b1t);
                double vhat = vW1[i][j] / (1 - b2t);
                W1[i][j] -= lr * mhat / (sqrt(vhat) + eps);
            }
        }
        // b1
        for (int i=0;i<2;i++){
            double g = db1[i];
            mb1[i] = beta1 * mb1[i] + (1 - beta1) * g;
            vb1[i] = beta2 * vb1[i] + (1 - beta2) * g * g;
            double mhat = mb1[i] / (1 - b1t);
            double vhat = vb1[i] / (1 - b2t);
            b1[i] -= lr * mhat / (sqrt(vhat) + eps);
        }
        // W2
        for (int i=0;i<2;i++){
            double g = dW2[i];
            mW2[i] = beta1 * mW2[i] + (1 - beta1) * g;
            vW2[i] = beta2 * vW2[i] + (1 - beta2) * g * g;
            double mhat = mW2[i] / (1 - b1t);
            double vhat = vW2[i] / (1 - b2t);
            W2[i] -= lr * mhat / (sqrt(vhat) + eps);
        }
        // b2
        {
            double g = db2;
            mb2 = beta1 * mb2 + (1 - beta1) * g;
            vb2 = beta2 * vb2 + (1 - beta2) * g * g;
            double mhat = mb2 / (1 - b1t);
            double vhat = vb2 / (1 - b2t);
            b2 -= lr * mhat / (sqrt(vhat) + eps);
        }

        // diagnostics
        if (e % print_every == 0 || e == 1){
            // compute accuracy quickly
            int correct = 0;
            for (int i=0;i<N;i++){
                double x0 = X[i][0], x1 = X[i][1];
                double a1_0 = sigmoid(W1[0][0]*x0 + W1[0][1]*x1 + b1[0]);
                double a1_1 = sigmoid(W1[1][0]*x0 + W1[1][1]*x1 + b1[1]);
                double a2 = sigmoid(W2[0]*a1_0 + W2[1]*a1_1 + b2);
                int pred = (a2 >= 0.5) ? 1 : 0;
                if (pred == Y[i]) ++correct;
            }
            cout << "[Epoch " << e << "] loss="<< loss << " acc=" << (double)correct/N << "\n";
        }

        // early stop if perfect
        bool perfect = true;
        for (int i=0;i<N;i++){
            double x0 = X[i][0], x1 = X[i][1];
            double a1_0 = sigmoid(W1[0][0]*x0 + W1[0][1]*x1 + b1[0]);
            double a1_1 = sigmoid(W1[1][0]*x0 + W1[1][1]*x1 + b1[1]);
            double a2 = sigmoid(W2[0]*a1_0 + W2[1]*a1_1 + b2);
            int pred = (a2 >= 0.5) ? 1 : 0;
            if (pred != Y[i]) { perfect = false; break; }
        }
        if (perfect){
            cout << "=> Perfect classification at epoch " << e << "\n";
            break;
        }
    } // epochs

    cout << "\n--- TRAINED MODEL (probability, class) ---\n";
    for (int i=0;i<N;i++){
        double x0 = X[i][0], x1 = X[i][1];
        double a1_0 = sigmoid(W1[0][0]*x0 + W1[0][1]*x1 + b1[0]);
        double a1_1 = sigmoid(W1[1][0]*x0 + W1[1][1]*x1 + b1[1]);
        double a2 = sigmoid(W2[0]*a1_0 + W2[1]*a1_1 + b2);
        int pred = (a2 >= 0.5) ? 1 : 0;
        cout << "Input: " << (int)x0 << " " << (int)x1
             << " => prob=" << a2 << " class=" << pred
             << " (target=" << Y[i] << ")\n";
    }

    return 0;
}
