#include <iostream>
#include <time.h>
#include <stdio.h>  
using namespace std;
template<class T>
void InsertSort(T *arr, int n) { // 排序函数
    int i, j;
    int temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp;j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
	 for (i = 1; i <n; i++){
		 cout<<"a["<<i<<"]="<<arr[i]<<endl;
	 }
}
int main(){
	int n;
	clock_t start ,stop ;  // 时间参数
     double cost;   
	  start=clock();	
	int a[500];
	 for (int i = 0; i < 500; i++) {
       a[i]=rand()%10000;
	    cout<<"a["<<i<<"]="<<a[i]<<endl;
    }
	InsertSort(a,500);
	 stop=clock();	
	  cost=(double)(stop-start)/CLOCKS_PER_SEC;
	 cout << "对于" << 500 << "个情况，耗时" << cost <<"s"<< endl;
	  system( "PAUSE "); 
	return 0;

}