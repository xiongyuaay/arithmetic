#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;
    string target = "LANQIAO";
    int j = 0; 

    for (int i = 0; i < input.size(); i++) 
    {
        if (input[i] == target[j]) 
        {
            j++; 
        }
        if (j == target.size()) 
        {
            cout << "YES" << endl; 
            return 0;
        }
    }
    cout << "NO" << endl; 
    return 0;
}
