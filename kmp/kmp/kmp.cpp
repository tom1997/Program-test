#include<iostream>
#include <string>
using namespace std;
/*int kmp(string s,string t){
	while(){
	}
}*/
void get_next(string pattern, int next[]) {


     int i = 0;  // i用来记录当前计算的next数组元素的下标， 同时也作为模式串本身被匹配到的位置的下标
     int j = 0;//代表从在i的位置模式串无法匹配成功，从下一个位置开始匹配
     next[0] = -1; //  next[0]固定为-1
     int p_len = pattern.length();
     while (++i < p_len) {
         if (pattern[i] == pattern[j]) {

             next[i] = j++;

             while (next[i] != -1 && pattern[i] == pattern[next[i]]) {
                 next[i] = next[next[i]];
             }
         } else {
             next[i] = j;
             j = 0;
             if (pattern[i] == pattern[j]) {
                 j++;
             }
         }
}
}
int search(string source, string pattern, int next[]){
    int i = 0;
    int j = 0;
    int p_len = pattern.length();
    int s_len = source.length();
    while (j < p_len && i < s_len) {
        if (j == -1 || source[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = next[j];            
        }
    }
    if (j < pattern.length())
        return -1;
    else
        return i - pattern.length();
}
int main() {
    string source = "ABCDABCEAAAABASABCDABCADABCDABCEAABCDABCEAAABASABCDABCAABLAKABCDABABCDABCEAAADSFDABCADABCDABCEAAABCDABCEAAABASABCDABCADABCDABCEAAABLAKABLAKK";
    string pattern = "ABCDABCEAAABASABCDABCADABCDABCEAAABLAK";
    int *next=new int[pattern.length()];
	 for(int i = 0; i<pattern.length(); i++)
        next[i]=NULL;
    get_next(pattern, next);
    cout << "next数组: \t";
    for    (int i = 0; i<pattern.length(); i++)
        cout << next[i] << " ";
    cout << endl;
    int pos = search(source, pattern, next);
    if (-1 != pos) {
        cout << "匹配成功，模式串在主串中首次出现的位置是: 第" << pos + 1 << "位";
        getchar();
        return 0;
    } else {
        cout << "匹配失败";
    }
    getchar();
    return 0;
}