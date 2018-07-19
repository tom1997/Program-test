#include <iostream>
using namespace std;
#include "Bitree.h"
static int count=0;
static int count1=0;
static BiNode *p=NULL;
void countleaf(BiNode *bt){

	if(bt!=NULL){
		if(bt->lchild==NULL && bt->rchild== NULL){
			count++;
		}
		countleaf(bt->lchild);
		countleaf(bt->rchild);
	}

}
void Count(BiNode *bt){
	if(bt!=NULL){
		Count(bt->lchild);
		count1++;
		Count(bt->rchild);
	}
}
int Depth(BiNode *bt){
	if(bt==NULL) return 0;
	else{
		int hl=Depth(bt->lchild);
		int hr=Depth(bt->lchild);
		return max(hl,hr)+1;
	}
}
BiNode *Parent(BiNode *bt,char x){
		if(bt->data==x) return p;
		else if(bt->lchild!=NULL){
			p=bt;
			Parent(bt->lchild,x);
			
		}
		if(bt->data==x) return p;
		else if(bt->rchild!=NULL){
			Parent(bt->rchild,x);
		}

	}

void main()
{	
	BiTree T; //创建一棵树
	
	cout<<"------前序遍历------ "<<endl;
	T.PreOrder( );
	cout<<endl;
	cout<<"------中序遍历------ "<<endl;
	T.InOrder( );
	cout<<endl;
	cout<<"------后序遍历------ "<<endl;
	T.PostOrder( );
	cout<<endl;
	cout<<"------层序遍历------ "<<endl;
	T.LeverOrder();
	cout<<endl;
	BiNode *a=T.reroot();
	countleaf(a);
	cout<<"叶子数量总共有"<<count<<endl;
	Count(a);
	cout<<"结点总共有"<<count1<<endl;
	cout<<"深度为"<<Depth(a)<<endl;
	char x;
	cout<<"请输入你想查找的结点"<<endl;
	cin>>x;
	Parent(a,x);
	cout<<x<<"的双亲结点为"<<p->data;
	cout<<endl;
	system("pause");
}