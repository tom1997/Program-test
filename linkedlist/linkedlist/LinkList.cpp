#include "linklist.h"
template <class DataType>
LinkList<DataType> :: LinkList( )
{
 first = new Node<DataType>;                        //����ͷ���
 first->next = NULL;                      //ͷ����ָ�����ÿ�
}
template <class DataType>  
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
 Node<DataType> *r, *s;
 first = new Node<DataType>;                    //����ͷ���
 r = first;                            //βָ���ʼ��
 for (int i = 0; i < n; i++)
 { 
  s = new Node<DataType>; s->data = a[i];        //Ϊÿ������Ԫ�ؽ���һ�����
  r->next = s; r = s;                 //�����s���뵽�ն˽��֮��
 }
 r->next = NULL;        //����������ϣ����ն˽���ָ�����ÿ�
}
template <class DataType>
LinkList<DataType> :: ~LinkList( )
{
 Node<DataType> *q;
 while (first != NULL)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
 {
  q = first;                 //�ݴ汻�ͷŽ��
  first = first->next;         // firstָ���ͷŽ�����һ�����
  delete q;    
 }
}

template <class DataType>  
void LinkList<DataType> :: Insert(int i, DataType x)
{
 Node<DataType> *p = first, *s;
 int count = 0;               //����ָ��pӦָ��ͷ���
    while (p != NULL && count < i - 1)  //���ҵ�i - 1�����
    {
  p = p->next;                   //����ָ��p����
  count++;
    }
    if (p == NULL) throw "λ��";      //û���ҵ���i - 1�����
    else {
  s = new Node<DataType>;  s->data = x;     //����һ�����s����������Ϊx
  s->next = p->next; p->next = s;   //�����s���뵽���p֮��
    }
}
template <class DataType>  
DataType LinkList<DataType> :: Delete(int i)
{
 Node<DataType> *p, *q;
 DataType x;
 int count = 0; 
 p = first;               //ע�⹤��ָ��pҪָ��ͷ���
 while (p != NULL && count < i - 1)  //���ҵ�i-1�����
 {
  p = p->next;
  count++;
 }
 if (p == NULL || p->next == NULL)  //���p�����ڻ�p�ĺ�̽�㲻����
  throw "λ��"; 
 else {
  q = p->next; x = q->data;         //�ݴ汻ɾ���
  p->next = q->next;              //ժ��
  delete q; 
  return x;
 }
}
template <class DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
 Node<DataType> *p = first->next;
 int count = 1;         //����ָ��p���ۼ���count��ʼ��
 while (p != NULL)    
 {
  if (p->data == x) return count;     //���ҳɹ��������������������
  p = p->next;                   
  count++;
 }
 return 0;                        //�˳�ѭ����������ʧ��
}
template <class DataType>
void LinkList<DataType> :: PrintList( )
{
 Node<DataType> *p = first->next;                 //����ָ��p��ʼ��
 while (p != NULL)
 {
  cout << p->data<<"  ";
  p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
 }
 cout<<endl;
}
template <class DataType>
int LinkList<DataType> :: length()
{
 Node<DataType> *p = first;
 p=first->next;
 int j=0;
 while(p!=NULL){
  p=p->next;
  j++;
 }
 return j;
}
template <class DataType>
LinkList<DataType>& LinkList<DataType>::operator=(LinkList<DataType> &L)    //���ظ�ֵ������ʵ��A=B��ֵ
{   
    Node<DataType> *s,*srcptr=L.first;              //�����Ʊ��ͷ�ڵ�
	Node<DataType>  *destptr=first=new Node<DataType>;

	while (srcptr->next!=NULL){     //����ڵ㸴��
		  s=new Node<DataType>;         //�����½ڵ�
		  s->data=srcptr->next->data;
          destptr->next=s;
		  destptr=destptr->next;
		  srcptr=srcptr->next;
          
	 }
	destptr->next=NULL;
	return L;
}
template <class DataType>
LinkList<DataType>::LinkList(LinkList<DataType> &L){
 Node<DataType> *s; *srcptr-L.first;
 Node<DataType> *destptr=first=new Node <DataType>;
 while (scrptr->next!=NULL){
 s=new Node<DataType>;
 s->data=srcptr->next->data;
 destptr->next=s;
 destptr=destptr->next;
 srcptr=srcptr->next
 }
 srcptr=next->NULL;
}
template <class DataType>
int LinkList<DataType>::Increase(){
	Node<DataType> *p;
	Node<DataType> *q;
	p=first->next;
	while(p->next!=NULL)
	{
		q=p->next;
		if(p->data<q->data)p=q;
		else return 0;
	}
	return 1;
}
template <class DataType>
void LinkList<DataType>::Reverse( ){
	Node<DataType> *p;
	Node<DataType> *pre;
	Node<DataType> *r;
	p=first->next;pre=NULL;
	while(p!=NULL){
		r=p->next;
		p->next=pre;
		pre=p;
		p=r;
	}
	first->next=pre;
	
}


 