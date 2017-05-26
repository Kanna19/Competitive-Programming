#include <iostream>
using namespace std;

int x, y, p, q;

inline bool isPossible(int v)
{
	return (1ll *p *v >= x && 1ll *v *(q -p) >= (y -x));
}

int main()
{
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> x >> y >> p >> q;
		
		int l = 0, r = 1000000000;
		
		while(l < r)
		{
			int mid = l +r >> 1;
			
			if(isPossible(mid))
				r = mid;
			
			else 
				l = mid +1;
		}
		
		if(isPossible(l))
			cout << 1ll *q *l -y << endl;
		
		else
			cout << -1 << endl;
	}

	return 0;
}
