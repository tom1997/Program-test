#include <iostream>
using namespace std;
double FahrenheitandCelsius(double f){
	
	return 5*(f-32)/9;
}
int main(){
	double y;
	cin>>y;
	cout<<" Celsius temperature is "<<FahrenheitandCelsius(y)<<"¡ãC"<<endl;
	return 0;
}

