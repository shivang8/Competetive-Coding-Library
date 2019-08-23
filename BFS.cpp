/*
Level Nodes
You have been given a Tree consisting of N nodes. A tree is a fully-connected graph consisting of N nodes and N-1 edges. The nodes in this tree are indexed from 1 to N. Consider node indexed 1 to be the root node of this tree. The root node lies at level one in the tree. You shall be given the tree and a single integer x. You need to find out the number of nodes lying on level x.

Input Format: The first line consists of a single integer N denoting the number of nodes in the tree. Each of the next N-1 lines consists of 2 integers a and b denoting an undirected edge between node a and node b. The next line consists of a single integer x.

Output Format: You need to print a single integers denoting the number of nodes on level x.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>	// Contains INT_MAX, INT_MIN

using namespace std;

int BFS(vector <int> v[], int n, int s, int x)
{
	//Initilization
	queue <int> q;
	int visit[n+5]={0};	// The colour of node 0 - white, 1 - grey, 2 - black
	int dist[n+5];	// The distance from root
	int predescessor[n+5];
	memset(predescessor,-1,sizeof(predescessor));
	memset(dist,INT_MAX,sizeof(dist));
	// Start with root
	visit[s] = 1;
	dist[s] = 0;
	predescessor[s] = -1;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i=0;i<v[u].size();i++)
		{
			if(visit[v[u][i]]==0)
			{
				q.push(v[u][i]);
				visit[v[u][i]]=1;
				dist[v[u][i]] = dist[u] + 1;
				predescessor[v[u][i]] = u;
			}
		}
		visit[u] = 2;
	}
	int count = 0;
	for(int i=1;i<n;i++)
	{
		if(dist[i]+1 == x)	// Distance + 1 = Height 
			count++;
	}
	return count;
}

int main()
{
	int n;
	cin>>n;
	vector <int> v[n+5];
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int x;
	cin>>x;
	cout<<BFS(v,n,1,x)<<endl;
	return 0;
}