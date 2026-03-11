# Bài 5: Đếm các phần tử có giá trị lẻ và tính tổng của chúng
#
# Mô tả: Với đầu vào là một danh sách số nguyên, xác định số lượng phần tử lẻ
# và tổng của chúng.
#
# Ví dụ:
#  Input: 1 2 3 4 5
#  Output:
#    Số phần tử lẻ: 3
#    Tổng các giá trị lẻ: 9

ds = [int(i) for i in input().split()]
count_odd = 0
sum_odd = 0
for x in ds:
    if x % 2 != 0:
        count_odd += 1
        sum_odd += x

print("Số phần tử lẻ:", count_odd)
print("Tổng các giá trị lẻ:", sum_odd)
