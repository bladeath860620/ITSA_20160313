#include<iostream>
using namespace std;

int main()
{
	long long int month;
	while(cin >> month) {
		long long adult = 0, y1 = 1, y2 = 0;
		while(month-- > 1){
			adult += y2;
			y2 = y1;
			y1 = adult;
		}
		cout << y2 + y1 + adult << endl;
	}
	return 0;
}
