#include <bits/stdc++.h>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

void findWalls(vector<string> &wallArr, string &wall, const int m, const int curr)
{
    if (curr == m)
    {
        wallArr.push_back(wall);
    }
    else
    {
        if (curr + 1 <= m)
        {
            string newWall = wall + to_string(curr + 1);
            findWalls(wallArr, newWall, m, curr + 1);

            if (curr + 2 <= m)
            {
                newWall = wall + to_string(curr + 2);
                findWalls(wallArr, newWall, m, curr + 2);

                if (curr + 3 <= m)
                {
                    newWall = wall + to_string(curr + 3);
                    findWalls(wallArr, newWall, m, curr + 3);

                    if (curr + 4 <= m)
                    {
                        newWall = wall + to_string(curr + 4);
                        findWalls(wallArr, newWall, m, curr + 4);
                    }
                }
            }
        }
    }
}

void findHeight(const vector<string> &wallArr, vector<int> &crackNum, int n, int height, int &currNum, string currWall, int currIndex)
{
    if (height == n)
    {
        bool perfect = true;
        for (int index = 0; perfect && index < crackNum.size() - 1; index++)
        {
            if (crackNum[index] == n)
                perfect = false;
        }
        if (perfect)
            currNum++;
    }
    else
    {
        for (int index = 0; index < wallArr.size(); index++)
        {
            string wall = wallArr[index];
            vector<int> newCracks = crackNum;
            for (int indexCrack = 0; indexCrack < wall.length(); indexCrack++)
            {
                newCracks[wall.at(indexCrack) - '0' - 1]++;
            }
            findHeight(wallArr, newCracks, n, height + 1, currNum, wall, index);
        }
    }
}

int legoBlocks(int n, int m)
{
    string wall = "";
    vector<string> wallArr;
    findWalls(wallArr, wall, m, 0);

    int currNum = 0;

    for (int index = 0; index < wallArr.size(); index++)
    {
        vector<int> crackNum(m, 0);
        for(int indexCrack = 0; indexCrack < wallArr[index].length(); indexCrack++)
        {
            crackNum[wallArr[index].at(indexCrack) - '0' - 1]++;
        }
        findHeight(wallArr, crackNum, n, 1, currNum, wallArr[index], index);
    }

    return currNum;
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
