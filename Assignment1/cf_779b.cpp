#include <iostream>
using namespace std;

int main()
{
	int n, k;
	scanf(" %d%d", &n, &k);
	
	if(n == 0)
	{
		printf("0\n");
		return 0;
	}
	
	int temp = n;
	int curr = 0, digits = 0;
	
	while(temp != 0)
	{
		if(temp % 10 == 0)
			curr++;
			
		temp /= 10;
		digits++;
	}
	
	if(curr < k)
	{
		printf("%d\n", digits -1);
		return 0;
	}
	
	temp = n;
	
	int ans = 0;
	while(k)
	{
		if(temp % 10 != 0)
			ans++;
		
		else
			k--;
		
		temp /= 10;	
	}
	
	printf("%d\n", ans);	
	return 0;
}
