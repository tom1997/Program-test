#include <iostream>
using namespace std;
class Clock{
public:
	Clock();
	void setTime(int newH=0,int newM=0,int newS=0);
 void showTime();
  ~Clock(){}
private:
	int hour ;
	int minute ;
	int second ;
};

void Clock::setTime(int newH,int newM,int newS){
	hour=newH;
	minute=newM;
	second=newS;
}
inline void Clock::showTime(){
	cout<<hour<<":"<<minute<<":"<<second<<endl;
}

int main(){
	Clock myClock;
	cout<<"First time set and output:"<<endl;
	myClock.setTime();
	myClock.showTime();
	cout<<"Secound time set and output:"<<endl;
	myClock.setTime(8,30,30);
	myClock.showTime();

	getchar();
}
