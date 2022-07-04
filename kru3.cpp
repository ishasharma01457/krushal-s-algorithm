#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
typedef pair<int, int> xPair;
struct Graph
{
	int V, K;
	vector< pair<int, xPair> > edges;
	Graph(int V, int K)
	{
		this->V = V;
		this->K = K;
	}
	void Edge(int u, int v, int w)
	{
		edges.push_back({w, {u, v}});
	}
	int kruskal();
};
struct Disjoint
{
	int *parent, *rnk;
	int n;
	Disjoint(int n)
	{
		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;
			parent[i] = i;
		}
	}
	int find(int u)
	{
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	void merge(int x, int y)
	{
		x = find(x), y = find(y);
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};
int Graph::kruskal()
{
	int krushal_wt = 0;
	sort(edges.begin(), edges.end());
	Disjoint ds(V);
	vector< pair<int, xPair> >::iterator it;
	for (it=edges.begin(); it!=edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);
		if (set_u != set_v)
		{
			cout << u << " - " << v << endl;
			krushal_wt += it->first;
			ds.merge(set_u, set_v);
		}
	}

	return krushal_wt;
}
int main()
{
	int V = 9, E = 14;
	Graph g(V, E);
	g.Edge(0, 1, 3);
	g.Edge(0, 7, 8);
	g.Edge(1, 2, 8);
	g.Edge(1, 7, 1);
	g.Edge(2, 1, 7);
	g.Edge(2, 9, 2);
	g.Edge(2, 5, 4);
	cout << "points of graph are \n";
	int krushal_wt = g.kruskal();

	cout << "\nWeight of graph is " << krushal_wt;

	return 0;
}
