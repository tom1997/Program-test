#include <iostream>
using namespace std;
int main(){
	unsigned short int i;
	unsigned short int j;
	short int y;
	cout<<"please input the first number"<<endl;
	cin>>i;
	cout<<"please input the second number"<<endl;
	cin>>j;
	if(j==0)
		return -1;
	else 
		y=i/j;
	return y;
}