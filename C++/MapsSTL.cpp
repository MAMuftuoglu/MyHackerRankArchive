#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int queryNum, mark, numLoops = 0, choice;
    ;
    string name;
    map<string, int> studentMap;

    cin >> queryNum;

    while (numLoops < queryNum)
    {
        numLoops++;

        cin >> choice >> name;

        if (choice == 1)
        {
            cin >> mark;

            if (studentMap.find(name) != studentMap.end())
            {
                studentMap.find(name)->second += mark;
            }
            else
            {
                studentMap.insert(make_pair(name, mark));
            }
        }
        else if (choice == 2)
        {
            if (studentMap.find(name) != studentMap.end())
            {
                studentMap.erase(name);
            }
        }
        else if (choice == 3)
        {
            if (studentMap.find(name) != studentMap.end())
            {
                cout << studentMap.find(name)->second << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
