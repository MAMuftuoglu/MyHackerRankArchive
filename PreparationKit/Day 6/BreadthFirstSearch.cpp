#include <bits/stdc++.h>

/*
 * Complete the 'bfs' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. 2D_INTEGER_ARRAY edges
 *  4. INTEGER s
 */

std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s)
{
    std::queue<int> nodes;
    nodes.push(s);
    std::vector<int> shortestReachAll(n, 0);
    std::vector<bool> visited(n, false);

    while (!nodes.empty())
    {
        int currNode = nodes.front();
        nodes.pop();

        if (!visited[currNode - 1])
        {
            for (std::vector<int> edge : edges)
            {
                if (edge[0] == currNode && !visited[edge[1] - 1])
                {
                    nodes.push(edge[1]);
                    shortestReachAll[edge[1] - 1] = shortestReachAll[edge[0] - 1] + 6;
                }
                else if (edge[1] == currNode && !visited[edge[0] - 1])
                {
                    nodes.push(edge[0]);
                    shortestReachAll[edge[0] - 1] = shortestReachAll[edge[1] - 1] + 6;
                }
            }
            visited[currNode - 1] = true;
        }
    }

    std::vector<int> shortestReach;
    for (int index = 0; index < shortestReachAll.size(); index++)
    {
        if (index != s - 1)
        {
            int value;
            value = (shortestReachAll[index] != 0) ? shortestReachAll[index] : -1;
            shortestReach.push_back(value);
        }
    }

    return shortestReach;
}

int main()
{

    std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}};

    for(int num : bfs(5, 3, edges, 1)) {
        std::cout << num << std::endl;
    }

    return 0;
}
