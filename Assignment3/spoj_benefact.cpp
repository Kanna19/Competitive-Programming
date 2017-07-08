#include <iostream>
#include <queue>
#include <vector>

const int MAXN = 50010;
using namespace std;

int n;
int d[MAXN];
int level[MAXN];
vector < pair <int, int> > adj[MAXN];

int bfs(int source)
{
	for(int i = 1; i <= n; i++)
		level[i] = -1;

	level[source] = d[source] = 0;
	
	queue <int> Q;
	Q.push(source);
	
	int farthest_node = source;
	
	int max_level = 0;
	int max_dist = 0;
	
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		
		if(d[u] > max_dist)
		{
			max_dist = d[u];
			farthest_node = u;
		}
		
		int len = adj[u].size();
		for(int i = 0; i < len; i++)
		{
			int v = adj[u][i].first, wt = adj[u][i].second;
			
			if(level[v] == -1)
			{
				level[v] = level[u] +1;
				d[v] = d[u] +wt;
				Q.push(v);
			}
		}
	}

	return farthest_node;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		
		for(int i = 1; i < n; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		
		cout << d[bfs(bfs(1))] << '\n';
	}
	
	return 0;
}
