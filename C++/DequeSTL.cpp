#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k)
{
    // Write your code here.

    deque<int> container;

    for (int index = 0; index < n; index++)
    {
        while (!container.empty() && arr[index] > container.back())
        {
            container.pop_back();
        }

        container.push_back(arr[index]);

        if (index >= k && container.front() == arr[index - k])
        {
            container.pop_front();
        }
        if (index >= k - 1)
            cout << container.front() << " ";
    }

    cout << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
