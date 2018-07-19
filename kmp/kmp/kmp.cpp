#include<iostream>
#include <string>
using namespace std;
/*int kmp(string s,string t){
	while(){
	}
}*/
void get_next(string pattern, int next[]) {


     int i = 0;  // i������¼��ǰ�����next����Ԫ�ص��±꣬ ͬʱҲ��Ϊģʽ������ƥ�䵽��λ�õ��±�
     int j = 0;//�������i��λ��ģʽ���޷�ƥ��ɹ�������һ��λ�ÿ�ʼƥ��
     next[0] = -1; //  next[0]�̶�Ϊ-1
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
    cout << "next����: \t";
    for    (int i = 0; i<pattern.length(); i++)
        cout << next[i] << " ";
    cout << endl;
    int pos = search(source, pattern, next);
    if (-1 != pos) {
        cout << "ƥ��ɹ���ģʽ�����������״γ��ֵ�λ����: ��" << pos + 1 << "λ";
        getchar();
        return 0;
    } else {
        cout << "ƥ��ʧ��";
    }
    getchar();
    return 0;
}