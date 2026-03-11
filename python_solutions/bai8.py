# Bài 8: Đếm các phần tử âm và liệt kê các số âm
#
# Mô tả: Nhập một dãy số nguyên; chương trình in số lượng số âm và danh sách các
# số âm đó.
#
# Ví dụ:
#  Input: -1 2 -3 4
#  Output:
#    Số phần tử âm: 2
#    Các số âm: [-1, -3]

ds = [int(i) for i in input().split()]
negatives = []
for x in ds:
    if x < 0:
        negatives.append(x)

print("Số phần tử âm:", len(negatives))
print("Các số âm:", negatives)
