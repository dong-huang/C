#include "iostream"
#include "string.h"
#include "vector"
using namespace std;
bool dfs(int x, int y, int num, vector<vector<int>> &vec, vector<vector<int>> &vis);
int main()
{
    int g, num;
    char c;
    vector<vector<int>> in, vis;
    vector<int> tem;
    while (cin >> g)
    {
        tem.push_back(g);
        if ((c = getchar()) == '\n')
        {
            in.push_back(tem);
            tem.clear();
        }
        if (c == '#')
            break;
    }
    cout << "number:";
    cin >> num;
    for (int i = 0; i < in.size(); i++)
    {
        tem.clear();
        for (int j = 0; j < in[0].size(); j++)
        {
            tem.push_back(0);
        }
        vis.push_back(tem);
    }
    if (dfs(0, 0, num, in, vis))
        cout << "true";
    return 0;
}
bool dfs(int x, int y, int num, vector<vector<int>> &vec, vector<vector<int>> &vis)
{
    if (vis[y][x])
        return false;
    if (vec[y][x] == num)
        return true;
    vis[y][x] = 1;
    if (vec[y][x] < num)
    {
        if (x + 1 < vec[0].size())
            if (dfs(x + 1, y, num, vec, vis))
                return true;
        if (y + 1 < vec.size())
            if (dfs(x, y + 1, num, vec, vis))
                return true;
    }
    else
    {
        if (x > 0)
            if (dfs(x - 1, y, num, vec, vis))
                return true;
        if (y > 0)
            if (dfs(x, y - 1, num, vec, vis))
                return true;
    }
    return false;
}
