#include <iostream>  
using namespace std;  
  
template<class T>  
class CirQueue;  
  
template<class T>  
class Node      //�����  
{  
private:  
    T data;  
    Node<T> *next;  
public:  
    Node()  
    {  
        next=NULL;  
    }  
    Node(T d)  
    {  
        data=d;  
        next=NULL;  
    }  
    friend CirQueue<T>;  
};  
  
template<class T>  
class CirQueue
{  
private:  
    Node<T> *first;  
public:  
    CirQueue()  
    {  
        first=new Node<T>();  
    }  
      
    bool empty() const  
    {  
        return (first->next==0);  
    }  
      
    void push(T d)  //��ջ  
    {  
        Node<T> *p=new Node<T>(d);  
        p->next=first->next;  
        first->next=p;  
    }  
      
    T top() //����ջ��Ԫ��  
    {  
        if(empty())  
        {  
            cout<<"ջΪ��"<<endl;  
			system("pause");
            exit(1);  
        }  
        Node<T> *p=first->next;  
        T temp=p->data;  
        return temp;  
    }  
      
    void pop()  //����ջ��Ԫ��  
    {  
        Node<T> *p=first->next;  
        first->next=p->next;  
        delete p;  
    }  
      
};  
  
void OutPut(int& minH,int& minS,CirQueue<int> H[],int k,int n);  
bool Hold(int c,int& minH,int& minS,CirQueue<int> H[],int k,int n);  
  
bool Rail_Road(int p[],int n,int k)  
{  
    //k������죬�����ʼ����Ϊp[1...n]  
      
    //�����뻺����Ӧ����ջ  
    CirQueue<int> *H;  
    H=new CirQueue<int>[k];  
      
    int NowOut=1; //��һ��Ҫ����ĳ���  
    int minH=n+1; //������б����С�ĳ���  
    int minS=k; //�����С�ĳ������ڻ����ı��  
  
    //����������  
    for(int i=0;i<n;i++)  
    {  
        if(p[i]==NowOut)  
        {  
            cout<<"������ "<<p[i]<<" �������������"<<endl;  
            NowOut++;  
              
            //�ӻ���������  
            while(minH==NowOut)  
            {  
                OutPut(minH,minS,H,k,n);  
                NowOut++;  
                if(NowOut==n+1) //���ȫ������󷵻أ���Ȼ������ڴ�Ƿ�����  
                    return true;  
            }  
        }  
        else  
        {  
            //��p[i]����ĳ�������  
            if(!Hold(p[i],minH,minS,H,k,n))  
                return false;  
        }  
    }  
    return true;  
}  
  
void OutPut(int& minH,int& minS,CirQueue<int> H[],int k,int n)  
{  
    //��һ�ڳ���ӻ�����������촦  
  
    int c;  
  
    c=H[minS].top();  
    H[minS].pop();  
  
    cout<<"������ "<<c<<" �ӻ���� "<<minS+1<<" ���� "<<endl;  
  
    //���������ջ
    minH=n+1;  
      
    for(int i=0;i<k;i++)  
        if( (!H[i].empty()) && (H[i].top()<minH) )  
        {  
            minH=H[i].top();  
            minS=i;  
        }  
}  
  
bool Hold(int c,int& minH,int& minS,CirQueue<int> H[],int k,int n)  
{  
    //�ú����ǽ�����c���뻺�����  
  
    //Ϊ����cѰ�����Ż����  
    int BestTrack=k;//��ʼ��  
    int BestTop=n+1; //���Ż�����ջ��������  
  
    int x;  
  
    //ɨ�軺���  
    for(int i=0;i<k;i++)  
    {  
        if(!H[i].empty())  
        {  
            x=H[i].top();  
            if(c<x && x<BestTop)  
            {  
                BestTop=x;  
                BestTrack=i;  
            }  
        }  
        else  
        {  
            //H[i]Ϊ��ʱ  
            if(BestTrack==k)  
                BestTrack=i;  
        }  
    }  
  
    if(BestTrack==k) //û�п��õĻ����  
        return false;  
  
    H[BestTrack].push(c);  
    cout<<"������ "<<c<<" ������ "<<BestTrack+1<<" �������"<<endl;  
  
    //��Ҫʱ�޸�minH��minS  
    if(c<minH)  
    {  
        minH=c;  
        minS=BestTrack;  
    }  
  
    return true;  
}  