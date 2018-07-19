#include <iostream>  
using namespace std;  
  
template<class T>  
class CirQueue;  
  
template<class T>  
class Node      //结点类  
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
      
    void push(T d)  //入栈  
    {  
        Node<T> *p=new Node<T>(d);  
        p->next=first->next;  
        first->next=p;  
    }  
      
    T top() //返回栈顶元素  
    {  
        if(empty())  
        {  
            cout<<"栈为空"<<endl;  
			system("pause");
            exit(1);  
        }  
        Node<T> *p=first->next;  
        T temp=p->data;  
        return temp;  
    }  
      
    void pop()  //弹出栈顶元素  
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
    //k个缓冲轨，车厢初始排序为p[1...n]  
      
    //创建与缓冲轨对应的链栈  
    CirQueue<int> *H;  
    H=new CirQueue<int>[k];  
      
    int NowOut=1; //下一次要出轨的车厢  
    int minH=n+1; //缓冲轨中编号最小的车厢  
    int minS=k; //编号最小的车厢所在缓冲轨的编号  
  
    //车厢重排序  
    for(int i=0;i<n;i++)  
    {  
        if(p[i]==NowOut)  
        {  
            cout<<"将车厢 "<<p[i]<<" 从入轨移至出轨"<<endl;  
            NowOut++;  
              
            //从缓冲轨中输出  
            while(minH==NowOut)  
            {  
                OutPut(minH,minS,H,k,n);  
                NowOut++;  
                if(NowOut==n+1) //输出全部车厢后返回，不然会造成内存非法访问  
                    return true;  
            }  
        }  
        else  
        {  
            //将p[i]放入某个缓冲轨  
            if(!Hold(p[i],minH,minS,H,k,n))  
                return false;  
        }  
    }  
    return true;  
}  
  
void OutPut(int& minH,int& minS,CirQueue<int> H[],int k,int n)  
{  
    //把一节车厢从缓冲轨送至出轨处  
  
    int c;  
  
    c=H[minS].top();  
    H[minS].pop();  
  
    cout<<"将车厢 "<<c<<" 从缓冲轨 "<<minS+1<<" 出轨 "<<endl;  
  
    //检查所有链栈
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
    //该函数是将车厢c放入缓冲轨中  
  
    //为车厢c寻找最优缓冲轨  
    int BestTrack=k;//初始化  
    int BestTop=n+1; //最优缓冲轨的栈顶车厢编号  
  
    int x;  
  
    //扫描缓冲轨  
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
            //H[i]为空时  
            if(BestTrack==k)  
                BestTrack=i;  
        }  
    }  
  
    if(BestTrack==k) //没有可用的缓冲轨  
        return false;  
  
    H[BestTrack].push(c);  
    cout<<"将车厢 "<<c<<" 移至第 "<<BestTrack+1<<" 个缓冲轨"<<endl;  
  
    //必要时修改minH和minS  
    if(c<minH)  
    {  
        minH=c;  
        minS=BestTrack;  
    }  
  
    return true;  
}  