#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int solution(int a, int b) {
  // PLEASE DO NOT MODIFY THE FUNCTION SIGNATURE
  // write code here
  int temp = a;
  int res = 0;
  int b_n = b?log10(b) + 1:1;
  int b_top = b / pow(10, b_n-1);
  vector<int> num;
  while (temp) {
    int cur = temp % 10;
    num.emplace_back(cur);
    temp = temp / 10;
  }
  int n = num.size();
  int flag = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (!flag && num[i] > b_top) {
      res += num[i] * pow(10, i + b_n);
      continue;
    }
    if (!flag && num[i] <= b_top) {
      res += b * pow(10, i + b_n) + num[i] * pow(10, i);
      flag = 1;
      continue;
    }
    res += num[i] * pow(10, i);
  }
  if (!flag)
  {
    res += b;
  }
  
  return res;
}

int main() {
  cout << (solution(9, 15) == 915) << endl;
  cout << (solution(76543, 4) == 765443) << endl;
  cout << (solution(1, 0) == 10) << endl;
  cout << (solution(44, 5) == 544) << endl;
  cout << (solution(666, 6) == 6666) << endl;
  return 0;
}