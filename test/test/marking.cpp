#include <iostream>
using namespace std;
int main(){
	double x;
	cout<<"�㿼�Կ��˶��ٷ�?(0~100)"<<endl;
	cin>>x;
	if(x<60 && x>=0){
		cout<<"��ķ���:��"<<endl;
		getchar();
		getchar ();
	}
	else if(x>=60 && x<80){
		cout<<"��ķ���:��"<<endl;
		getchar();
		getchar ();
	}
	else if(x>=90&& x<=100  ){
		cout<<"��ķ���:��"<<endl;
		getchar();
		getchar ();
	}
	else if(x>=80 && x<90){
		cout<<"��ķ���:��"<<endl;
		getchar();
		getchar ();
	}
	else {
		cout<<"������� "<<endl;
		getchar();
		getchar ();
	}
}
