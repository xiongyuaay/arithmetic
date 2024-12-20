#include <iostream>
#include <set>
#include <string>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    int n;
    string steps;
    cin >> n >> steps;

    set<pair<int, int>> uniquePositions;

    for (int i = 0; i < n; i++)
    {
        for (char newStep : {'F', 'L', 'R'}) 
        {
            if (steps[i] == newStep) continue; 

            string newSteps = steps;
            newSteps[i] = newStep;

            int x = 0, y = 0, dir = 0;
            for (char step : newSteps) 
            {
                if (step == 'F') 
                {
                    x += dx[dir];
                    y += dy[dir];
                }
                else if (step == 'L') 
                {
                    dir = (dir + 3) % 4; 
                    x += dx[dir];
                    y += dy[dir];
                } 
                else if (step == 'R') 
                {
                    dir = (dir + 1) % 4; 
                    x += dx[dir];
                    y += dy[dir];
                }
            }

            uniquePositions.insert({x, y});
        }
    }

    cout << uniquePositions.size() << endl;

    return 0;
}
