#include <iostream>
#include <vector>
#include <queue>

const int MAXN = 10001;
using namespace std;

int n;
int vertex;
int max_dist;
vector <int> adj[MAXN];

void bfs(int source)
{
	vector <int> dist(n +1, 0);
	
	queue <int> Q;
	Q.push(source);
	
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		
		vertex = u;
		max_dist = dist[u];
		
		int len = adj[u].size();
		for(int i = 0; i < len; i++)
		{
			int v = adj[u][i];
			
			if(dist[v] == 0 && v != source)
			{
				dist[v] = dist[u] +1;
				Q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	
	for(int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bfs(1);
	bfs(vertex);
	cout << max_dist << '\n';
	
	return 0;
}
