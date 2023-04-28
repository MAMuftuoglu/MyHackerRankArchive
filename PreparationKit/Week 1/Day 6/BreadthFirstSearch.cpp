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

class graph {
private:
    int numVertices;
    std::list<int>* adjacencyLists;
    int* visitedArr;

public:
    graph(std::vector<std::vector<int>>, int);
    ~graph();
    void addEdge(std::vector<int>);
    std::vector<int> BFS(int);
};

graph::graph(std::vector<std::vector<int>> edges, int vertices) {
    adjacencyLists = new std::list<int>[vertices + 1];
    numVertices = vertices;
    visitedArr = nullptr;
    for(std::vector<int> edge : edges)
        addEdge(edge);
}

graph::~graph() {
    delete [] adjacencyLists;
}

void graph::addEdge(std::vector<int> edge) {
    adjacencyLists[edge[0]].push_back(edge[1]);
    adjacencyLists[edge[1]].push_back(edge[0]);
}

std::vector<int> graph::BFS(int s) {
    visitedArr = new int[numVertices + 1];
    for(int i = 0; i <= numVertices; i++)
        visitedArr[i] = -1;
    
    std::queue<int> vertexQ;

    visitedArr[s] = 0;
    vertexQ.push(s);

    std::list<int>::iterator iter;

    while(!vertexQ.empty()) {
        int currVertex = vertexQ.front();
        vertexQ.pop();

        for(iter = adjacencyLists[currVertex].begin(); iter != adjacencyLists[currVertex].end(); iter++) {
            int adjVertex = *iter;
            if(visitedArr[adjVertex] == -1) {
                visitedArr[adjVertex] = visitedArr[currVertex] + 6;
                vertexQ.push(adjVertex);
            }
        }
    }

    std::vector<int> resultArr;

    for(int index = 1; index <= numVertices; index++) {
        if(visitedArr[index] != 0)
            resultArr.push_back(visitedArr[index]);
    }

    delete [] visitedArr;
    visitedArr = nullptr;

    return resultArr;
}

std::vector<int> bfs(int n, int m, std::vector<std::vector<int>> edges, int s)
{
   graph givenGraph(edges, n);
   return givenGraph.BFS(s);
}

int main()
{

    std::vector<std::vector<int>> edges = {{1, 2}, {1, 3}, {3, 4}};

    for(int num : bfs(5, 3, edges, 1)) {
        std::cout << num << std::endl;
    }

    return 0;
}
