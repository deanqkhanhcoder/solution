# Bài 12: Đếm các phần tử chia hết cho 3 và liệt kê các số đó
#
# Mô tả: Nhập một danh sách số nguyên, xác định các giá trị chia hết cho 3 và
# hiển thị cả số lượng và danh sách.
#
# Ví dụ:
#  Input: 2 3 5 6 9
#  Output:
#    Số phần tử chia hết cho 3: 3
#    Các số chia hết cho 3: [3, 6, 9]
ds = [int(i) for i in input().split()]
div3_list = []
for x in ds:
    if x % 3 == 0:
        div3_list.append(x)

print("Số phần tử chia hết cho 3:", len(div3_list))
print("Các số chia hết cho 3:", div3_list)
