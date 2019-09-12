/*
    SUBMITED BY :   Shivang Srivastava
    USERNAME    :   shivang8
*/
#include<bits/stdc++.h>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long int
#define modulo 1000000007
using namespace std;

int prims(vector <pair<int,int> > G[], int src, int n)
{
    ll wt=0;
    priority_queue < pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
    bool vis[n+5];int w[n+5];
    for(int i=1;i<=n;i++){
        
        w[i] = INT_MAX;
        vis[i] = 0;
    }
    w[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        pair<int,int> x = pq.top();
        int u = x.second;
        pq.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        wt+=x.first;
        for(int i = 0; i<G[u].size() ; i++)
        {
            int v = G[u][i].first;
            int d = G[u][i].second;
            if(!vis[v])
            {
                pq.push(make_pair(d,v));
            }
        }
    }
/*    for(int i=1;i<=n;i++)
    {
        if(i!=src)
        {
            if( w[i] == INT_MAX)
                cout<<"-1 ";
            else
                cout<<w[i]<<" ";
        }
    }*/
    return wt;
}

int main()
{
    fast_io;
    int n,m;
    cin>>n>>m;
    vector <pair<int,int> > G[n+5];
    while(m--)
    {
            int x,y,z;
            cin>>x>>y>>z;
            G[x].push_back(make_pair(y,z));
            G[y].push_back(make_pair(x,z));
    }
    int src;
    cin>>src;
    cout<<prims(G,src,n)<<endl;
    return 0;
}
