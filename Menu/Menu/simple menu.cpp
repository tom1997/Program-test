#include <iostream>
using namespace std;
double fuc(double f){
	
	return ((5/9)(f-32));
}
int main(){
	double y;
	cin>>y;
	cout<<" Celsius temperature is "<<fuc(y)<<"¡ãC"<<endl;
	getchar();
	getchar();
}

