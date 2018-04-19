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
 LinkList( );                     //无参构造函数，建立只有头结点的空链表
 LinkList(DataType a[ ], int n);      //有参构造函数，建立有n个元素的单链表
 ~LinkList( );                    //析构函数
 int Locate(DataType x);           //按值查找。在单链表中查找值为x的元素序号
 void Insert(int i, DataType x);      //插入操作，第i个位置插入元素值为x的结点
 DataType Delete(int i);           //删除操作，在单链表中删除第i个结点
 void PrintList( );                 //遍历操作，按序号依次输出各元素
 int length();
 LinkList(LinkList<DataType> &L);      //复制构造函数
 int Increase();                   //判断单链表是否递增,实验书p23
 void Reverse();                  //将单链表逆置,实验书p23,p24
 void Insert(DataType x);        //建立有序单链表，参考实验书p25算法-7
 void Purge();                      //将单链表中相同的值删除,实验书p35
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
		//		b.Delete(b.Locate(q->data)); // 不清楚错误在哪里
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
 Node<DataType> *first;                     //单链表的头指针
};

#endif

 