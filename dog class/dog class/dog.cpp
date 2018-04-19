#include <iostream>
using namespace std;
 
class Date
{
friend ostream& operator<<(ostream&,const Date&);
  
    int year;
    int month;
    int day;
public:    
    Date() {year=2013; month=9; day=30;}
};
 
ostream& operator<<(ostream& out,const Date& date)
{
    out<<date.year<<'-'<<date.month<<'-'<<date.day;
    return out;
}
 
int main()
{
    Date date;
    cout<<date<<endl;
    system("pause"); 
}