#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	int dice[4];
	int i, j;
	int a, b;
	int status = 0;
	int total = 0;
	int exist[6] = {0};
	for(i=0; i<cases; i++)
	{
		for(j=0; j<4; j++)
		{
			cin >> dice[j];
			exist[dice[j]-1]++;
		}
		for(a=0; a<6; a++)
		{
			if(exist[a] == 4)
			{
				cout << "WIN" << endl;
				status = 1;
			}
		}
		if(status != 1)
		{
			for(a=0; a<6; a++)
			{
				if(exist[a] == 2)
				{
					for(b=0; b<4; b++)
					{
						total += dice[b];
						//cout << dice[b] << endl;
						//cout << "TOTAL = " << total << endl;
					}
					//cout << "TOTAL = " << total << endl;
					cout << total-((a+1)*2) << endl;
					status = 2;
				}
				if(status == 2)
					break;
			}
		}
		if(status != 1 && status != 2)
		{
			cout << "R" << endl;
		}
		//------------------
		for(a=0; a<6; a++)
			exist[a] = 0;
		status = 0;
		total = 0;
	}
}