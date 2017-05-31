#include <iostream>
#include <algorithm>

#define ll long long

const int MAXN = 100001;
using namespace std;

int a[MAXN];

int get_count(int key, int from, int to)
{
	int l = from, r = to;
	
	while(l < r)		//first occurence
	{
		int mid = l +r >> 1;
		
		if(a[mid] == key && (mid == from || a[mid -1] != key))
		{
			l = mid;
			break;
		}
		
		else if(a[mid] >= key)
			r = mid -1;
		
		else
			l = mid +1;
	}
	
	if(a[l] != key)
		return 0;
	
	int ans = l;
	
	l = from, r = to;
	
	while(l < r)	//last occurence
	{
		int mid = l +r >> 1;
		
		if(a[mid] == key && (mid == to || a[mid +1] != key))
		{
			l = mid;
			break;
		}
		
		else if(a[mid] <= key)
			l = mid +1;
			
		else
			r = mid -1;
	}
	
	ans = l -ans +1;
	
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a, a +n);
	
	ll ans = 0;
	for(int i = 0; i < n; i++)
		ans += get_count(a[i] +k, i +1, n);
	
	cout << ans << endl;
	
	return 0;
}
