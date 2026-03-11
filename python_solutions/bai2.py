# Bài 2: Liệt kê các tháng có số tiền điện nhiều hơn tiền điện trung bình theo tháng
#
# Mô tả: Nhập một dòng gồm các số nguyên biểu diễn tiền điện từng tháng.
# Tính tiền điện trung bình rồi liệt kê các tháng (theo chỉ số 1-based) có giá trị
# lớn hơn trung bình đó.
#
# Ví dụ:
#  Input: 100 120 110
#  Output:
#    Tiền điện trung bình: 110.0
#    Các tháng có tiền điện cao hơn trung bình: [2]

bills = [int(i) for i in input().split()]

total = 0
for v in bills:
    total += v
average = total / len(bills)

months_above = []
idx = 0
for v in bills:
    idx += 1
    if v > average:
        months_above.append(idx)

print("Tiền điện trung bình:", average)
print("Các tháng có tiền điện cao hơn trung bình:", months_above)
