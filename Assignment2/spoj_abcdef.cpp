#include <iostream>
#include <unordered_map>

#define ll long long

const int MAXN = 100;
using namespace std;

int a[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	unordered_map <int, int> lhs;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				lhs[a[i] *a[j] +a[k]]++;
	
	ll ans = 0;
	
	for(int i = 0; i < n; i++)
		if(a[i] != 0)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					ans += lhs[a[i] *(a[j] +a[k])];
	
	cout << ans << endl;
	return 0;
}
