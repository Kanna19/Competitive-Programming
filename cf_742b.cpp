#include <iostream>

const int MAXN = 100001;
using namespace std;

int cnt[MAXN];

int main()
{
	int n, x;
	scanf(" %d%d", &n, &x);
	
	while(n--)
	{
		int foo;
		scanf(" %d", &foo);
		cnt[foo]++;
	}
	
	long long ans = 0;
	
	for(int i = 1; i < MAXN; i++)
	{
		if(cnt[i])
		{
			int req = i ^ x;
			
			if(req >= MAXN || req < 0)
				continue;
				
			if(req == i)
				ans += 1ll *cnt[i] *(cnt[i] -1);
			
			else
				ans += 1ll *cnt[i] *cnt[req];
		}
	}
	
	ans >>= 1;
	cout << ans << endl;
	
	return 0;
}
