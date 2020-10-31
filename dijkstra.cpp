#include<queue>
#include<iostream>
#include<vector>

using namespace std;
int inf = 1e9;

vector<pair<int,int>> ad[100005];
vector<int> dist(100005,inf);
vector<int> vis(100005,0);

void dijsktra(int source)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
    q.push(make_pair(0, source));
    dist[source]=0;

    while(!q.empty())
    {
        int top_vtx = q.top().second;
        q.pop();
        if(vis[top_vtx]==1)
            continue;
        vis[top_vtx]=1;

        for(int i=0;i<ad[top_vtx].size();i++)
        {
            int x = ad[top_vtx][i].first;
            int w = ad[top_vtx][i].second;

            if(dist[x] > dist[top_vtx] + w && vis[x]==0)
            {
                dist[x]  = dist[top_vtx] + w;
                q.push(make_pair(dist[x], x));
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    int i;
    for(i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ad[u].push_back(make_pair(v,w));
        ad[v].push_back(make_pair(u,w));
    }
    int source;
    cin>>source;
    dijsktra(source);
    for(i=0;i<n;i++)
    {
        cout<<"Shortest distance between "<<source<<" and "<<i<<" is "<<dist[i]<<endl;
    }
    return 0;
}