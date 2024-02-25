#pragma once

#include <iostream>
#include <vector>
#include <queue>

class GraphK
{
public:
	GraphK(int vertices) : verticesCount(vertices), adjacencies(vertices), inDegree(vertices, 0) {}
	void addEdge(int verticeOut, int verticeIn);
	void topologicalSort();

private:
	int verticesCount;
	std::vector<std::vector<int>> adjacencies;
	std::vector<int> inDegree;
};