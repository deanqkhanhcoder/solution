# Bài 4: Đếm các phần tử dương và tính tổng của chúng
#
# Mô tả: Nhập một danh sách số nguyên, đếm các phần tử lớn hơn 0 và tính tổng.
#
# Ví dụ:
#  Input: -1 2 3 -4 5
#  Output:
#    Số phần tử dương: 3
#    Tổng các giá trị dương: 10

ds = [int(i) for i in input().split()]
count_positive = 0
sum_positive = 0
for x in ds:
    if x > 0:
        count_positive += 1
        sum_positive += x

print("Số phần tử dương:", count_positive)
print("Tổng các giá trị dương:", sum_positive)
