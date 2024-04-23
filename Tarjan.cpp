#include "Tarjan.h"
#include <string>

using namespace std;

void GraphT::dfs(int vertice)
{
	visited[vertice] = true;

	for (int u : adjacencies[vertice])
		if (!visited[u])
			dfs(u);

	s.push(vertice);
}

void GraphT::addEdge(int verticeOut, int verticeIn)
{
	if (verticeOut < verticesCount && verticeIn < verticesCount)
		adjacencies[verticeOut].push_back(verticeIn);
	else
		throw exception("¬ведены неверные данные!");
}

wstring GraphT::topologicalSort()
{
	wstring string;

	for (int i = 0; i < verticesCount; i++)
		if (!visited[i])
			dfs(i);

	while (!s.empty())
	{
		string.append(to_wstring(s.top()));
		string.append(L" ");
		s.pop();
	}

	return string;
}