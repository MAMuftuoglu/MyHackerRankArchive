#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

template <class Data>
struct QueueNode
{
    Data item;
    QueueNode *next;

    QueueNode(const Data &newItem) : item(newItem), next(nullptr) {}
};

template <class Data>
class Queue
{
private:
    QueueNode<Data> *front, *end;
    int size;

public:
    Queue() : front(nullptr), end(nullptr), size(0) {}
    ~Queue()
    {
        while(front != nullptr)
        {
            Data temp;
            this->dequeue(temp);
        }
    }

    /**
     * Enqueues the given item to the end of queue
     * @param newItem is the item that is going to be enqueued
     * */
    void enqueue(const Data &newItem)
    {
        size++;

        if (end == nullptr)
        {
            end = new QueueNode<Data>(newItem);
            front = end;
        }
        else
        {
            end->next = new QueueNode<Data>(newItem);
            end = end->next;
        }
    }

    /**
     * Dequeues the element which was enqueued first.
     * @param deletedItem The removed item
     * */
    void dequeue(Data &deletedItem)
    {
        if (size != 0)
        {
            deletedItem = front->item;
            size--;
            if (front == end)
            {
                delete front;
                front = nullptr;
                end = nullptr;
            }
            else
            {
                QueueNode<Data> *temp = front;
                front = front->next;
                delete temp;
            }
        }
    }

    /**
     * @return Number of elements in the queue
     * */
    int qSize() const
    {
        return size;
    }

    /**
     * Turns queue to an array
     * @return Array of a queue
     * */
    Data *toArray() const
    {
        Data *arr = new Data[size];
        int index = 0;

        for (QueueNode<Data> *temp = front; temp != nullptr; temp = temp->next)
        {
            arr[index] = temp->item;
            index++;
        }

        return arr;
    }
};

/**
 * Finds the given char's index by searching from the back
 * @param str Given string that function searches
 * @param searchChar Seacrhed char in given string
 * @return index of char, -1 if cannot find
 * */
int rfind(const string &str, const char searchChar)
{
    int returnIndex = -1, index = str.length() - 1;
    bool searching = true;

    while (searching)
    {
        if (index == -1 || str.at(index) == searchChar)
        {
            returnIndex = index;
            searching = false;
        }

        index--;
    }
    return returnIndex;
}

struct Wall
{
    vector<int> crackNums;
    int currHeight;

    void updateCrack(string extendStr)
    {
        auto foundIndex = extendStr.find(",");

        while (foundIndex != string::npos)
        {
            crackNums[stoi(extendStr.substr(0, foundIndex)) - 1]++;
            extendStr = extendStr.substr(foundIndex + 1);
            foundIndex = extendStr.find(",");
        }

        crackNums[stoi(extendStr) - 1]++;
    }

    Wall() : crackNums(vector<int>(0)), currHeight(0) {}

    Wall(string base, int m)
    {
        currHeight = 1;
        crackNums = vector<int>(m, 0);
        updateCrack(base);
    }
};

int legoBlocks(int n, int m)
{
    Queue<string> possibleWalls;
    string wall = "0";
    possibleWalls.enqueue(wall);
    int reachedLimit = 0;
    bool carrryOn = true;

    while (carrryOn)
    {
        possibleWalls.dequeue(wall);

        if (wall.length() == 1 || stoi(wall.substr(rfind(wall, ',') + 1), nullptr) != m)
        {
            int currLength = stoi(wall.substr(rfind(wall, ',') + 1), nullptr);
            string newWall;

            if (currLength + 1 <= m)
            {
                newWall = wall + "," + to_string(currLength + 1);
                possibleWalls.enqueue(newWall);

                if (currLength + 1 == m)
                    reachedLimit++;

                if (currLength + 2 <= m)
                {
                    newWall = wall + "," + to_string(currLength + 2);
                    possibleWalls.enqueue(newWall);

                    if (currLength + 2 == m)
                        reachedLimit++;

                    if (currLength + 3 <= m)
                    {
                        newWall = wall + "," + to_string(currLength + 3);
                        possibleWalls.enqueue(newWall);

                        if (currLength + 3 == m)
                            reachedLimit++;

                        if (currLength + 4 <= m)
                        {
                            newWall = wall + "," + to_string(currLength + 4);
                            possibleWalls.enqueue(newWall);

                            if (currLength + 4 == m)
                                reachedLimit++;
                        }
                    }
                }
            }
        }
        else
        {
            possibleWalls.enqueue(wall);
        }

        if (reachedLimit == possibleWalls.qSize())
            carrryOn = false;
    }

    string *wallArr = possibleWalls.toArray();
    Queue<Wall> allWalls;

    for (int index = 0; index < possibleWalls.qSize(); index++)
    {
        Wall baseWall(wallArr[index].substr(2), m);
        allWalls.enqueue(baseWall);
    }

    carrryOn = true;
    reachedLimit = 0;

    Wall base;

    while (carrryOn)
    {
        allWalls.dequeue(base);

        if (base.currHeight != n)
        {

            for (int index = 0; index < possibleWalls.qSize(); index++)
            {
                Wall newOne = base;
                newOne.updateCrack(wallArr[index].substr(2));
                newOne.currHeight++;

                if (newOne.currHeight == n)
                {
                    bool viable = true;
                    for (int crackIndex = 0; viable && crackIndex < newOne.crackNums.size() - 1; crackIndex++)
                    {
                        if (newOne.crackNums[crackIndex] == n)
                            viable = false;
                    }

                    if (viable)
                    {
                        allWalls.enqueue(newOne);
                        reachedLimit++;
                    }
                }
                else
                    allWalls.enqueue(newOne);
            }
        }
        else
            allWalls.enqueue(base);

        if (reachedLimit == allWalls.qSize())
            carrryOn = false;
    }

    cout << reachedLimit << endl;
    return reachedLimit;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
