/* 给你两个正整数 xCorner 和 yCorner 和一个二维整数数组 circles ，其中 circles[i] = [xi, yi, ri] 表示一个圆心在 (xi, yi) 半径为 ri 的圆。

坐标平面内有一个左下角在原点，右上角在 (xCorner, yCorner) 的矩形。你需要判断是否存在一条从左下角到右上角的路径满足：路径 完全 在矩形内部，不会 触碰或者经过 任何 圆的内部和边界，同时 只 在起点和终点接触到矩形。

如果存在这样的路径，请你返回 true ，否则返回 false 。 */

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


class Solution 
{
public:
    bool canReachCorner(int xCorner, int yCorner, vector<vector<int>>& circles) 
    {
        vector<vector<int>> path;
        for(auto it=circles.begin();it!=circles.end();it++)
        {
            if (it->at(0) + it->at(2) <= 0 || it->at(0) - it->at(2) >= xCorner || it->at(1) + it->at(2) <= 0 || it->at(1) - it->at(2) >= yCorner)
            {
                circles.erase(it);
                it--;
                continue;
            }
            __int64 x1 = it->at(0), y1 = it->at(1), r1 = it->at(2);
            if ((pow(x1, 2) + pow(y1, 2) <= pow(r1, 2)) || (pow(x1, 2) + pow(y1 - yCorner, 2) <= pow(r1, 2)) || (abs(x1) <= r1 && y1 >= 0 && y1 <= yCorner) || (abs(y1 - yCorner) <= r1 && x1 >= 0 && x1 <= xCorner) || ((x1 - xCorner)*(x1 - xCorner) + (y1 - yCorner)*(y1 - yCorner) - r1*r1 <= 0))
            {
                path.push_back(*it);
                circles.erase(it);
                it--;
            }
            
        }  
        if(!circles.size() && !path.size())
        {
            return true;
        }
        while (path.size())
        {
            vector<int> circle = path.front();
            path.erase(path.begin());
            __int64 x2 = circle[0], y2 = circle[1], r2 = circle[2];
            if((x2*x2 + y2*y2 <= r2*r2) || ((x2 - xCorner)*(x2 - xCorner) + y2*y2 <= r2*r2) || ((x2 - xCorner)*(x2 - xCorner) + (y2 - yCorner)*(y2 - yCorner) <= r2*r2) || (abs(x2 - xCorner) <= r2 && y2 >= 0 && y2 <= yCorner) || (abs(y2) <= r2 && x2 >= 0 && x2 <= xCorner))
            {
                return false;
            }
            for (auto it=circles.begin();it!=circles.end();it++)
            {
                int x1 = it->at(0), y1 = it->at(1), r1 = it->at(2);
                __int64 R = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
                __int64 R_2 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
                if(R_2 <= (r1 + r2)*(r1 + r2))
                {
                    double r1_2 = pow(r1, 2);
                    double r2_2 = pow(r2, 2);
                    double temp1 = (r1_2 - r2_2) / (2*R_2);
                    double temp2 = (sqrt(2*(r1_2 + r2_2) / R_2 - pow(r1_2 -r2_2, 2) / pow(R_2, 2) - 1)) / 2;
                    double a1 = (x1 + x2)/2 + temp1 * (x2 - x1);
                    double a2 = (y2 - y1) * temp2;
                    double b1 = (y1 + y2)/2 + temp1 * (y2 - y1);
                    double b2 = (x1 - x2) * temp2;
                    if ((a1 + a2 < 0 && b1 + b2 < 0 && a1 - a2 < 0 && b1 - b2 < 0) || (a1 + a2 > xCorner && b1 + b2 > yCorner && a1 - a2 > xCorner && b1 - b2 > yCorner))
                    {
                        continue;
                    }
                    
                    path.push_back(*it);
                    circles.erase(it);
                    it--;
                }
            }
            
        }
        return true;
    }

};

int main()
{
    Solution s;
    int x = 500000000;
    int y = 500000000;
    vector<vector<int>> c = {{499980000,699999999,200000000}, {500020000,300000001,200000000}};
    if(s.canReachCorner(x, y, c))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    
    return 0;
}