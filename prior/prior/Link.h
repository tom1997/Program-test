
#ifndef LinkList_H
#define LinkList_H

template <class DataType>
struct Node
{
      DataType data;
      Node<DataType> *next;  
   Node<DataType> *prior;
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
private:
 Node<DataType> *first;                     //�������ͷָ��
};

template <class DataType>
LinkList<DataType> :: LinkList( )
{
 first = new Node<DataType>;                        //����ͷ���
 first->next = first;                      //ͷ����ָ�����ÿ�
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
  s->prior=r;
  r->next = s; r = s;                 //�����s���뵽�ն˽��֮��
 }
 first->prior=r;   //�������ڵ�
 r->next = first;        //����������ϣ����ն˽���ָ�����ÿ�


}

template <class DataType>
LinkList<DataType> :: ~LinkList( )
{
 Node<DataType> *q;
 while (first != first)        //�ͷŵ������ÿһ�����Ĵ洢�ռ�
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
 while (p->next!= first && count < i - 1)  //���ҵ�i - 1�����
    {
  p = p->next;                   //����ָ��p����
  count++;
    }
 if (p->next == first) throw "λ��";      //û���ҵ���i - 1�����
    else {
  s = new Node<DataType>;  s->data = x;     //����һ�����s����������Ϊx
  s->prior=p;
  s->next = p->next; p->next->prior = s;   //�����s���뵽���p֮��
  p->next=s;
    }
}

template <class DataType>  
DataType LinkList<DataType> :: Delete(int i)
{
 Node<DataType> *p, *q;
 DataType x;
 int count = 0; 
 p = first;               //ע�⹤��ָ��pҪָ��ͷ���
 while (p ->next!= first && count < i - 1)  //���ҵ�i-1�����
 {
  p = p->next;
  count++;
 }
 if (p->next == first)  //���p�����ڻ�p�ĺ�̽�㲻����
  throw "λ��"; 
 else {
  q = p->next; x = q->data;         //�ݴ汻ɾ���
  q->prior=p;

  p->next = q->next;              //ժ��
  q->next->prior=p;


  delete q; 
  return x;
 }
}

template <class DataType>  
int LinkList<DataType> :: Locate(DataType x) 
{
 Node<DataType> *p = first->next;
 int count = 1;         //����ָ��p���ۼ���count��ʼ��
 while (p != first)    
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
 Node<DataType> *p = first->prior;                 //����ָ��p��ʼ��
/* while (p!= first)
 {
  cout << p->data<<"  ";
  p = p->next;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
 }*/

 while (p!= first)
 {
  cout << p->data<<"  ";
  p = p->prior;                 //����ָ��p���ƣ�ע�ⲻ��д��p++
 }
 cout<<endl;
}
#endif

 