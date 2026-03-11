# Bài 3: Đếm các phần tử âm và tính tổng của chúng
#
# Mô tả: Cho một danh sách số nguyên. Hãy đếm xem có bao nhiêu phần tử âm và
# tính tổng các phần tử âm đó.
#
# Ví dụ:
#  Input: 1 -2 3 -4 5
#  Output:
#    Số phần tử âm: 2
#    Tổng các giá trị âm: -6

ds = [int(i) for i in input().split()]
count_negative = 0
sum_negative = 0
for x in ds:
    if x < 0:
        count_negative += 1
        sum_negative += x

print("Số phần tử âm:", count_negative)
print("Tổng các giá trị âm:", sum_negative)
