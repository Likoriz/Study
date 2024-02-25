#include "Tarjan.h"

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
	adjacencies[verticeOut].push_back(verticeIn);
}

void GraphT::topologicalSort()
{
	for (int i = 0; i < verticesCount; i++)
		if (!visited[i])
			dfs(i);

	cout << "Topological sort: " << endl;
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}