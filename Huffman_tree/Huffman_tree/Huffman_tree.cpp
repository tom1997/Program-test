#include <iostream>
#include<string>
#include"Bitree.h"
using namespace std;

int minchar(const char *a,int n, int pre){
	int k=0;
	char c=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>c ){
			c=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]<=c && a[i]>a[pre]){
			c=a[i];
			k=i;
		}
		else if(a[i]<=c && a[i]==a[pre] && i!=pre){
			c=a[i];
			k=i;
		}
		
	}
	return k;

}
/*int pre=0;
pre=minchar(a,n,pre);
pre2=minchar(a,n,pre);*/

struct element{
	int weight;
	int lc,rc,parent;
};
/*void HuffanTree(element huffTree[],int w[],int n){
	for(int i=0;i<2*n-1;i++){
		huffTree[i].parent=-1;
		huffTree[i].lc=-1;
		huffTree[i].rc=-1;
	}
	for(int i=0;i<n;i++){
		huffTree[i].weight=w[i];
	}
	for(int k=n;k<2*n-1;k++){
		Seletej
	}
}*/
BiNode *create(BiNode *x){
	BiNode *p=new BiNode;
	p->data=x->data;
	if(x->lchild!=NULL){
		p->lchild=create(x->lchild);
	}
	else
		p->lchild=NULL;
	if(x->rchild!=NULL){
		p->rchild=create(x->rchild);
	}
	else
		p->rchild=NULL;
	return p;
}

int main(){
	string str="abcdefghijklmnopqrstuvwxyz";
	char *b=(char *)str.data();
	char *a=new char[str.size()+1];
	a[0]='0';
	for (int i=0;i<str.size();i++){
		a[i+1]=b[i];
	}
	cout<<a<<endl;
	BiTree *T=new BiTree[str.size()+1];
	for(int i=0;i<str.size()+1;i++){
		T[i].reroot()->data=a[i];
	}
	for(int i=0;i<str.size()+1;i++){
		T[i].PostOrder();
	}
	cout<<endl;
	int pre1=0;
	int x,y,z;
	for(int i=0;i<str.size();i++){ // 加压
		int pre=0;
		pre=minchar(a,str.size (),pre1);
		BiNode *p=new BiNode; //创造新节点
		BiNode *p2=new BiNode; //可能是垃圾代码
		BiNode *t=T[pre].reroot(); //赋值
		T[pre].reroot()->rchild=create(t);
		pre1=minchar(a,str.size (),pre);
		T[pre].reroot()->lchild=T[pre1].reroot(); // 当两个ascii码加起来的时候会出现负数，未知到怎么解决


		x=T[pre].reroot()->lchild->data;
		y=T[pre].reroot()->rchild->data;
		T[pre].reroot()->data=x+y;
		a[pre]=x+y;
		z=a[pre];
		cout<<z<<" "<<pre<<endl;

	}

	T[1].PostOrder();
	

	system("pause");

	
}