#include <iostream>
#include <list>
#include <queue>
#include <map>

template <typename T>
class Graph
{

public:
    map<T, list<T>> l;
    void addEdge(int x, int y);

    void bfs(int src);
};

void Graph<int>::addEdge(int x, int y)
{
    this->l[x].push_back(y);
    l[y].push_back(x);
}

void Graph<int>::bfs(int src)
{
    map<T, bool> visited;
    queue<T> q;

    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        T node = q.front();
        q.pop();
        cout << node << " ";

        for (T nbr : l[node])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = true;
            }
        }
    }
}
