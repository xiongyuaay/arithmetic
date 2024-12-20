#include <iostream>
#include <set>
#include <string>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() 
{
    int n;
    string steps;
    cin >> n >> steps;

    int x = 0, y = 0, dir = 0;
    pair<int, int> position[n + 1]; 
    int direction[n + 1];         

    position[0] = {0, 0};
    direction[0] = 0;

    for (int i = 1; i <= n; ++i) 
    {
        if (steps[i - 1] == 'F') 
        {
            x += dx[dir];
            y += dy[dir];
        } 
        else if (steps[i - 1] == 'L') 
        {
            dir = (dir + 3) % 4; 
            x += dx[dir];
            y += dy[dir];
        } 
        else if (steps[i - 1] == 'R') 
        {
            dir = (dir + 1) % 4; 
            x += dx[dir];
            y += dy[dir];
        }
        position[i] = {x, y};
        direction[i] = dir;
    }

    set<pair<int, int>> uniquePositions;

    for (int i = 1; i <= n; ++i) {
        int px = position[i - 1].first, py = position[i - 1].second, pdir = direction[i - 1];

        for (char newStep : {'F', 'L', 'R'}) {
            if (steps[i - 1] == newStep) continue;

            int nx = px, ny = py, ndir = pdir;
            if (newStep == 'F') 
            {
                nx += dx[ndir];
                ny += dy[ndir];
            } 
            else if (newStep == 'L') 
            {
                ndir = (ndir + 3) % 4;
                nx += dx[ndir];
                ny += dy[ndir];
            } 
            else if (newStep == 'R') 
            {
                ndir = (ndir + 1) % 4;
                nx += dx[ndir];
                ny += dy[ndir];
            }

            for (int j = i + 1; j <= n; ++j) {
                if (steps[j - 1] == 'F') 
                {
                    nx += dx[ndir];
                    ny += dy[ndir];
                } 
                else if (steps[j - 1] == 'L') 
                {
                    ndir = (ndir + 3) % 4;
                    nx += dx[ndir];
                    ny += dy[ndir];
                } 
                else if (steps[j - 1] == 'R') 
                {
                    ndir = (ndir + 1) % 4;
                    nx += dx[ndir];
                    ny += dy[ndir];
                }
            }

            uniquePositions.insert({nx, ny});
        }
    }

    cout << uniquePositions.size() << endl;

    return 0;
}
