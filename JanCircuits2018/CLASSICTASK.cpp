#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 1e6+5;

int n, m, lg, a, b, ans;
int parent[N];
vector<pii> edges, e[55];

int find(int k){
      return k == parent[k] ? k : parent[k] = find(parent[k]);
}

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n>>m;
      for(int i=0; i<m; i++){
            cin>>a>>b;
            edges.push_back(pii(a, b));
      }
      while(n>>(lg+1))
            lg++;
      for(pii it : edges){
            int l1 = it.first;
            int r1 = it.second;
            int l2 = (n - r1 + 1) + n;
            int r2 = (n - l1 + 1) + n;
            // cout<<l1<<" : "<<r1<<" : "<<l2<<" : "<<r2<<"\n";
            for(int t=lg; t>=0; t--){
                  if(l2+(1<<t)-1 <= r2){
                        // cout<<t<<" : "<<l1<<" - "<<l2<<" - "<<(1<<t)<<"\n";
                        e[t].push_back(pii(l1, l2));
                        l2 += (1<<t);
                        l1 += (1<<t);
                  }
            }
      }
      for(int t=lg; t>=0; t--){
            for(int i=1; i<=2*n; i++){
                  parent[i] = i;
            }
            for(pii it : e[t]){
                  parent[find(it.first)] = find(it.second);
            }
            if(!t)
                  break;
            for(int i=0; i<n+n; i++){
                  if(i != find(i)){
                        e[t-1].push_back(pii(i, find(i)));
                        e[t-1].push_back(pii(i+(1<<(t-1)), find(i)+(1<<(t-1))));
                  }
            }
            e[t].clear();
      }
      for(int i=1; i<=n; i++){
            parent[find(i)] = find(n+n-i+1);
      }
      for(int i=1; i<=n+n; i++){
            if(i==find(i))
                  ans++;
      }
      cout<<ans<<"\n";
      return 0;
}
