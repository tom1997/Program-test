#include<iostream>

using namespace std;
#define MAXSIZE 1000  
typedef struct BtreeNode{  
     char data;  
     struct BtreeNode *lchild;  
     struct BtreeNode *rchild;  
}BtreeNode;  
  
//�������ʽת��������  
/* 
   afaΪָ����ʽ�ַ�����ָ�� 
   sΪҪת���ı��ʽ�ַ�������ʼλ�� 
   eΪҪת���ı��ʽ�ַ����Ľ���λ�õĺ�һ�� 
*/  
BtreeNode* afaToBtree(char *afa,int s,int e){  
    //���ֻ��һ�����Ǿ���Ҷ�ӽ����  
    if(e-s==1)  
    {  
         BtreeNode* bn=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));  
         bn->data=afa[s];  
         bn->lchild=NULL;  
         bn->rchild=NULL;  
         return bn;  
    }  
    /* 
       local_r��¼��ǰҪת���ı��ʽ���ɶ������ĸ��ڵ��������λ�� 
       flag��¼�Ƿ�ǰ�������������� 
       m_m_p��¼��ǰ���ʽ�������������ұߵ�+��-λ�� 
       a_s_p��¼��ǰ���ʽ�������������ұߵ�*��/λ�� 
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
         //���ʽ��������������(5-2*3+7)������������û�в���������ȥ�������Ҷ�����  
         afaToBtree(afa,s+1,e-1);  
     else   
     {  
        //�����+����-������ڵ�Ϊ���ұߵ�+��-�����������ұߵ�*��/  
        if(a_s_p>0)local_r=a_s_p;  
        else if(m_m_p>0)local_r=m_m_p;  
        //ȷ�����ڵ�͸��ڵ�����Ӻ��Һ���  
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
	if (bt==NULL)  return;      //�ݹ���õĽ�������	          
    else {	
        InOrder(bt->lchild);    //����ݹ����root��������
        cout<<bt->data<<" ";    //���ʸ�����������
        InOrder(bt->rchild);    //����ݹ����root��������
	}
}

void PostOrder(BtreeNode *bt)
{
	if (bt==NULL)  return;       //�ݹ���õĽ�������
    else {	
        PostOrder(bt->lchild);    //����ݹ����root��������
        PostOrder(bt->rchild);    //����ݹ����root��������
        cout<<bt->data<<" ";      //���ʸ�����������
	}
}


void  LeverOrder( BtreeNode *root)
{
	const int MaxSize=100;
	int front=-1, rear=-1;  //����˳����У����ٶ����ᷢ������
	
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
    //��ʼ��  
    memset(input,'\0',sizeof(input));  
  
    cin >> input ;  
  
    BtreeNode* myBtree=(struct BtreeNode*)malloc(sizeof(struct BtreeNode));  
  
    //myBtree����input�������ʽ�����Ķ������ĸ��ڵ�(ָ������Ŷ)  
  
    myBtree=afaToBtree(input,0,strlen(input));
	cout<<"ǰ���"<<endl;
	PreOrder(myBtree);
	cout<<endl;
	cout<<"�����"<<endl;
	InOrder(myBtree);
	cout<<endl;
	cout<<"�����"<<endl;
	PostOrder(myBtree);
	cout<<endl;
	cout<<"�����"<<endl;
	LeverOrder(myBtree);
	
	system("pause");
  
      
}  