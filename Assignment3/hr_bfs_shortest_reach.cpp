#include <iostream>
#include <list>
#include <queue>

#define pb push_back

using namespace std;

void bfs(int source, vector < list <int> > &adj, vector <int> &d)
{
	d[source] = 0;
	
	queue <int> Q;
	Q.push(source);
	
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		
		for(const auto &v : adj[u])
		{
			if(d[v] == -1)
			{
				d[v] = d[u] +6;
				Q.push(v);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--)
	{
		int n, m;
		cin >> n >> m;
		
		vector < list <int> > adj(n +1);
		vector <int> d(n +1, -1);
		
		while(m--)
		{
			int u, v;
			cin >> u >> v;
			
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		int s;
		cin >> s;
		
		bfs(s, adj, d);
		
		for(int i = 1; i <= n; i++)
			if(i != s)
				cout << d[i] << ' ';
				
		cout << '\n';
	}
	
	return 0;
}
