#include <iostream>
#include <ctime>//ʱ���������
using namespace std;
int main(){
	srand(time(NULL));//ÿ�����г��򶼲�һ���������������Ϊ��һ����ʱ���
	int ran_num;
	ran_num=rand()%100;
	int a;
	cout<<"Please input the number until you get the expected number."<<endl;
	do{
		cin>>a;
		if(a!=ran_num){
			if(a>ran_num){
				cout<<"Your input no. is larger than the expected value."<<endl;
				int a=0;}
			else if(a<ran_num)
				cout<<"Your input no. is smaller than the expected value."<<endl;
			int a=0;
			continue;

		}
	}while(a!=ran_num);
	getchar();
	cout<<"You get it!"<<endl;
	getchar();
	
}