#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int queryNum, numOfLoop = 0;
    int choice, value;
    set<int> intSet;

    cin >> queryNum;

    while (numOfLoop < queryNum)
    {
        numOfLoop++;

        cin >> choice >> value;

        if (choice == 1)
        {
            intSet.insert(value);
        }
        else if (choice == 2)
        {
            if (intSet.find(value) != intSet.end())
            {
                intSet.erase(value);
            }
        }
        else if (choice == 3)
        {
            if (intSet.find(value) != intSet.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
