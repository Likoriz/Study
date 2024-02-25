#include "Kahn.h"

using namespace std;

void GraphK::addEdge(int verticeOut, int verticeIn)
{
	adjacencies[verticeOut].push_back(verticeIn);
	inDegree[verticeIn]++;
}

void GraphK::topologicalSort()
{
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
		}
	}

	if (result.size() != verticesCount)
	{
		cout << "There is a cycle in the graph!" << endl;
		return;
	}
	else
	{
		cout << "Topological sort: " << endl;

		for (int vertice : result)
			cout << vertice << " ";
		cout << endl;
	}
}