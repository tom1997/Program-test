#include <iostream>;
using namespace std;
#include   <stdlib.h>      
#include   <time.h>   
int getRandom(int i)
{
int *a=new int[i-1];
for(int x=0;x<=i-1;x++){
		a[x]=x;
		}
int k = rand() % i;
return a[k];
}
int main()
{
	int i;
	int max_num = 0;
	int k=1;
	int num;
	double v=0;
	cout<<"请输入苹果个数"<<endl;
	cin>>i;
	cout<<"请输入抽取数量"<<endl;
	cin>>num;
	int *a=new int[i-1];
	int *c=new int[num+1];
	int n=0;
		for(int k=0;k<=num+1;k++){
	c[k]=0;}
	for(int x=0;x<=i-1;x++){
		a[x]=0;
		}
	int e=1;
	for(int j=0;j<=num+1;j++){
		n++;
			int y=getRandom(i)+1;
			for(int x=0;x<=i-1;x++){
					e=e*a[x];
					
				}
		for(int x=-1;x<=i-1;x++){
			if(y==x+1){
				a[x]++;
				if(e==0){
					e=1;
				cout<<"抽中苹果编号为"<<y<<endl;
				for(int x=0;x<=i-1;x++){
					cout<<"a["<<x+1<<"]为"<<a[x]<<endl;}
				c[k]++;
				}
				else if(e!=0){ 
				e=1;
				cout<<"第"<<c[k]<<"次才把所有苹果洗完"<<endl;
				k++;
				for(int x=0;x<=i-1;x++){
					a[x]=0;
				}
				}
		
		}
		}
	}
	for(int k=0;k<=num+1;k++){
	v=v+c[k];
	cout<<"c["<<k<<"]"<<"次数为"<<c[k] <<endl;}
	cout<<"平均次数为"<<v/k <<endl;
	for(int i=0;i<num+1;i++)
{
	if(c[i]>c[max_num])//当前的数比最大值大
		max_num=i;
	}
	cout<<"最大值是:"<<c[max_num]<<" 对应下标:"<<max_num<<endl;
	getchar();
	getchar();
}
