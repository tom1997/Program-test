#include "Queue.h"  
  
int main()  
{  
    int p[9]={6,1,3,4,5,7,2,8,9};  
    if(Rail_Road(p,9,10))  
        cout<<"车厢重排序成功"<<endl;  
    else  
        cout<<"车厢重排序失败"<<endl;  
	system("pause");
    return 0;  
}  