#include "iostream"
#include "vector"
using namespace std;
//10 9 2 5 3 7 101 18
void dfs(vector<int> &vec, int begin, vector<int> &ans, int *max, vector<int> &res);
int main()
{
    vector<int> in;
    int g;
    while (cin >> g)
    {
        in.push_back(g);
        if (getchar() == '\n')
            break;
    }
    vector<int> ans, res;
    int max = 0;
    dfs(in, 0, ans, &max, res);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}
void dfs(vector<int> &vec, int begin, vector<int> &ans, int *max, vector<int> &res)
{
    if (begin == vec.size())
        return;
    if (vec.size() - begin - 1 + ans.size() <= *max)
        return;
    for (int i = begin; i < vec.size(); i++)
    {
        if (ans.empty() || *(ans.end() - 1) < vec[i])
        {
            ans.push_back(vec[i]);
            if (ans.size() > *max)
            {
                res = ans;
                *max = ans.size();
            }
            dfs(vec, i + 1, ans, max, res);
            ans.erase(ans.end() - 1);
        }
    }
}