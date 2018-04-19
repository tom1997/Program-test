#include <iostream>
#include <ctime>//时间随机函数
using namespace std;
int main(){
	srand(time(NULL));//每次运行程序都不一样的随机数，种子为不一样的时间点
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