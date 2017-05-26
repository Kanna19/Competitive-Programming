#include <iostream>

const int INF = 0x3f3f3f3f;
const int MAXN = 150001;

using namespace std;

int prefix_sum[MAXN];

int main()
{
	int n, k;
	scanf(" %d%d", &n, &k);
	
	for(int i = 1; i <= n; i++)
	{
		int height;
		scanf(" %d", &height);
		prefix_sum[i] = height +prefix_sum[i -1];
	}
	
	int min_sum = INF;
	int index = -1;
	
	for(int i = 1; i +k -1 <= n; i++)
	{
		int curr_sum = prefix_sum[i +k -1] -prefix_sum[i -1];
	
		if(curr_sum < min_sum)
		{
			min_sum = curr_sum;
			index = i;
		}	
	}
	
	printf("%d\n", index);
	return 0;
}
