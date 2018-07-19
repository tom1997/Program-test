#include <iostream>
using namespace std;
#include "Bitree.h"
void BiTree::init(char data){
	BiNode *bt=new BiNode;
	bt->data=data;
	bt->lchild=NULL;
	bt->rchild=NULL;
	root=bt;
}


BiNode *BiTree::Creat(BiNode *bt,char ch)
{
    if (ch=='#') return NULL;
    else{ 
	     bt = new BiNode;       //����һ�����
         bt->data=ch;
		 bt->lchild = Creat(bt->lchild,'#');    //�ݹ齨��������
		 bt->rchild = Creat(bt->rchild,'#');    //�ݹ齨��������
    } 
    return bt;

}     
void BiTree::Release(BiNode *bt)
{
	if (bt != NULL){                  
	     Release(bt->lchild);   //�ͷ�������
         Release(bt->rchild);   //�ͷ�������
         delete bt;
	}  

}

void BiTree::PreOrder(BiNode *bt)
{
	if(bt==NULL)  return;
	else {		
		cout<<bt->data<<" ";
        PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void BiTree::InOrder(BiNode *bt)
{
	if (bt==NULL)  return;      //�ݹ���õĽ�������	          
    else {	
        InOrder(bt->lchild);    //����ݹ����root��������
        cout<<bt->data<<" ";    //���ʸ�����������
        InOrder(bt->rchild);    //����ݹ����root��������
	}
}

void BiTree::PostOrder(BiNode *bt)
{
	if (bt==NULL)  return;       //�ݹ���õĽ�������
    else {	
        PostOrder(bt->lchild);    //����ݹ����root��������
        PostOrder(bt->rchild);    //����ݹ����root��������
        cout<<bt->data<<" ";      //���ʸ�����������
	}
}


void BiTree::LeverOrder( )
{
	const int MaxSize=100;
	int front=-1, rear=-1;  //����˳����У����ٶ����ᷢ������
	
	BiNode *Q[MaxSize], *q;
	if (root==NULL) return;
	else {
		Q[++rear]=root;
		
		while (front!=rear)
		{
			q=Q[++front];
     		cout<<q->data<<" "; 		
    		if (q->lchild!=NULL) 
				Q[++rear]=q->lchild;		
			if (q->rchild!=NULL) 
				Q[++rear]=q->rchild;
		}
	}
}


