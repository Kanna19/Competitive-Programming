#include <iostream>
using namespace std;

int cnt1, cnt2, x, y;

bool chk(int v)
{
	int factors_x = v/x;
	int factors_y = v/y;
	int factors_xy = v/(x *y);
	
	int a = factors_y -factors_xy, b = factors_x -factors_xy;
	
	int available = v -factors_x -factors_y +factors_xy;
	int req = 0;
	
	if(a < cnt1)
		req = cnt1 -a;
	
	if(b < cnt2)
		req += cnt2 -b;
	
	return (available >= req);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> cnt1 >> cnt2 >> x >> y;
	
	int l = 2, r = (int)2e9;
	
	while(l < r)
	{
		int mid = 1ll *l +r >> 1;
		
		if(chk(mid))
			r = mid;	
	
		else
			l = mid +1;
	}
	
	cout << l << endl;
	return 0;
}
