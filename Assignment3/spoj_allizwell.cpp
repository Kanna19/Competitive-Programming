#include <iostream>
 
const int MAXN = 110;
using namespace std;
 
int r, c;
bool vis[MAXN][MAXN];
char grid[MAXN][MAXN];
string target = "ALLIZZWELL";
int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};
 
bool dfs(int x, int y, int index)
{
	if(index == 10)
		return 1;
	
	vis[x][y] = 1;
		
	bool chk = 0;
	for(int i = 0; i < 8; i++)
	{
		int X = x +dx[i], Y = y +dy[i];
		
		if(X < 0 || Y < 0 || X >= r || Y >= c)
			continue;
			
		if(!vis[X][Y] && grid[X][Y] == target[index])
			chk |= dfs(X, Y, index +1);
	}
	
	vis[x][y] = 0;
	return chk;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> r >> c;
		
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				vis[i][j] = 0;
				cin >> grid[i][j];
			}
		}
		
		bool flag = 1;
		for(int i = 0; i < r && flag; i++)
		{
			for(int j = 0; j < c; j++)
			{
				if(grid[i][j] == 'A' && dfs(i, j, 1))
				{
					cout << "YES\n";
					flag = 0;
					break;
				}			
			}
		}
		
		if(flag)
			cout << "NO\n";
	}	
	
	return 0;
} 
