#include<iostream>

using namespace std;
#define MAXSIZE 1000  
typedef struct BtreeNode{  
     char data;  
     struct BtreeNode *lchild;  
     struct BtreeNode *rchild;  
}BtreeNode;  
  
//算术表达式转化二叉树  
/* 
   afa为指向表达式字符串的指针 
   s为要转化的表达式字符串的起始位置 
   e为要转化的表达式字符串的结束位置的后一个 
*/  
BtreeNode* afaToBtree(char *afa,int s,int e){  
    //如果只有一个数那就是叶子结点了  
    if(e-s==1)  
    {  
         BtreeNode* bn=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));  
         bn->data=afa[s];  
         bn->lchild=NULL;  
         bn->rchild=NULL;  
         return bn;  
    }  
    /* 
       local_r记录当前要转化的表达式生成二叉树的根节点操作符的位置 
       flag记录是否当前搜索在括号里面 
       m_m_p记录当前表达式中括号外面最右边的+、-位置 
       a_s_p记录当前表达式中括号外面最右边的*、/位置 
    */  
     int local_r=0,flag=0;   
     int m_m_p=0,a_s_p=0;  
     for(int i=s;i<e;i++)  
     {  
        if(afa[i]=='(')flag++;  
        else if(afa[i]==')')flag--;  
        if(flag==0){  
            if(afa[i]=='*'||afa[i]=='/')  
                m_m_p=i;  
            else if(afa[i]=='+'||afa[i]=='-')  
                a_s_p=i;  
        }  
     }  
     if((m_m_p==0)&&(a_s_p==0))  
         //如果式子整个有括号如(5-2*3+7)，即括号外面没有操作符，则去掉括号找二叉树  
         afaToBtree(afa,s+1,e-1);  
     else   
     {  
        //如果有+或者-，则根节点为最右边的+或-，否则是最右边的*或/  
        if(a_s_p>0)local_r=a_s_p;  
        else if(m_m_p>0)local_r=m_m_p;  
        //确定根节点和根节点的左孩子和右孩子  
        BtreeNode* b=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));;  
        b->data=afa[local_r];  
        b->lchild=afaToBtree(afa,s,local_r);  
        b->rchild=afaToBtree(afa,local_r+1,e);  
        return b;  
     }  
}  
void  PreOrder(BtreeNode *bt)
{
	if(bt==NULL)  return;
	else {		
		cout<<bt->data<<" ";
        PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void  InOrder(BtreeNode *bt)
{
	if (bt==NULL)  return;      //递归调用的结束条件	          
    else {	
        InOrder(bt->lchild);    //中序递归遍历root的左子树
        cout<<bt->data<<" ";    //访问根结点的数据域
        InOrder(bt->rchild);    //中序递归遍历root的右子树
	}
}

void PostOrder(BtreeNode *bt)
{
	if (bt==NULL)  return;       //递归调用的结束条件
    else {	
        PostOrder(bt->lchild);    //后序递归遍历root的左子树
        PostOrder(bt->rchild);    //后序递归遍历root的右子树
        cout<<bt->data<<" ";      //访问根结点的数据域
	}
}


void  LeverOrder( BtreeNode *root)
{
	const int MaxSize=100;
	int front=-1, rear=-1;  //采用顺序队列，并假定不会发生上溢
	
	BtreeNode *Q[MaxSize], *q;
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
  
void main(){  
  
    char input[MAXSIZE];  
    int len=0;  
    //初始化  
    memset(input,'\0',sizeof(input));  
  
    cin >> input ;  
  
    BtreeNode* myBtree=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));  
  
    //myBtree就是input算术表达式产生的二叉树的根节点(指针类型哦)  
  
    myBtree=afaToBtree(input,0,strlen(input));
	cout<<"前序表达："<<endl;
	PreOrder(myBtree);
	cout<<endl;
	cout<<"中序表达："<<endl;
	InOrder(myBtree);
	cout<<endl;
	cout<<"后序表达："<<endl;
	PostOrder(myBtree);
	cout<<endl;
	cout<<"层序表达："<<endl;
	LeverOrder(myBtree);
	
	system("pause");
  
      
}  