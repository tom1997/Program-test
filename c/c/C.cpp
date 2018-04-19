#include <iostream>
#include <string>
using namespace std;
class message{
public:
	void x(double inmark,string inname,string inmessage){
	name=inname;
	mark=inmark;
    message1=inmessage;};
	void show(){
	cout<<name<<":"<<message1<<endl;}
	double getmark(){return mark;}
	string getname(){return name;}
	string getmessage(){return message1;}
private:
	double mark;
	string name,message1;
};

int main(){
	int N=2;
	double averge=0;
	string name;
	string mark;
	string message0;
	message *ptr=new message[N];
	int t;

	for(;;){
	
	
	for(int i=0;i<N;i++){
		cout<<"Please input your name and message"<<endl;
	cin>>name>>message0;
	ptr[i].x(i,name,message0);
	}
	cout<<endl;
	for(int i=0;i<N;i++){
		ptr[i].show();}
	cout<<endl;
	int *arange=new int [N];
	int *list=new int [N];

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arange[i]==ptr[j].getmark()){
		ptr[j].show();
		break;

		}
			
	}	
	}
	int x;
	cout<<"请输入你想屏蔽的留言号码 "<<endl;
	cin>>x;
	x--;
	cout<<ptr[x].getname()<<" "<<ptr[x].getmessage()<<endl;
	cout<<"以上内容已经被删除"<<endl;
	ptr[x].x(-1," "," ");
	for(int i=0;i<N;i++){
		if(ptr[i].getmark()==-1)
			cout<<x++<<"号留言已经被屏蔽"<<endl;
		
		else	
		cout<<ptr[i].getname()<<" "<<ptr[i].getmessage()<<endl;
	}
	
	delete []ptr;
	
	getchar();
	getchar();
	}

}
