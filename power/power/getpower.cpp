#include <iostream>
using namespace std;
int getpower(int x,int y){
	if(y==1)
		return x;
	else if(y>1)
		return x*(getpower(x,y-1));
	else if(y==0)
		return 1;
	else if(y<0)
		return 0;
}
double getpower(double x,int y){
	if(y==1)
		return x;
	else if(y>1)
		return x*(getpower(x,y-1));
	else if (y<1)
		return 1/(x*(getpower(x,y+1)));
}
int main(){
	int a;
	double b;
	int c;
	cout<<"Input a interger"<<endl;
	cin>>a;
	cout<<"Input a float"<<endl;
	cin>>b;
	cout<<"Input a interger"<<endl;
	cin>>c;
		cout<<a<<"^"<<c<<"="<<getpower(a,c)<<endl;
		cout<<b<<"^"<<c<<"="<<getpower(b,c)<<endl;
	getchar();
	getchar();
}//���ú���ʱ����������������ͱ�Ȼ�Ǻͺ�����ͬ���ú����Ż�ִ�С�
