#include <iostream>
#include <vector>

const int MAXN = 10001;
using namespace std;

int a[MAXN];
int b[MAXN];
int sum1[MAXN];
int sum2[MAXN];
int l1, l2;

int isPresent(int key)
{
	int l = 1, r = l2;
	
	while(l < r)
	{
		int mid = l +r >> 1;
		
		if(b[mid] == key)
			return mid;
		
		else if(b[mid] > key)
			r = mid -1;
		
		else
			l = mid +1;
	}
	
	if(b[l] != key)
		return -1;
	
	return l;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	while(1)
	{
		cin >> l1;
		
		if(l1 == 0)
			break;
		
		for(int i = 1; i <= l1; i++)
		{
			cin >> a[i];
			sum1[i] = sum1[i -1] +a[i];
		}
			
		cin >> l2;
		for(int i = 1; i <= l2; i++)
		{
			cin >> b[i];
			sum2[i] = sum2[i -1] +b[i];
		}
		
		vector < pair<int, int> > seq;	
		seq.push_back({0, 0});
		
		for(int i = 1; i <= l1; i++)
		{
			int index = isPresent(a[i]);
			
			if(index == -1)
				continue;
				
			seq.push_back({i, index});
		}
		
		seq.push_back({l1, l2});
		
		int len = seq.size();
		
		int ans = 0;
		for(int i = 1; i < len; i++)
		{
			int prev_x = seq[i -1].first, prev_y = seq[i -1].second;
			int curr_x = seq[i].first, curr_y = seq[i].second;
			
			ans += max(sum1[curr_x] -sum1[prev_x], sum2[curr_y] -sum2[prev_y]);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
