#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

const int ALPHABET_SIZE = 10; // A to J inclusive

struct node
{
    node **children;
    bool isEndOfWord;

    node()
    {
        isEndOfWord = false;
        children = new node*[ALPHABET_SIZE];
        for (int index = 0; index < ALPHABET_SIZE; index++)
            children[index] = nullptr;
    }
};

class tree
{
private:
    node *root;
    void clean(node *);

public:
    tree()
    {
        root = new node;
    }
    ~tree()
    {
        clean(root);
    }
    void insert(const string &);
    bool isPrefixExist(const string &) const;
};

void tree::clean(node *root)
{
    for (int index = 0; index < ALPHABET_SIZE; index++)
    {
        if (root->children[index] != nullptr)
            clean(root->children[index]);
    }

    delete[] root->children;
}

bool tree::isPrefixExist(const string &word) const
{
    node *temp = this->root;

    for (int i = 0; i < word.length() && temp != nullptr; i++)
    {
        int index = word.at(i) - 'a';
        if (temp->children[index] != nullptr && temp->children[index]->isEndOfWord)
        {
            cout << "BAD SET" << endl
                 << word << endl;
            return true;
        }

        temp = temp->children[index];
    }

    if (temp == nullptr)
        return false;
    else
    {
        cout << "BAD SET" << endl
             << word << endl;
        return true;
    }
}

void tree::insert(const string &word)
{
    node *temp = root;

    for (int i = 0; i < word.length(); i++)
    {
        int index = word.at(i) - 'a';

        if (temp->children[index] == nullptr)
        {
            temp->children[index] = new node;
            if (i == word.length() - 1)
                temp->children[index]->isEndOfWord = true;
        }
        temp = temp->children[index];
    }
}

void noPrefix(vector<string> words)
{
    tree wordTree;

    for (string word : words)
    {
        if (wordTree.isPrefixExist(word))
            return;
        else
            wordTree.insert(word);
    }
}

int main()
{
    string fileName = "input.txt";
    ifstream inputFile(fileName.c_str());



    string n_temp;
    getline(inputFile, n_temp);

    int n = stoi(n_temp);

    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        string words_item;
        getline(inputFile, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    inputFile.close();

    return 0;
}