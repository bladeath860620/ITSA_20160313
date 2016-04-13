#include <iostream>
#include <string>
using namespace std;

bool alpha(char c)
{
	if((c <= 'Z' && c >= 'A')|| (c <= 'z' && c >= 'a'))
		return true;
	else
		return false;
}

bool check(string a, int i, int j)
{
	if(a[i] == a[j] && a[i+1] == a[j+1] && a[i+2] == a[j+2])
		return true;
	else
		return false;
}

int main()
{
	string s;
	getline(cin, s);
	unsigned int temp, temp2, temp3;
	unsigned int i;
	for(i = 0; i < s.length(); i++)
	{
		if(alpha(s[i])&&alpha(s[i+1])&&alpha(s[i+2])&&(i+2)<s.length())
		{
			temp = i+3;
			while(s[temp] == ' ')
			{
				temp++;
			}
			temp2 = temp+3;
			while(s[temp2] == ' ')
			{
				temp2++;
			}
			temp3 = temp2+3;
			while(s[temp3] == ' ')
			{
				temp3++;
			}
			if(check(s,i,temp) && check(s,i,temp2) && check(s,i,temp3))
			{
				i = temp3+2;
				continue;
			}
			else if(check(s,i,temp) && check(s,i,temp2))
			{
				s[i] = 'C';
				s[i+1] = 'P';
				s[i+2] = 'P';
				s[temp] = 'C';
				s[temp+1] = 'P';
				s[temp+2] = 'P';
				s[temp2] = 'C';
				s[temp2+1] = 'P';
				s[temp2+2] = 'P';
				i=temp2+2;
			}
			else if(check(s,i,temp))
			{
				s[i] = 'C';
				s[i+1] = 'P';
				s[i+2] = 'P';
				s[temp] = 'C';
				s[temp+1] = 'P';
				s[temp+2] = 'P';
				i=temp+2;
			}
		}

	}
	cout << s << endl;
	return 0;
}