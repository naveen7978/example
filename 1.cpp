#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> ve;
typedef vector<long long> vl;
typedef vector<pair<int,int>> vp;
typedef vector<char> vc;
typedef vector<double>vd;

#define fi first
#define se second
#define pb push_back
#define con continue 
#define rep(i,a,b) for (int i=a;i<b;i++)
#define res(j,a,b) for (int j=a;j>=b;j--)
void setIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
}
int mn , mni;
void dfs(int u , int l ,vector<int>v[] , vector<int>le[] ,vector<bool>&vis,vector<int>&val,vector<int>&parent){
 vis[u] = true;
 le[l].pb(u);
 if(mn>val[u]){
    mn = val[u] ; 
    mni = u;
 }
 for(auto ch : v[u]){
    if(vis[ch])con;
    dfs(ch,l+1,v,le,vis,val,parent);
    parent[ch] = u;
 }
}
int main(){
 int t;
 cin>>t;
 while(t--){
 int n,m=0,k;
 cin>>n;
 vector<int>adj[n],level[n];
 vector<int>v(n),ans,parent(n,-1);
 rep(i,0,n)cin>>v[i];
 rep(i,1,n){
  int u , v;
  cin>>u>>v;
  u--,v--;
  adj[u].pb(v);
  adj[v].pb(u);
  }
  vector<bool>vis(n);
  mn = INT_MAX  ;
 dfs(0,0,adj,level,vis,v,parent);
 int x = mni;
 ve rev;
 while(x!=-1){
  vis[x] = false;
  if(x!=mni)
    rev.pb(x);
  x = parent[x];
  }
  res(i,n-1,0){
    int k = level[i].size();
    m+=k;
    rep(j,0,k){
        int y = level[i][j];
        if(vis[y])ans.pb(y);
    }
  }
  m--;
  reverse(rev.begin(),rev.end());
   rep(i,0,rev.size())
   ans.pb(rev[i]);
   cout<<m<<"\n";
   rep(i,0,ans.size())cout<<ans[i]+1<<" ";
   cout<<"\n";
 }
}