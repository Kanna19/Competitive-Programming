#include <iostream>
#include <stack>

using namespace std;

int main()
{
	while(1)
	{
		int n;
		scanf(" %d", &n);
		
		if(n == 0)
			break;
			
		stack <int> side_road;	
		int curr_min = 1;
		
		for(int i = 0; i < n; i++)
		{
			int curr_truck;
			scanf(" %d", &curr_truck);
		
			if(curr_truck == curr_min)
				curr_min++;
			
			else
			{
				while(!side_road.empty() && side_road.top() == curr_min)
				{
					curr_min++;
					side_road.pop();
				}
		
				side_road.push(curr_truck);
			}
		}
	
		bool flag = 1;
		while(!side_road.empty())
		{
			int next_truck = side_road.top();
			side_road.pop();
		
			if(next_truck == curr_min)
				curr_min++;
		
			else
			{
				printf("no\n");
				flag = 0;
				break;
			}
		}
		
		if(flag)
			printf("yes\n");
	}
	
	return 0;
}
