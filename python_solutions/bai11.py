# Bài 11: Đếm các phần tử chẵn và liệt kê các số chẵn
#
# Mô tả: Tương tự bài 10 nhưng với số chẵn. Nhập danh sách nguyên, in số lượng
# số chẵn và danh sách chúng.
#
# Ví dụ:
#  Input: 1 2 3 4 5
#  Output:
#    Số phần tử chẵn: 2
#    Các số chẵn: [2, 4]

ds = [int(i) for i in input().split()]
even_list = []
for x in ds:
    if x % 2 == 0:
        even_list.append(x)

print("Số phần tử chẵn:", len(even_list))
print("Các số chẵn:", even_list)
