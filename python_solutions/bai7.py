# Bài 7: Đếm các phần tử chia hết cho 3 và tính tổng của chúng
#
# Mô tả: Cho một danh sách số, xác định bao nhiêu phần tử chia hết cho 3 và
# tính tổng các phần tử đó.
#
# Ví dụ:
#  Input: 1 3 4 6 7
#  Output:
#    Số phần tử chia hết cho 3: 2
#    Tổng các giá trị chia hết cho 3: 9

ds = [int(i) for i in input().split()]
count_div3 = 0
sum_div3 = 0
for x in ds:
    if x % 3 == 0:
        count_div3 += 1
        sum_div3 += x

print("Số phần tử chia hết cho 3:", count_div3)
print("Tổng các giá trị chia hết cho 3:", sum_div3)
