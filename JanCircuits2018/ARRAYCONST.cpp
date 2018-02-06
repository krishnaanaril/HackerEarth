#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+5;

typedef pair<int, int> pii;

int n, m, mat[N][N], sz;
vector<pii> val, pos;
vector<int> a;
bitset<N> visit;

int main(){
      ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      cin>>n>>m;
      for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                  cin>>mat[i][j];
                  if(j>i){
                        pos.push_back({i, j});
                        val.push_back({mat[i][j], sz++});
                  }
            }
      }
      int chunk = m/n;
      int more, less;
      if(m%n){
            more = m - (n)*chunk;
            less = n - more;
            chunk++;
      }
      else{
            more = n;
            less = 0;
      }
      assert(more+less==n);
      // cout<<more<<" : "<<less<<" : "<<chunk<<"\n";
      int cnt = 0;
      sort(val.begin(), val.end());
      for(pii it : val){
            if(!visit[pos[it.second].first]){
                  if(more){
                        a.push_back(chunk);
                        more--;
                        cnt++;
                  }
                  else{
                        a.push_back(chunk-1);
                        cnt++;
                  }
            }
            if(cnt>=n)
                  break;
            if(!visit[pos[it.second].second]){
                  if(more){
                        a.push_back(chunk);
                        more--;
                        cnt++;
                  }
                  else{
                        a.push_back(chunk-1);
                        cnt++;
                  }
                  if(cnt>=n)
                  break;
            }
      }
      for(int it: a)
            cout<<it<<" ";
      cout<<"\n";
      return 0;
}
