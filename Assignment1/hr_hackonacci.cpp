#include <iostream>
using namespace std;

bool ref[7] = {1, 1, 0, 1, 0, 0, 1};
int ans[4];

int main()
{
	int n, q;
	scanf(" %d%d", &n, &q);
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int curr = (i % 7) *(j % 7);
			curr = (curr *curr) % 7;
			
			int a = n -j +1, b = i;
			int chk = (a % 7) *(b % 7);
			chk = (chk *chk) % 7;
			
			if(ref[chk] != ref[curr])
				ans[1]++;
			
			a = n -i +1, b = n -j +1;
			chk = (a % 7) *(b % 7);
			chk = (chk *chk) % 7;
			
			if(ref[chk] != ref[curr])
				ans[2]++;
		}
	}
	
	ans[3] = ans[2];
	
	while(q--)
	{
		int angle;
		scanf(" %d", &angle);
		printf("%d\n", ans[(angle % 360)/90]);
	}
	
	return 0;
}
