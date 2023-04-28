#include <bits/stdc++.h>

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */

/* ---------- Min Heap ---------- */

class minHeap
{
public:
    minHeap(const std::vector<int> &);

    void insert(int);
    int deleteMin();
    int size() const;
    int getMin() const;

private:
    std::vector<int> heap;

    void percolateUp(int);
    void percolateDown(int);
    void heapify();
};

minHeap::minHeap(const std::vector<int> &arr) : heap(arr)
{
    heapify();    
}

int minHeap::getMin() const {
    return heap[0];
}

void minHeap::insert(int value)
{
    heap.push_back(value);
    percolateUp(size() - 1);
}

int minHeap::deleteMin()
{
    if (size() == 0)
        throw "Heap is empty";

    int min = heap[0];
    heap[0] = heap[size() - 1];
    heap.pop_back();
    percolateDown(0);
    return min;
}

void minHeap::heapify()
{
    for (int i = size() / 2 - 1; i >= 0; --i)
    {
        percolateDown(i);
    }
}

void minHeap::percolateUp(int hole)
{
    int value = heap[hole];

    while (hole > 0 && value < heap[(hole - 1) / 2])
    {
        heap[hole] = heap[(hole - 1) / 2];
        hole = (hole - 1) / 2;
    }
    heap[hole] = value;
}

void minHeap::percolateDown(int hole)
{
    int value = heap[hole];
    int child;

    for (; 2 * hole + 1 < size(); hole = child)
    {
        child = 2 * hole + 1;
        if (child + 1 < size() && heap[child + 1] < heap[child])
            child++;

        if (heap[child] < value)
            heap[hole] = heap[child];
        else
            break;
    }

    heap[hole] = value;
}

int minHeap::size() const
{
    return heap.size();
}

/* ---------- Main Function ---------- */

int cookies(int k, std::vector<int> A)
{
    minHeap heap(A);

    int result = 0;

    while(heap.getMin() < k && heap.size() > 1) {
        int combine1 = heap.deleteMin();
        int combine2 = heap.deleteMin();

        int toInsert = combine1 + 2 * combine2;

        heap.insert(toInsert);
        result++;
    }

    return (heap.getMin() < k) ? -1 : result;
}

int main()
{
    int n, k;

    std::ifstream inputFile;
    std::string fileName = "input.txt";
    inputFile.open(fileName.c_str());
    std::string line;
    std::getline(inputFile, line);
    std::stringstream lineReader(line);

    lineReader >> n >> k;

    std::getline(inputFile, line);

    lineReader = std::stringstream(line);

    std::vector<int> array(n);

    for (int index = 0; index < n; index++)
    {
        lineReader >> array[index];
    }

    std::cout << cookies(k, array) << std::endl;

    return 0;
}
