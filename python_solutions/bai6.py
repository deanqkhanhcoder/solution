# Bài 6: Đếm các phần tử có giá trị chẵn và tính tổng của chúng
#
# Mô tả: Đếm số lượng các số chẵn trong danh sách đầu vào và cộng tổng chúng.
#
# Ví dụ:
#  Input: 1 2 3 4 5
#  Output:
#    Số phần tử chẵn: 2
#    Tổng các giá trị chẵn: 6

ds = [int(i) for i in input().split()]
count_even = 0
sum_even = 0
for x in ds:
    if x % 2 == 0:
        count_even += 1
        sum_even += x

print("Số phần tử chẵn:", count_even)
print("Tổng các giá trị chẵn:", sum_even)
