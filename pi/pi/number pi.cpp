#include <iostream>
using namespace std;
int main(){
		double pi=4.0;
		double i=1;
		int x=1;
		for(int n=1;n<=5000000;n++){
		
		i=(i+2);
		x*=-1;
		
		pi+=(4.0/(x*i));
		}
	cout<<pi;
	getchar();getchar();
	return 0;
}