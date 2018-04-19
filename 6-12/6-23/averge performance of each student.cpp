#include <iostream>
#include <string>
using namespace std;
class student{
public:
	void x(double inmark,string inname){
	name=inname;
	mark=inmark;};
	void show(){
	cout<<name<<":"<<mark<<endl;}
	double getmark(){return mark;}
	string getname(){return name;}
private:
	double mark;
	string name;

};
void sort(int *src, int len)
{
	int tem;
    for (int i = 0; i < len; i++)
    {
        for(int j = 0; j < len - i - 1; j++) 
            if(src[j] > src[j+1]) 
            {
				tem = src[j];
                src[j] = src[j+1];
                src[j+1] = tem;
            }
    }
}
int main(){
	int N;
	cout<<"Please input the number of students."<<endl;
	cin>>N;
	double averge=0;
	string name;
	double mark;
	student *ptr=new student[N];
	for(int i=0;i<N;i++){
		cout<<"Please input the student's name and mark."<<endl;
	cin>>name>>mark;
	ptr[i].x(mark,name);
	}
	cout<<endl;
	for(int i=0;i<N;i++){
		ptr[i].show();}
	cout<<endl;
	for(int i=0;i<N;i++){
		averge+=ptr[i].getmark();}
	cout<<"Averge of these "<<N<<" students's mark is "<<averge/N<<endl;
	int *arange=new int [N];
	int *list=new int [N];
	for(int i=0;i<N;i++){
		arange[i]=ptr[i].getmark();
	}

	sort(arange,N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arange[i]==ptr[j].getmark()){
		ptr[j].show();
		break;

		}
			
	}	
	}
	int x;
	cout<<"请输入你想查询的学生号码 "<<endl;
	cin>>x;
	x--;
	cout<<ptr[x].getname()<<" "<<ptr[x].getmark()<<endl;
	ptr[x].x(0,"没有用户");
	for(int i=0;i<N;i++){
		if(ptr[i].getmark()==0)
			cout<<x++<<"号学生的资料已经被删除"<<endl;
		
		else
		cout<<ptr[i].getname()<<" "<<ptr[i].getmark()<<endl;
	}
	
	delete []ptr;
	
	getchar();
	getchar();
	
}
