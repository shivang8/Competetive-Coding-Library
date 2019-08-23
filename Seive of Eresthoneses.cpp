/*
    SUBMITED BY :   Shivang Srivastava
    USERNAME    :   shivang8
*/
#include<iostream>
#include<vector>
#include<cstring>	// Contains memset
#define mm(a,n) memset(a,n,sizeof(a))
using namespace std;

vector <int> find_prime(int s, int e)
{
    bool a[e+5];
    mm(a,true);
    a[0]=false;
    a[1]=false;
    for(int i=2;i*i<=e;i++)
    {
        for(int p=i*i;p<=e;p=p+i)
        {
            a[p]=false;
        }
    }
    vector <int> v;
    for(int i=s;i<=e;i++)
    {
        if(a[i])
            v.push_back(i);
    }
    return v;
    
}

int main()
{
    vector <int> v;
    v = find_prime(0,50);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
