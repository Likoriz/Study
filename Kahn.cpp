#include "Kahn.h"
#include <string>

using namespace std;

void GraphK::addEdge(int verticeOut, int verticeIn)
{
    if (verticeOut < verticesCount && verticeIn < verticesCount)
    {
        adjacencies[verticeOut].push_back(verticeIn);
        inDegree[verticeIn]++;
    }
    else
        throw exception("¬ведены неверные данные!");
}

wstring GraphK::topologicalSort()
{
    wstring string;

    queue<int> queue;
    vector<int> result;

    for (int i = 0; i < verticesCount; i++)
        if (inDegree[i] == 0)
            queue.push(i);

    while (!queue.empty())
    {
        int verticeOut = queue.front();
        queue.pop();
        result.push_back(verticeOut);

        for (int verticeIn : adjacencies[verticeOut])
        {
            inDegree[verticeIn]--;

            if (inDegree[verticeIn] == 0)
                queue.push(verticeIn);

            auto it = find(adjacencies[verticeIn].begin(), adjacencies[verticeIn].end(), verticeOut);
            if (it != adjacencies[verticeIn].end())
                adjacencies[verticeIn].erase(it);
        }
    }

    if (result.size() != verticesCount)
        string = L"√раф содержит цикл!";
    else
        for (int vertice : result)
        {
            string.append(to_wstring(vertice));
            string.append(L" ");
        }

    return string;
}