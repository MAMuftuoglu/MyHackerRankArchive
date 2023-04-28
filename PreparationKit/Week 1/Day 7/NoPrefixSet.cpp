#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

struct node
{
    char data;
    node *left, *right;

    node(char ch) : data(ch)
    {
        left = nullptr;
        right = nullptr;
    }
};

node *createTree(string word)
{
    node *head = new node(word.at(0));
    node *temp = head;
    for (int index = 1; index < word.length(); index++)
    {
        temp->left = new node(word.at(index));
        temp = temp->left;
    }

    return head;
}

bool traverseTree(node *root, string &word)
{
    node *temp = root;
    int index;
    for (index = 1; index < word.size(); index++)
    {
        if (temp->left != nullptr && temp->left->data == word.at(index))
        {
            if (index == word.size() - 1)
                return true;
            else
                temp = temp->left;
        }
        else if (temp->right != nullptr && temp->right->data == word.at(index))
        {
            if (index == word.size() - 1)
                return true;
            else
                temp = temp->right;
        }
        else
        {
            if (temp->left == nullptr)
                temp->left = createTree(word.substr(index));
            else
                temp->right = createTree(word.substr(index));
            break;
        }
    }

    return false;
}

void noPrefix(vector<string> words)
{
    vector<node *> trees;
    trees.push_back(createTree(words[0]));

    for (int index = 1; index < words.size(); index++)
    {
        for (int index2 = 0; index2 < trees.size(); index2++)
        {
            if (trees[index2]->data == words[index].at(0))
            {
                if (traverseTree(trees[index2], words[index]))
                {
                    cout << "BAD SET" << endl
                         << words[index];
                    return;
                }
                break;
            }
            else
            {
                trees.push_back(createTree(words[index]));
                break;
            }
        }
    }
    cout << "GOOD SET";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++)
    {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

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
