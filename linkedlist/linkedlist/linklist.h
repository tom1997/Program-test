#ifndef linklist_H
#define linklist_H

template <class DataType>
struct Node
{
      DataType data;
      Node<DataType> *next;  
};

template <class DataType>
class LinkList
{
public:
 LinkList( );                     //�޲ι��캯��������ֻ��ͷ���Ŀ�����
 LinkList(DataType a[ ], int n);      //�вι��캯����������n��Ԫ�صĵ�����
 ~LinkList( );                    //��������
 int Locate(DataType x);           //��ֵ���ҡ��ڵ������в���ֵΪx��Ԫ�����
 void Insert(int i, DataType x);      //�����������i��λ�ò���Ԫ��ֵΪx�Ľ��
 DataType Delete(int i);           //ɾ���������ڵ�������ɾ����i�����
 void PrintList( );                 //������������������������Ԫ��
 int length();
 LinkList(LinkList<DataType> &L);      //���ƹ��캯��
 int Increase();                   //�жϵ������Ƿ����,ʵ����p23
 void Reverse();                  //������������,ʵ����p23,p24
 void Insert(DataType x);        //�������������ο�ʵ����p25�㷨-7
 void Purge();                      //������������ͬ��ֵɾ��,ʵ����p35
 LinkList<DataType>& LinkList<DataType>::operator=(LinkList<DataType> &L);
 template <class DataType>
 friend int IsEqual(LinkList<DataType> &a,LinkList<DataType> &b){
	 Node<DataType> *pa;
	 Node<DataType> *pb;
	 pa=a.first->next;
	 pb=b.first->next;
	 while(pa!=NULL &&pb!=NULL){
		 if(pa->data==pb->data){
			pa=pa->next;
			pb=pb->next;
		}
		else break;
	}
	if(pa==NULL && pb==NULL)
		return 1;
	else return 0;};
 template <class DataType>
 friend void Interception(LinkList<DataType> &a,LinkList<DataType> &b)
	 {
		 Node<DataType> *pre=a.first;
		 Node<DataType> *p=a.first->next;
		 Node<DataType> *q=b.first->next;
		 if(p->data<q->data){
			 pre->next=p->next;
			 delete p;
			 p=pre->next;
		 }
		 else if(p->data>q->data)
			 q=q->next;
		 else{
			 p=p->next;
			 q=q->next;
		 }
		 a.PrintList();
 }
 ;
template <class DataType>
 friend void Union(LinkList<DataType> &a,LinkList<DataType> &b)
	 {
		 Node<DataType> *pre=b.first;
		 Node<DataType> *p=a.first->next;
		 Node<DataType> *q=b.first->next;
		 int i=1;
		 while(p->next!=NULL){
			 q=pre;
			 i++;
			 while(q->next!=NULL){
		//		b.Delete(b.Locate(q->data)); // ���������������
				q=q->next;
			 }
			 p=p->next;
			 cout<<i;
		 }
		 while(q->next!=NULL){
			 a.Insert(i, q->data);
			 q=q->next;
		 }
		 p->next=NULL;

 };
 template <class DataType> 
 friend void Difference(LinkList<DataType> &A, LinkList<DataType> &B);
private:
 Node<DataType> *first;                     //�������ͷָ��
};

#endif

 