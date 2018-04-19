#include <iostream>
using namespace std;
int main(){
	int n=0;
	int i=1;
	cout<<"n是1-100之间的质数"<<endl;
	do{
		n++;
		do{
			i++;
			if(n==i){
				cout<<"n="<<n<<endl;
				break;
			}
			else if(n!=i&&n%i==0){
				break;
				
			}
		}
			while(i<n);
			i=1;
	}while(n<9999999999);
	getchar();
	getchar();
	return 0;
}