# Bài 9: Đếm các phần tử dương và liệt kê các số dương
#
# Mô tả: Với đầu vào là các số nguyên, in số lượng số dương và danh sách các số
# dương đó.
#
# Ví dụ:
#  Input: -1 2 -3 4
#  Output:
#    Số phần tử dương: 2
#    Các số dương: [2, 4]

ds = [int(i) for i in input().split()]
pos_list = []
for x in ds:
    if x > 0:
        pos_list.append(x)

print("Số phần tử dương:", len(pos_list))
print("Các số dương:", pos_list)
