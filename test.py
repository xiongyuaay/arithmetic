# 给定的整数列表
numbers = [
    534, 386, 319, 692, 169, 338, 521, 713, 640, 692, 969, 362, 311, 349, 308, 357, 515, 140, 591, 216,
    57, 252, 575, 630, 95, 274, 328, 614, 18, 605, 17, 980, 166, 112, 997, 37, 584, 64, 442, 495,
    821, 459, 453, 597, 187, 734, 827, 950, 679, 78, 769, 661, 452, 983, 356, 217, 394, 342, 697, 878,
    475, 250, 468, 33, 966, 742, 436, 343, 255, 944, 588, 734, 540, 508, 779, 881, 153, 928, 764, 703,
    459, 840, 949, 500, 648, 163, 547, 780, 749, 132, 546, 199, 701, 448, 265, 263, 87, 45, 828, 634,
]

# 初始化 dp 数组，dp[i] 表示和模 24 等于 i 时的最大和
mod = 24
dp = [-float('inf')] * mod
dp[0] = 0  # 和为 0 是 24 的倍数

# 动态规划更新 dp 数组
for x in numbers:
    new_dp = dp[:]  # 为避免状态污染，使用临时数组
    for j in range(mod):
        new_dp[(j + x) % mod] = max(new_dp[(j + x) % mod], dp[j] + x)
    dp = new_dp

# 答案为 dp[0]
dp[0]
