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
	cout<<"建立树，节点用编号表示，节点编号为0的点为根节点"<<endl<<"输入节点的总数目"<<endl;
	cin>>T.n;
	T.a[i].key=T.a[i].left=T.a[i].right=T.a[i].lw=T.a[i].rw=T.a[i].exisited=0;
	for(int i=1;i<=T.n;i++){
		cout<<"输入第"<<i<<"个节点的左儿子编号，右儿子编号，左衰减量，右衰减量（如果没有则为0）"<<endl;
		T.a[i].lw=i;
		T.a[i].exisited=0;
		cin>>T.a[i].left>>T.a[i].right>>T.a[i].lw>>T.a[i].rw;
		d[T.a[i].left]=T.a[i].lw;
		d[T.a[i].right]=T.a[i].rw;
	}
	cout<<"输入容忍值的大小"<<endl;
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
			cout<<"在第"<<i<<"个节点放置放大器"<<endl;
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
		cout<<"是否继续(y/n)";
		cin>>c;
	}while(c=='y');
	system("pause");
	return 0;
}