#include "iostream"
#include "string"
using namespace std;
bool check(string s, int begin, int end);
char pair_(char ch);
int main(){
    string s1;
    cin >> s1;
    bool ok = check(s1, 0, s1.length() - 1);
    if(ok){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}
bool check(string s, int begin, int end){
    if(begin>end)
        return true;
    if(begin==end)
        return false;
    for (int i = begin + 1; i <= end;i++){
        if(s[i]==pair_(s[begin])){
            return check(s, begin + 1, i - 1) && check(s, i + 1, end);
        }
    }
    return false;
}
char pair_(char ch){
    switch(ch){
        case '(':
            return ')';
        case '[':
            return ']';
        case '{':
            return '}';
    }
    return 0;
}