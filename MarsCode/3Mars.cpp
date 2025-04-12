/* 小M在工作时遇到了一个问题，他需要将用户输入的不带千分位逗号的数字字符串转换为带千分位逗号的格式，并且保留小数部分。小M还发现，有时候输入的数字字符串前面会有无用的 0，这些也需要精简掉。请你帮助小M编写程序，完成这个任务。 */

#include <string>
#include <iostream>

std::string solution(const std::string& s) {
    // write code here
    int len = s.size();
    std::string res = s;
    
    for (int i = 0; i < len; i++)
    {
        if (s[i] != '0')
        {
            res = s.substr(i);
            break;
        }
    }
    int dot = res.size();
    
    if (res.find(".") != std::string::npos)
    {
        dot = res.find(".");
    }
    int count = 0;
    for (int i = dot-1; i > 0; i--)
    {
        count++;
        
        if (count == 3)
        {
            res.insert(i, ",");
            count = 0;
        }
        
    }
    
    

    return res;
}

int main() {
    solution("02300545202");
    std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
}