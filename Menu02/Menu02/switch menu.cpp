#include <iostream>
using namespace std;
int main(){
	char a;
	cout<<"Menu:A(dd) D(elete) S(ort) Q(uit)"<<endl;
	cout<<"A=���ӣ�D=ɾ����S=����Q=�˳���"<<endl;
	do{
		cin>>a;
	switch (a){
		case 'A':
		cout<<"�����Ѿ����ӡ�"<<endl;
		break;
		case 'D':
		cout<<"�����Ѿ�ɾ����"<<endl;
		break;
		case 'S':
		cout<<"�����Ѿ�����"<<endl;
		break;
		case 'Q':
		cout<<"�����˳���"<<endl;
		exit(0);
		break;
		default:
			cout<<"�������"<<endl;
	}
	}while(a!='Q'||a!='q');
}



