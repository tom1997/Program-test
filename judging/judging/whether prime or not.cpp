#include <iostream>
using namespace std;
void judgingprimenumber(int x){
	int i=1;
	do{
		
		i++;
		if(x%i==0&&x!=i){
			cout<<x<<" is not a prime."<<endl;
			cout<<i<<" is its smallest factor.";
		break;
		}
		else if(x==i){
			cout<<x<<" is a prime.";
		break;
		}
		
	}while(i<x);
}
int main(){
	int a;
	cout<<"Please input a positive number that I can judge it whether prime or not."<<endl;
	cin>>a;
	judgingprimenumber(a);
	getchar();
	getchar();
	return 0;
}
