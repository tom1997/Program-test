#include <iostream>
using namespace std;
typedef int ElemType;
int MaxSize=10;
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LinkList;
void sort(LinkList *&L)
{
    LinkList *p,*pre,*q;
    p=L->next->next;          
    L->next->next=NULL;        
    while(p!=NULL)
    {
        q=p->next;              
        pre=L;      
        while(pre->next!=NULL&&pre->next->data<p->data)    
            pre=pre->next;
        p->next=pre->next;    
        pre->next=p;
        p=q;  
    }
}
int main()
{
	LinkList *A=new LinkList[MaxSize],*p,*r;
    A->next=NULL;
    r=A;
    ElemType a[10]={3,8,2,7,1,5,3,4,6,0};
    for(int i=0;i<10;i++)
    {
        p=new LinkList;
        p->data=a[i];
        r->next=p;
        r=p;
    }
    r->next=NULL;
    cout<<"ÅÅÐòºóÎª£º"<<endl;
    sort(A);
    p=A->next;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
	system("pause");
    return 0;
}