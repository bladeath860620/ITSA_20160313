#include <iostream>
#include <vector>
using namespace std;

void ranking(vector<int> v,int arr[],int n){
	int count;
	for(int i=0;i<n;i++){
		arr[i]=0;
	}

	for(int i=0;i<n;i++){
		count = 0;
		for(int j=0;j<n;j++){
			if(v[i] < v[j]){
				count ++;
			}
		}
		arr[i] = n-count;
	}

}

int getMax(vector<int> v,int n){
	int max=0;
	for(int i=0;i<n;i++){
		if(v[i] > max){
			max = v[i];
		}
	}
	return max;
}


int main(){
	int n,p,m,i,temp,all,level,max,tax;
	cin >> n;
	while(n){
		n--;

		vector<int> money;
		cin >> p;
		temp = p;
		int rank[p];

		while (temp){
			temp--;
			cin >> m;
			money.push_back(m);
		}

		max = getMax(money,p);

		tax = 0;

		ranking(money,rank,p);

		for(i=0;i<p;i++){
			
			level = 100 - (rank[i]*100/p);

			if(money[i] == max){
				tax += (money[i]*4/10);
			}
			else if(0 <= level && level <= 10){
				tax += (money[i]*4/10);
			}
			else if(11 <= level && level <= 30){
				tax += (money[i]*3/10);
			}
			else if(31 <= level && level <= 60){
				tax += (money[i]*2/10);
			}
			else if(61 <= level && level <= 80){
				tax += (money[i]/10);
			}
		} 

		cout << tax << endl;
	}
}