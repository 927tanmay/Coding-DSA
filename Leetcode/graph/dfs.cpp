void solve(vector<int> g[], int x, vector<bool> &vis, vector<int> &res)
{
    vis[x] = true;
    res.push_back(x);

    for (int i = 0; i < g[x].size(); i++)
    {
        if (vis[g[x][i]] == false)
            solve(g, g[x][i], vis, res);
    }

    return;
}

vector<int> dfs(vector<int> g[], int N)
{
    vector<bool> vis(N, false);
    vector<int> res;
    solve(g, 0, vis, res);
    return res;
}