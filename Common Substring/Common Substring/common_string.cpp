#include<iostream>

#include <string>
#include <vector>
using namespace std;
int lcs_len(string s1, string s2){

    int n = s1.size(), n2 = s2.size();
    if (n==0 || n2==0)return 0;
    vector<vector<int>> dp(n+1, vector<int>(n2+1,0));

    for (int i = 1; i <=n; i++){
        for (int j = 1; j <=n2; j++){
            if (s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

    }
    return dp[n][n2];
}

 int main(){
	     string s1, s2;
    while (cin >> s1 >> s2){

        cout << s1 << "  " << s2 << "的最长公共子串长度为" << lcs_len(s1, s2) << endl;
    }

	 system("pause");

 }
