#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int cnt[10001];
vector<int>result;
bool toposort(int n)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=n;i++)
        if(cnt[i]==0) 
        pq.push(i);

    while(!pq.empty())
    {
        int current=pq.top();
        result.push_back(current);
        pq.pop();

        for(int i:adj[current])
        {
            cnt[i]--;
            if(cnt[i]==0)
                pq.push(i);
        }
    }
    return result.size()==n;
}
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        cnt[y]++;
    }
    if (!toposort(n))
    {
        cout<<"Sandro fails.";

    }

    else
    {

        for(int i:result)
            cout<<i<<" ";
    }
}
