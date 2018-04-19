#include <iostream>
using namespace std;
int main(){
	double i;
	int x;
	cout<<"Enter a float number."<<endl;
	cin>>i;
	i*=100;
	x=i;
	i-=x;
	if(i>=0.5)
		x=x+1;
	i=x;
	i=i/100;
	cout<<i;
	getchar();
	getchar();
	return 0;
}
	



