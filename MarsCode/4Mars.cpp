/* 小M面对一组从 1 到 9 的数字，这些数字被分成多个小组，并从每个小组中选择一个数字组成一个新的数。目标是使得这个新数的各位数字之和为偶数。任务是计算出有多少种不同的分组和选择方法可以达到这一目标。

numbers: 一个由多个整数字符串组成的列表，每个字符串可以视为一个数字组。小M需要从每个数字组中选择一个数字。
例如对于[123, 456, 789]，14个符合条件的数为：147 149 158 167 169 248 257 259 268 347 349 358 367 369。 */
#include <iostream>
#include <vector>

int solution(std::vector<int> numbers) {
    // Please write your code here
    int len = numbers.size();
    std::vector<std::vector<int>> dp(len, std::vector<int>(2));
    for (int i = 0; i < len; i++)
    {
        int cur = numbers[i];
        int odd = 0;
        int even = 0;

        while (cur)
        {
            int en = cur % 10;
            cur = cur / 10;
            if (en % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        if (i == 0)
        {
            dp[i][0] = odd;
            dp[i][1] = even;
            continue;
        }
        dp[i][0] = dp[i-1][0] * even + dp[i-1][1] * odd;
        dp[i][1] = dp[i-1][0] * odd + dp[i-1][1] * even;
    }
    

    return dp[len-1][1];
}

int main() {
    // You can add more test cases here
    std::cout << (solution({123, 456, 789}) == 14) << std::endl;
    std::cout << (solution({123456789}) == 4) << std::endl;
    std::cout << (solution({14329, 7568}) == 10) << std::endl;
    return 0;
}