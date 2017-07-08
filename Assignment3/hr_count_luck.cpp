#include <iostream>

const int MAXN = 110;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

using namespace std;

int n, m;
bool vis[MAXN][MAXN];
int luck[MAXN][MAXN];
char forest[MAXN][MAXN];

void dfs(int x, int y)
{
	vis[x][y] = 1;
	
	if(forest[x][y] == '*')
		return;
	
	int cnt = 0;
	for(int i = 0; i < 4; i++)
	{
		int X = x +dx[i], Y = y +dy[i];
		
		if(X < 0 || Y < 0 || X >= n || Y >= m || forest[X][Y] == 'X')
			continue;
		
		cnt++;	
	}
	
	int wt = luck[x][y];
	
	if(forest[x][y] == 'M')
		wt += (cnt > 1);
	
	else
		wt += (cnt > 2);
		
	for(int i = 0; i < 4; i++)
	{
		int X = x +dx[i], Y = y +dy[i];
		
		if(X < 0 || Y < 0 || X >= n || Y >= m || forest[X][Y] == 'X')
			continue;
		
		if(!vis[X][Y] || luck[X][Y] > wt)
		{
			luck[X][Y] = wt;
			dfs(X, Y);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> n >> m;
		
		int start_x, start_y, end_x, end_y;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> forest[i][j];
				
				if(forest[i][j] == 'M')
					start_x = i, start_y = j;
				
				else if(forest[i][j] == '*')
					end_x = i, end_y = j;
				
				vis[i][j] = 0;
			}
		}
		
		int k;
		cin >> k;
		
		luck[start_x][start_y] = 0;
		
		dfs(start_x, start_y);
		
		cout << ((luck[end_x][end_y] == k) ? "Impressed\n" : "Oops!\n");
	}
	
	return 0;
}
