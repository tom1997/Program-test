#include<iostream>
#define max 20
using namespace std;
static int p=1;
struct node{
	int key;
	int exisited;
	int left,right;
	int lw,rw;
};
struct Tree{
	node a[max];
	int n;
	int tolerancel;
};
int D[max];
int d[max];
void init(){
	int i;
	for(int i=0;i<max;i++){
		D[i]=0;
		d[i]=0;
	}
}
void CreateTree(Tree &T){
	int i=0;
	cout<<"���������ڵ��ñ�ű�ʾ���ڵ���Ϊ0�ĵ�Ϊ���ڵ�"<<endl<<"����ڵ������Ŀ"<<endl;
	cin>>T.n;
	T.a[i].key=T.a[i].left=T.a[i].right=T.a[i].lw=T.a[i].rw=T.a[i].exisited=0;
	for(int i=1;i<=T.n;i++){
		cout<<"�����"<<i<<"���ڵ������ӱ�ţ��Ҷ��ӱ�ţ���˥��������˥���������û����Ϊ0��"<<endl;
		T.a[i].lw=i;
		T.a[i].exisited=0;
		cin>>T.a[i].left>>T.a[i].right>>T.a[i].lw>>T.a[i].rw;
		d[T.a[i].left]=T.a[i].lw;
		d[T.a[i].right]=T.a[i].rw;
	}
	cout<<"��������ֵ�Ĵ�С"<<endl;
	cin>>T.tolerancel;
}
void setamplifier(Tree &T,int k){
	int decr;
	int y;
	y=T.a[k].left;
	if(y){
		decr=D[y]+d[y];
		if(decr>T.tolerancel){
			T.a[y].exisited=1;
		}
		else D[k]=decr;
	}
	y=T.a[k].right;
	if(y){
		decr=D[y]+d[y];
		if(decr>T.tolerancel){
			T.a[y].exisited=1;
		}
		else if(D[k]<decr)
			D[k]=decr;
	}
}
void PostOrder(Tree &T,int k){
	if(p>T.n){
		return;
	}
	setamplifier(T,k);
	p++;
	PostOrder(T,p);
	PostOrder(T,p);	
}
void PrintResult(Tree &T){
	int i;
	for(int i=1;i<=T.n;i++){
		if(T.a[i].exisited){
			cout<<"�ڵ�"<<i<<"���ڵ���÷Ŵ���"<<endl;
		}
	}
}
int main(){
	char c;
	Tree T;
	do{
		init();
		CreateTree(T);
		PostOrder(T,1);
		PrintResult(T);
		cout<<D[2]<<endl;
		cout<<"�Ƿ����(y/n)";
		cin>>c;
	}while(c=='y');
	system("pause");
	return 0;
}