#include <iostream>
#include <vector>
#include <cmath>

const int MAXN = 1000000000;
const int TILL = sqrt(MAXN);

using namespace std;

bool isPrime[TILL +1];
vector <int> primes;

void get_primes()
{
	isPrime[1] = 1;
	
	for(int i = 3; i <= TILL; i++)
	{
		if(!isPrime[i])
		{
			primes.push_back(i);
			
			for(long long j = 1ll *i *i; j <= TILL; j += i)
				isPrime[j] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	get_primes();
	
	int len = primes.size();
	
	int t;
	cin >> t;
	
	while(t--)
	{
		int m, n;
		cin >> m >> n;
		
		for(int i = m; i <= n; i++)
		{
			if((i & 1 && i != 1) || i == 2)
			{
				if(i <= TILL && !isPrime[i])
				{
					cout << i << endl;
					continue;
				}
				
				int j = 0;
				for(; j < len; j++)
					if(i % primes[j] == 0)
						break;
				
				if(j == len)
					cout << i << endl;
			}
		}
		
		cout << endl;
	}
	
	return 0;
}
