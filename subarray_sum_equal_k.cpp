//Given an nonnegative integer array, find a subarray where the sum of numbers is k.Your code should return the index of the first number and the index of the last number.Given [1, 4, 20, 3, 10, 5], sum k = 33, return [2, 4].
#include "iostream"
#include "vector"
using namespace std;
int main(){
    vector<int> nums, sum;
    int inp, sumi = 0, val;
    cout << "nums[]:";
    while(cin>>inp){
        nums.push_back(inp);
        if(getchar()=='\n')
            break;
    }
    cout << endl
         << "sum:";
    cin >> val;
    for (int i = 0; i < nums.size();i++){
        sumi += nums[i];
        sum.push_back(sumi);
    }
    for (int left = 0, right = 0; right < sum.size();){
        int minus = sum[right] - sum[left];
        if(minus<val){
            right++;
            continue;
        }
        if(minus==val){
            cout << '[' << left + 1 << ',' << right << ']';
            left++;
            continue;
        }
        if(minus>val){
            left++;
            continue;
        }
    }
    return 0;
}