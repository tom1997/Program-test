#include<iostream>
using namespace std;
#include<stdlib.h>
#include<time.h>
const int Max=10;
void Create1(int a[]){
	srand(time(NULL));
	for(int i=1;i<=Max;i++){
		a[i]=1+rand()%Max;
	}
};
void Create2(int a[]){
	srand(time(NULL));
	a[0]=0;
	for(int i=1;i<=Max;i++){
		a[i]=a[i-1]+rand()%Max;
	}
}
int SeqSearch(int r[],int n,int k,int &count){
	int i=n;
	r[0]=k;
	while(++count &&r[i]!=k){
		i--;
	}
	return i;
};
int BinSearch(int r[],int n,int k,int &count){
	int low=1;
	int high=n;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		count++;
		if(k<r[mid])
			high=mid-1;
		else if(k>r[mid])
			low=mid+1;
		else
			return mid;

	}
	return 0;

}
int HashSearch(int ht[],int m,int k,int &j,int &count){
	int i;
	j=k%m;
	count=1;
		if(ht[j]==k)
			return 1;
		else if(ht[j]==0){
			ht[j]=k;
			return 0;
		}
		i=(j+1)%m;
		while(ht[j]!=0 && i!=j){
			count++;
			if(ht[j]==k){
				j=i;
				return 1;
			}
			else
				i=(i+1)%m;
		}
		if(i==j){
			cout<<"溢出";
			return 0;
		}
		else{
			ht[j]=k;
			j=i;
			return 0;
		}
}
int Search(int r[],int n,int k){
	int i=1;
	r[n+1]=k;
	while(r[i]!=k)
		i++;
	return(i%(n+1));
}
int main(){
	int a[Max+1]={0};int ht[Max]={0};
	int temp;
	int i=0;
	int index=0;
	int location=0;
	int count=0;
	int k;
	Create1(a);
	for(int i=1;i<Max;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	k=1+rand()%Max;
	location=SeqSearch(a,Max,k,count);
	cout<<"元素"<<k<<"在序列中的序号是"<<location;
	cout<<"共比较"<<count<<"次"<<endl;
	Create2(a);
	location=0;
	count=0;
	for(int i=1;i<Max;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	location=BinSearch(a,Max,k,count);
	cout<<"元素"<<k<<"在序列中的序号是"<<location;
	cout<<"共比较"<<count<<"次"<<endl;
	count=0;
	for(i=0;i<Max+1;i++)
		HashSearch(ht,Max,a[i],index,count);
	cout<<"散列表中的元素为:"<<endl;
	for(i=0;i<Max;i++){
		cout<<ht[i]<<" ";
	}
	cout<<endl;
	srand(time(NULL));
	temp=a[rand()%9];
	cout<<"查找元素 "<<temp<<endl;
	HashSearch(ht,Max,temp,index,count);
	cout<<"查找成功！元素"<<temp<<"的下标为"<<index;
	cout<<"共比较"<<count<<"次"<<endl;
	for(int i=1;i<Max;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"以下展示顺序查找算法哨兵设在下标的高端,请输入需要查找的数字"<<endl;
	cin>>temp;
	cout<<Search(a,Max-1,temp);
	system("pause");
	return 0;
	
} 