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

    QueueNode(const Data& newItem) : item(newItem), next(nullptr) {}
};

template <class Data>
class Queue
{
private:
    QueueNode<Data> *front, *end;
    int size;

public:
    Queue() : front(nullptr), end(nullptr), size(0) {}


    void enqueue(const Data &newItem)
    {
        size++;

        if(end == nullptr)
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

    void dequeue(Data &deletedItem)
    {
        if(size != 0)
        {
            deletedItem = front->item;
            size--;
            if(front == end)
            {
                delete front;
                front = nullptr;
                end = nullptr;
            }
            else
            {
                QueueNode<Data>* temp = front;
                front = front->next;
                delete temp;
            }
        }
    }

    int qSize() const
    {
        return size;
    }
};

/**
 * Finds the given char's index by searching from the back
 * @param str Given string that function searches
 * @param searchChar Seacrhed char in given string
 * @return index of char, -1 if cannot find
 * */
int rfind(const string& str, const char searchChar)
{
    int returnIndex = -1, index = str.length() - 1;
    bool searching = true;

    while(searching)
    {
        if(index == -1 || str.at(index) == searchChar)
        {
            returnIndex = index;
            searching = false;
        }

        index--;
    }
    return returnIndex;
}

int legoBlocks(int n, int m)
{
    Queue<string> possibleWalls;
    string wall = "0";
    possibleWalls.enqueue(wall);
    int noDifferenceCount = 0;
    bool carrryOn = true;

    while(carrryOn)
    {
        possibleWalls.dequeue(wall);

        if(wall.length() == 1 || stoi(wall.substr(rfind(wall, ',') + 1), nullptr) != m)
        {
            noDifferenceCount = 0;

            int currLength = stoi(wall.substr(rfind(wall, ',') + 1), nullptr);
            string newWall;

            if(currLength + 1 <= m)
            {
                newWall = wall + "," + to_string(currLength + 1);
                possibleWalls.enqueue(newWall);
            }
            if(currLength + 2 <= m)
            {
                newWall = wall + "," + to_string(currLength + 2);
                possibleWalls.enqueue(newWall);
            }
            if(currLength + 3 <= m)
            {
                newWall = wall + "," + to_string(currLength + 3);
                possibleWalls.enqueue(newWall);
            }
            if(currLength + 4 <= m)
            {
                newWall = wall + "," + to_string(currLength + 4);
                possibleWalls.enqueue(newWall);
            }
        }
        else
        {
            noDifferenceCount++;
            possibleWalls.enqueue(wall);
        }

        if(noDifferenceCount == possibleWalls.qSize()) carrryOn = false;
    }

    return 0;
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
