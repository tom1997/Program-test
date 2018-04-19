#ifndef LinkList_n_H
#define LinkList_n_H

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
private:
	Node<DataType> *first;                     //单链表的头指针
};

template <class DataType>
LinkList<DataType> :: LinkList( )
{
	first = new Node<DataType>;                        //生成头结点
	first->next = first;                      //头结点的指针域置空
}

template <class DataType>  
LinkList<DataType> :: LinkList(DataType a[ ], int n)
{
	Node<DataType> *r, *s;
	first = new Node<DataType>;                    //生成头结点
	r = first;                            //尾指针初始化
	first->data=a[0];
	for (int i = 1; i < n; i++)
	{ 
		s = new Node<DataType>; s->data = a[i];        //为每个数组元素建立一个结点
		r->next = s; r = s;                 //将结点s插入到终端结点之后
	}
	r->next = first;        //单链表建立完毕，将终端结点的指针域置空
}

template <class DataType>
LinkList<DataType> :: ~LinkList( )
{
	Node<DataType> *q;
	while (first != first)        //释放单链表的每一个结点的存储空间
	{
		q = first;                 //暂存被释放结点
		first = first->next;         // first指向被释放结点的下一个结点
		delete q;    
	}
}

template <class DataType>  
void LinkList<DataType> :: Insert(int i, DataType x)
{
	if(i<=0) throw "太前";
	Node<DataType> *p = first, *s;
	int count = 1;               //工作指针p应指向头结点
	if(i==1){
		s=first;
		p=first;
			while(p->next!=first){
					p=p->next;		
		}
		first = new Node<DataType>;  first->data = x;     //申请一个结点s，其数据域为x
		first->next=s;   //将结点s插入到结点p之后
		p->next=first;

	}
	else {
    while (p->next!=first&&count < i-1)  //查找第i - 1个结点
    {
		p = p->next;                   //工作指针p后移
		count++;
    }
	s = new Node<DataType>;  s->data = x;     //申请一个结点s，其数据域为x
		s->next = p->next; p->next = s;   //将结点s插入到结点p之后
}

}
template <class DataType>  
DataType LinkList<DataType> :: Delete(int i)
{
	if(i<=0) throw "太前";

	Node<DataType> *p, *q;
	DataType x;
	int count = 0; 
	p = first;
	q=p;
	if(i==1){
		while(p->next!=first){
					p=p->next;		
		}
		first=first->next;
		q->next=first;
		x=q->data;
		p->next=first;
		delete q; 
		return x;
		
	}
			

	else{
	p = first;               //注意工作指针p要指向头结点
	
	while (p->next!= first && count < i - 2)  //查找第i-1个结点
	{
		p = p->next;
		count++;
	}
	if (p->next == first)  //结点p不存在或p的后继结点不存在
		throw "位置"; 
	else {
		q = p->next; x = q->data;         //暂存被删结点
		p->next = q->next;              //摘链
		delete q; 
		
		return x;
	}
}
}

template <class DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
	Node<DataType> *p = first;
	int count = 2;         //工作指针p和累加器count初始化
	if (p->data == x) return count;
	p = p->next;  
	while (p != first)    
	{
		if (p->data == x) return count;     //查找成功，结束函数并返回序号
		p = p->next;                   
		count++;
	}
	return 0;                        //退出循环表明查找失败
}

template <class DataType>
void LinkList<DataType> :: PrintList()
{
	Node<DataType> *p = first;                 //工作指针p初始化
	cout << p->data<<"  ";
	p = p->next; 
	while (p != first)
	{
		cout << p->data<<"  ";
		p = p->next;                 //工作指针p后移，注意不能写作p++
	}
	cout<<endl;
}

#endif