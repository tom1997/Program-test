#include <iostream>;
#include <vector>
#include <algorithm>
using namespace std;
#include   <stdlib.h>      
#include   <time.h>   
 void randperm(int Num)
  {
     vector<int> temp;
     for (int i = 0; i < Num; ++i)
    {
        temp.push_back(i + 1);
     }

    random_shuffle(temp.begin(), temp.end());

   for (int i = 0; i < temp.size(); i++)
     {
       cout << temp[i] << " ";
     }
 }
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
	int k=1;
	double v=0;
	cout<<"请输入苹果个数"<<endl;
	cin>>i;
	int *a=new int[i-1];
	int *c=new int[200];
	int n=0;
		for(int k=0;k<=200;k++){
	c[k]=0;}
	for(int x=0;x<=i-1;x++){
		a[x]=0;
		}
	int e=1;
	for(int j=0;j<=200;j++){
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
	for(int k=0;k<=100;k++){
	v=v+c[k];}
	cout<<"平均次数为"<<v/k <<endl;
	getchar();
	getchar();
}
