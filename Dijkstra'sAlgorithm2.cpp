#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t3;
  cin>>t3;
  while(t3--)
  {
    int t2;
    string x,y;
    map<string,int>mymap;
    cin>>t2;
    vector<vector<pair<int,int>>>adj(t2+1);
    int n;
    for(int t=1;t<=t2;t++)
    {
      cin>>x;
      mymap[x]=t;
      
      cin>>n;
      
      while(n--)
      {
        int destination,weight;
        cin>>destination>>weight;
        adj[t].push_back({destination,weight});
      }
      
    }
    cin>>n;
    while(n--)
    {
      string x,y;
      cin>>x>>y;
      int startnode=mymap[x];
      int endnode=mymap[y];
      vector<int>shdis(adj.size(),INT_MAX);
      shdis[startnode]=0;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      pq.push({0,startnode});
      while(!pq.empty())
      {
        int cudis=pq.top().first;
        int cuno=pq.top().second;
        pq.pop();
        if(cudis>shdis[cuno])
        continue;
        for(const pair<int,int>& node:adj[cuno])
        {
          int ndis=cudis+node.second;
          if(ndis<shdis[node.first])
          {
            shdis[node.first]=ndis;
            pq.push({ndis,node.first});
          }
        }
      }
      cout<<shdis[endnode]<<endl;
      
    }
    
    
  }
}
