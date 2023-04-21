#include <bits/stdc++.h>

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

void percolateDown(std::vector<int> &array, int hole, int size)
{
    int child, temp;

    for (temp = array[hole]; (2 * hole + 1) < size; hole = child)
    {
        child = 2 * hole + 1;
        if ((child != size - 1) && (array[child] > array[child + 1]))
            child++;
        if (array[child] < temp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = temp;
}

int deleteMin(std::vector<int> &array, int &size)
{
    int min = array[0];

    array[0] = array[size - 1];
    size--;
    percolateDown(array, 0, size);

    return min;
}

void insert(std::vector<int> &array, int item, int &size) {
    int hole = ++size;

    for(; hole > 1 && item < array[hole / 2]; hole /= 2) {
        array[hole] = array[hole / 2];
    }

    array[hole] = item;
}

int cookies(int k, std::vector<int> A)
{
    int result = 0;

    int index, size = A.size();
    for (index = A.size() / 2; index >= 0; index--)
    {
        percolateDown(A, index, A.size());
    }

    while (A[0] < k && size > 1)
    {
        int combine1 = deleteMin(A, size), combine2 = deleteMin(A, size);
        insert(A, combine1 + combine2, size);
        result++;
    }

    return (A[0] >= k) ? result : -1;
}

int main()
{
    int n, k;

    std::cin >> n >> k;

    std::vector<int> array(n);

    for (int index = 0; index < n; index++)
    {
        std::cin >> array[index];
    }

    std::cout << cookies(k, array) << std::endl;

    return 0;
}
