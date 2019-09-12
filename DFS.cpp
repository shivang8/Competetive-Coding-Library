/*
    SUBMITED BY :   Shivang Srivastava
    USERNAME    :   shivang8
*/
#include<bits/stdc++.h>
#define fast_io std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long int
#define modulo 1000000007
using namespace std;

void dfs(vector <int> G[], int color[], int src)
{
    color[src]=1;
    for(int i=0;i<G[src].size();i++)
    {
        if(color[ G[src][i] ]==0)
        {
            dfs(G,color,G[src][i]);
        }
    }
    color[src]=2;
}

int main()
{
    fast_io;
    int n,m;
    cin>>n>>m;
    vector <int> G[n+5];
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int color[n+5]={0};
    int src;
    cin>>src;
    dfs(G,color,src);
    int c=0;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
            c++;
    }
    cout<<c<<endl;
    return 0;
}