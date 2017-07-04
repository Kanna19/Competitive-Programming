#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int* to)
{
	int ans[101];
	
	for(int i = 1; i <= 100; i++)
		ans[i] = -1;
		
	ans[1] = 0;
	
	queue <int> Q;
	Q.push(1);
	
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		
		for(int i = 1; i <= 6; i++)
		{
			int v = u +i;
			
			if(v <= 100)
			{
				v = to[v];
				if(ans[v] == -1)
				{
					ans[v] = ans[u] +1;
					Q.push(v);
				}
			}
		}
	}
	
	return ans[100];
}

int main()
{
	int T;
	scanf(" %d", &T);
	
	while(T--)
	{
		int N;
		scanf(" %d", &N);
		
		int to[101];
		
		for(int i = 1; i <= 100; i++)
			to[i] = i;
			
		while(N--)
		{
			int u, v;
			scanf(" %d%d", &u, &v);
			to[u] = v;
		}
		
		int M;
		scanf(" %d", &M);
		
		while(M--)
		{
			int u, v;
			scanf(" %d%d", &u, &v);
			to[u] = v;
		}
		
		int ans = bfs(to);
		printf("%d\n", ans);
	}
	
	return 0;
}
