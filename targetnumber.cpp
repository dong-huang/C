#include "iostream"
#include "vector"
#include "set"
#include "algorithm"
using namespace std;
void make(vector<int> cad, int target, vector<int> res, int begin);
int sum(vector<int> t);
void privec(vector<int> t);
int main(){
    vector<int> cad;
    cout << "candidates:";
    char num_;
    int target=0, num;
    while(true){
        scanf("%d", &num);
        cad.push_back(num);
        num_ = getchar();
        if(num_=='\n')
            break;
    }
    cout << "target:";
    cin >> target;
    sort(cad.begin(), cad.end());
    vector<int> res;
    make(cad, target, res, 0);
    return 0;
}
void make(vector<int> cad, int target, vector<int> res, int begin){
    for (int i = begin; i < cad.size();i++){
        if(i>begin&&cad[i]==cad[i-1])
            continue;
        res.push_back(cad[i]);
        if(sum(res)>target)
            return;
        if(sum(res)==target){
            privec(res);
            cout << endl;
            res.erase(res.end() - 1);
            return;
        }
        make(cad, target, res, i + 1);
        res.erase(res.end() - 1);
    }
    return;
}
int sum(vector<int> t){
    int s = 0;
    for (int i = 0; i < t.size();i++){
        s += t[i];
    }
    return s;
}
void privec(vector<int> t){
    vector<int>::iterator it = t.begin();
    for (; it != t.end();it++){
        cout << *it << ' ';
    }
    return;
}