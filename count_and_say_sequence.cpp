//The count - and-say sequence is the sequence of integers beginning as follows : 1, 11, 21, 1211, 111221, ... 1 is read off as "one 1" or 11. 11 is read off as "two 1s" or 21. 21 is read off as "one 2, then one 1" or 1211. Given an integer n, generate the _n_th sequence.Note : The sequence of integers will be represented as a string
#include "iostream"
using namespace std;
string solute(string s);
string num2string(int num);
int main(){
    string ans;
    int n;
    cout << "n:";
    cin >> n;
    cout << endl;
    for (int i = 0; i < n;i++){
        ans = solute(ans);
    }
    cout << ans;
    return 0;
}
string solute(string s){
    if(s.empty())
        return "1";
    string ans;
    int cnt = 1;
    char cur = s[0];
    for (int i = 1; i < s.length();i++){
        if (cur == s[i])
        {
            cnt++;
            continue;
        }
        else {
            string temp;
            temp += num2string(cnt);
            temp.append(1, cur);
            ans += temp;
            cur = s[i];
            cnt = 1;
        }
    }
    string temp;
    temp += num2string(cnt);
    temp.append(1, cur);
    ans += temp;
    return ans;
}
string num2string(int num){
    if(num==0)
        return "0";
    string ans;
    while(num%10){
        ans.append(1, '0' + num % 10);
        num /= 10;
    }
    return ans;
}