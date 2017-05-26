#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	scanf(" %d", &n);
	
	vector <char> a(n), b(n);
	
	for(int i = 0; i < n; i++)
		scanf(" %c", &a[i]);
	
	for(int i = 0; i < n; i++)
		scanf(" %c", &b[i]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int flicks = 0;
	auto start = b.begin();
	
	for(int i = 0; i < n; i++)
	{
		auto it = lower_bound(start, b.end(), a[i]);
		
		if(it == b.end())
		{
			flicks = n -i;
			break;
		}
		
		start = ++it;	
	}
	
	printf("%d\n", flicks);
	
	flicks = 0;
	start = b.begin();	
	
	for(int i = 0; i < n; i++)
	{
		auto it = upper_bound(start, b.end(), a[i]);
		
		if(it == b.end())
			break;
		
		flicks++;
		start = ++it;
	}
	
	printf("%d\n", flicks);
	return 0;
}
