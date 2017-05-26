#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	scanf(" %d", &t);
	
	while(t--)
	{
		int n, k;
		scanf(" %d%d", &n, &k);
		
		vector <int> ans(n +1, -1);
		
		bool flag = 0;
		for(int i = 1; i <= k; i++)
		{
			if(i +k > n)
			{
				flag = 1;
				printf("-1\n");
				break;
			}
			
			ans[i +k] = i;
		}
		
		if(flag)
			continue;
		
		for(int i = k +1; i <= n; i++)
		{
			if(i -k > n)
			{
				flag = 1;
				printf("-1\n");
				break;
			}
			
			if(ans[i -k] == -1)
				ans[i -k] = i;
			
			else
			{
				if(i +k > n)
				{
					flag = 1;
					printf("-1\n");
					break;
				}
				
				if(ans[i +k] == -1)
					ans[i +k] = i;
				
				else
				{
					flag = 1;
					printf("-1\n");
					break;
				}
			}
		}
		
		if(flag)
			continue;
		
		for(int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");		
	}
	
	return 0;
}
