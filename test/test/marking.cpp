#include <iostream>
using namespace std;
int main(){
	double x;
	cout<<"你考试考了多少分?(0~100)"<<endl;
	cin>>x;
	if(x<60 && x>=0){
		cout<<"你的分数:差"<<endl;
		getchar();
		getchar ();
	}
	else if(x>=60 && x<80){
		cout<<"你的分数:中"<<endl;
		getchar();
		getchar ();
	}
	else if(x>=90&& x<=100  ){
		cout<<"你的分数:优"<<endl;
		getchar();
		getchar ();
	}
	else if(x>=80 && x<90){
		cout<<"你的分数:良"<<endl;
		getchar();
		getchar ();
	}
	else {
		cout<<"输入错误。 "<<endl;
		getchar();
		getchar ();
	}
}
