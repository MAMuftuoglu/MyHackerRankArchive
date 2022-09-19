#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node
{
    Node *next;
    Node *prev;
    int value;
    int key;
    Node(Node *p, Node *n, int k, int val) : prev(p), next(n), key(k), value(val){};
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val){};
};

class Cache
{

protected:
    map<int, Node *> mp;            // map the key to the node in the linked list
    int cp;                         // capacity
    Node *tail;                     // double linked list tail pointer
    Node *head;                     // double linked list head pointer
    virtual void set(int, int) = 0; // set function
    virtual int get(int) = 0;       // get function
};

class LRUCache : public Cache
{
public:
    LRUCache(int cap)
    {
        this->cp = cap;
        this->head = nullptr;
        this->tail = nullptr;
    }

    virtual void set(int givenKey, int givenVal) override
    {
        if (mp.size() == 0)
        {
            head = new Node(givenKey, givenVal);
            tail = head;
            mp.insert({givenKey, head});
        }
        else if (mp.find(givenKey) == mp.end())
        {
            head->prev = new Node(givenKey, givenVal);
            head->prev->next = head;
            head = head->prev;
            mp.insert({givenKey, head});

            if (mp.size() == cp)
            {
                mp.erase(tail->key);
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
        }
        else
        {
            auto iter = mp.find(givenKey);
            iter->second->value = givenVal;
        }
    }

    virtual int get(int key) override
    {
        if (mp.find(key) != mp.end())
        {
            auto iter = mp.find(key);

            auto *ptr = iter->second;
            auto *ptrNext = ptr->next;
            auto *ptrPrev = ptr->prev;

            if (ptrPrev != nullptr)
            {
                head->prev = ptr;
                ptrPrev->next = ptrNext;
                if (ptrNext != nullptr)
                    ptrNext->prev = ptrPrev;
                ptr->next = head;
                ptr->prev = nullptr;
                head = ptr;
            }

            return head->value;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    int n, capacity, i;
    cin >> n >> capacity;
    LRUCache l(capacity);
    for (i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "get")
        {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set")
        {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}
