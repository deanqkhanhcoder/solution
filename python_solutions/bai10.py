# Bài 10: Đếm các phần tử lẻ và liệt kê các số lẻ
#
# Mô tả: Nhập danh sách số nguyên; tìm và in số lượng số lẻ và danh sách số lẻ.
#
# Ví dụ:
#  Input: 1 2 3 4 5
#  Output:
#    Số phần tử lẻ: 3
#    Các số lẻ: [1, 3, 5]

ds = [int(i) for i in input().split()]
odd_list = []
for x in ds:
    if x % 2 != 0:
        odd_list.append(x)

print("Số phần tử lẻ:", len(odd_list))
print("Các số lẻ:", odd_list)
