#include<iostream>
using namespace std;
void year(int x){
	if(x%4==0)
		cout<<"闰年";
	else
		cout<<"不是闰年";


}
int main(){
	int n;
	cout<<"Enter a year"<<endl;
	cin>>n;
	year(n);
	getchar();
	getchar();
}
