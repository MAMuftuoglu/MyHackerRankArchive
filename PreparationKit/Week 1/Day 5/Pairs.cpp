#include <bits/stdc++.h>

/*
 * Complete the 'pairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 * 1. INTEGER k
 * 2. INTEGER_ARRAY arr
 */
void heapify(std::vector<int> &arr, int end, int root)
{
    int largest = root;

    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < end && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < end && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        int temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;

        heapify(arr, end, largest);
    }
}
void heapSort(std::vector<int> &arr, int end)
{
    for (int index = end / 2 - 1; index >= 0; index--)
    {
        heapify(arr, end, index);
    }

    for (int index = end - 1; index > 0; index--)
    {
        int temp = arr[index];
        arr[index] = arr[0];
        arr[0] = temp;

        heapify(arr, index, 0);
    }
}
int pairs(int k, std::vector<int> arr)
{
    heapSort(arr, arr.size());

    int numOfPairs = 0;

    for (int index = 0; index < arr.size() - 1; index++)
    {
        int left = 0, right = arr.size() - 1;
        bool carryOn = true;
        while (carryOn && left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] - arr[index] == k)
            {
                numOfPairs++;
                carryOn = false;
            }
            else if (arr[mid] - arr[index] > k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    return numOfPairs;
}
