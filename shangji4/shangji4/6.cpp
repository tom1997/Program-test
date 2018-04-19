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
	int N=5;
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
	int *arange=new int [N];
	int *list=new int [N];
	for(int i=0;i<N;i++){
		arange[i]=ptr[i].getmark();
	}

	sort(arange,N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arange[i]==ptr[j].getmark()){
	
		break;
			}
				ptr[N].show();
			
	}	
	}
	delete[]ptr;
	getchar();
	getchar();
	
}
