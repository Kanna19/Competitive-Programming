#include <iostream>
#include <vector>

const int MAXN = 110;
using namespace std;

int n;
bool vis[MAXN];
bool adj[MAXN][MAXN];
vector <int> language[MAXN];

void dfs(int u)
{
	vis[u] = 1;
	for(int v = 1; v <= n; v++)
		if(adj[u][v] && !vis[v])
			dfs(v);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m;
	cin >> n >> m;
	
	bool flag = 1;
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		
		if(k != 0)
			flag = 0;
		
		while(k--)
		{
			int l;
			cin >> l;
			
			language[l].push_back(i);
		}
	}
	
	if(flag)
	{
		cout << n << '\n';
		return 0;
	}
	
	for(int i = 1; i <= m; i++)
	{
		int len = language[i].size();
		
		for(int j = 0; j < len; j++)
			for(int k = j +1; k < len; k++)
				adj[language[i][j]][language[i][k]] = adj[language[i][k]][language[i][j]] = 1;	
	}
	
	int components = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
			components++;
		}
	}
	
	cout << components -1 << '\n';
	return 0;
}
