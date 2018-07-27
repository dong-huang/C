#include "iostream"
#include "string"
using namespace std;
//aabcc dbbca aadbbcbcac
bool check(string s1, string s2, string s3);
int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    if (check(s1, s2, s3) == true)
    {
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}
bool check(string s1, string s2, string s3){
    int len1 = s1.length(), len2 = s2.length();
    bool ma[len1 + 1][len2 + 1];
    ma[0][0] = true;
    for (int i = 1; i <= len1;i++){
        ma[i][0] = ma[i - 1][0] && s1[i - 1] == s3[i - 1];
    }
    for (int i = 1; i <= len2;i++){
        ma[0][i] = ma[0][i - 1] && s2[i - 1] == s3[i - 1];
    }
    for (int i = 1; i <= len1;i++){
        for (int j = 1; j <= len2;j++){
            ma[i][j] = (ma[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (ma[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return ma[len1][len2];
}