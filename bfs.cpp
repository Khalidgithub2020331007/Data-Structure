#include<bits/stdc++.h>
using namespace std;
vector<int>adj[30000];
vector<int>w[30000];
bool vis[30000];
int d[30000];
void clr(int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    vis[i]=0;
    d[i]=0;
  }
}
void bfs(int node,int n)
{
  queue<int>q;
  vis[node]=1;
  q.push(node);
  vis[node]=1;
  while(!q.empty())
  {
    node=q.front();
    q.pop();
    for(int it=0;it<adj[node].size();it++)
    {
      int v=adj[node][it];
      if(!vis[v])
      {
        vis[v]=1;
        d[v]=d[node]+w[node][it];
        q.push(v);
      }
    }
  }
}
int main(){
  int t,k;
  cin>>t;
  for(k=1;k<=t;k++)
  {
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
      adj[i].clear();
      w[i].clear();
    }
    for(i=0;i<n-1;i++)
    {
      int x,y,c;
      cin>>x>>y>>c;
      adj[x].push_back(y);
      adj[y].push_back(x);
      w[x].push_back(c);
      w[y].push_back(c);
    }
    int m=0,fn;
    clr(n);
    bfs(0,n);
    for(i=0;i<n;i++)
    {
      if(d[i]>m)
      {
        m=d[i];
        fn=i;
      }
    }
    clr(n);
    int ans=0;
    bfs(fn,n);
    for(i=0;i<n;i++)
    {
      if(d[i]>ans)ans=d[i];
    }
    cout<<"Case"<<" "<<k<<": "<<ans<<endl;
  }
}
