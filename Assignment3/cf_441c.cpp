#include <iostream>
#include <list>

const int MAXN = 310;
const int LEN = 45010;

#define pb push_back
using namespace std;

int n, m;
int color[MAXN][MAXN];
list < pair <int, int> > ans[LEN];

int dx[3] = {0, 0, 1};
int dy[3] = {1, -1, 0};
int start_x = 1, start_y = 1;

void paint(int x, int y, int len, int c)
{
	len--;
	color[x][y] = c;
	ans[c].pb({x, y});
	
	while(len--)
	{
		for(int i = 0; i < 3; i++)
		{
			int X = x +dx[i], Y = y +dy[i];
			
			if(X < 1 || Y < 1 || X > n || Y > m)
				continue;
				
			if(color[X][Y] == 0)
			{
				color[X][Y] = c;
				x = X, y = Y;
				ans[c].pb({x, y});
				break;
			}
		}
	}
	
	for(int i = 0; i < 3; i++)
	{
		int X = x +dx[i], Y = y +dy[i];
		
		if(X < 1 || Y < 1 || X > n || Y > m)
			continue;
			
		if(color[X][Y] == 0)
		{
			start_x = X, start_y = Y;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k;
	cin >> n >> m >> k;
	
	int l = n *m -2 *(k -1);
	paint(start_x, start_y, l, 1);
	
	for(int i = 2; i <= k; i++)
		paint(start_x, start_y, 2, i);
	
	for(int i = 1; i <= k; i++)
	{
		cout << ans[i].size() << ' ';
		
		for(const auto &x: ans[i])
			cout << x.first << ' ' << x.second << ' ';
		
		cout << '\n';
	}
	
	return 0;
}
