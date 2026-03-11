# Bài 1: Tổng số tiền điện của cả năm và tiền điện trung bình theo tháng
#
# Mô tả: Nhập một dòng gồm các số nguyên, mỗi số là tiền điện của một tháng trong năm.
# Chương trình tính:
#  1. Tổng tiền điện của cả năm.
#  2. Tiền điện trung bình mỗi tháng (tổng chia cho số tháng nhập).
#
# Ví dụ:
#  Input: 120 130 110 140 150 160 170 180 190 200 210 220
#  Output:
#    Tổng tiền điện cả năm: 1970
#    Tiền điện trung bình theo tháng: 164.16666666666666
#
# Lưu ý: nếu không nhập số nào thì kết quả là 0.

# Đọc danh sách tiền điện (giả sử 12 giá trị, nhưng không bắt buộc phải kiểm tra số lượng)
bills = [int(i) for i in input().split()]

# Tổng tiền điện của cả năm
total = 0
for v in bills:
    total += v

# Trung bình theo tháng (nếu có ít nhất một tháng)
average = total / len(bills)

# In kết quả ra màn hình
print("Tổng tiền điện cả năm:", total)
print("Tiền điện trung bình theo tháng:", average)
