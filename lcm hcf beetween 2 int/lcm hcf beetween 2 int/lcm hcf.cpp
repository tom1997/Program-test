#include <iostream>
using namespace std;
void LCM(int a,int b){
	int c;
	if(a>=b)
		c=a;
	else
		c=b;
	do{
		c++;
		if(c%a==0&&c%b==0){

			cout<<"LCM="<<c<<endl;
			break;
		}
	}while(c<(a*b));
}
void HCF(int a,int b){
	int d;
	if(a<=b)
		 d=a;
	else
		 d=b;
	do{
		if(a%d==0&&b%d==0){
			cout<<"HCF="<<d<<endl;
			break;
		}
		d--;
		
	}while(d>=1);

}
int main(){
	int a;
	int b;
	cout<<"please enter two postive integer"<<endl;
	cin>>a>>b;
	LCM(a,b);
	HCF(a,b);
	getchar();
		getchar();
		return 0;
}
