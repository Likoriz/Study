#pragma once

#include <iostream>
#include <vector>
#include <stack>

class GraphT
{
private:
    int verticesCount; // ���������� ������
    std::vector<std::vector<int>> adjacencies; // ������ ���������
    std::vector<bool> visited;
    std::stack<int> s;
    void dfs(int vertice);

public:
    GraphT(int verticesCount) : verticesCount(verticesCount), adjacencies(verticesCount), visited(verticesCount, false) {}
    void addEdge(int verticeOut, int verticeIn);
    void topologicalSort();
};