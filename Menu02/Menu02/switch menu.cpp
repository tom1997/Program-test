#include <iostream>
using namespace std;
int main(){
	char a;
	cout<<"Menu:A(dd) D(elete) S(ort) Q(uit)"<<endl;
	cout<<"A=增加，D=删除，S=排序，Q=退出。"<<endl;
	do{
		cin>>a;
	switch (a){
		case 'A':
		cout<<"数据已经增加。"<<endl;
		break;
		case 'D':
		cout<<"数据已经删除。"<<endl;
		break;
		case 'S':
		cout<<"数据已经排序。"<<endl;
		break;
		case 'Q':
		cout<<"程序退出。"<<endl;
		exit(0);
		break;
		default:
			cout<<"输入错误"<<endl;
	}
	}while(a!='Q'||a!='q');
}



