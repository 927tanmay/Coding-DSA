vector<int> bfs(vector<int> g[], int N)
{

    int vis[N] = {0};
    queue<int> q;
    vector<int> res;
    q.push(0);
    vis[0] = true;
    while (!q.empty())
    {

        int x = q.front();
        q.pop();
        res.push_back(x);
        for (int j = 0; j < g[x].size(); j++)
        {
            if (vis[g[x][j]] == false)
            {
                q.push(g[x][j]);
                vis[g[x][j]] = true;
            }
        }
    }

    return res;
}