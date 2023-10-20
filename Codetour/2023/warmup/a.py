# Scary night (Data Structure)
# Cho trước chuỗi S

# N (1e6): Độ dài chuổi S
# Q (1e5): Số lượng query
# 1 i c: Chọn index i (1-indexed), c = N,S,W,E
# 2 i j k: Chọn từ [i,j] xong xoay 90*k độ (1<=k<=1000)

# Làm lần lượt từng query
# Số lượng query mà hợp lệ ?? Tối đa là Q, cho phép trùng nhau
# Hợp lệ là đi từ trung tâm và quay về chỗ cũ, sum = 0