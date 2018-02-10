/*
	Swamy Saranam

	Date	: 09/02/2018 23:24:05
	Author	: Krishna Mohan A M
	Problem	:
	Status	:
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pll;

#define FASTIO                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b)            for(int i=(a);i<(b);i++)
#define REP(i,n)              FOR(i,0,n)
#define SORT(v)               sort((v).begin(),(v).end())
#define UN(v)                 SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)               memset(a,b,sizeof a)
#define PB                    push_back
#define F                     first
#define S                     second

const int MOD = 1000000007;
const int N = (1<<22);

int segTree[N], lz[N], dat[N];
int n, q, k, ty, a, b, c, ln;

inline void pushDown(int node, int l, int r){
      if(lz[node]==-1)
            return;
      segTree[node] = lz[node];
      if(l!=r)
            lz[2*node] = lz[2*node+1] = lz[node];
      lz[node] = -1;
}

void build(int node, int l, int r){
      if(l==r){
            segTree[node] = dat[l];
            return;
      }
      int mid = (l+r)>>1;
      build(2*node, l, mid);
      build(2*node+1, mid+1, r);
      segTree[node] = max(segTree[2*node], segTree[2*node+1]);
}

int query(int node, int l, int r, int sp, int ql, int qr){
      pushDown(node, l, r);
      if(ql<=l && qr>=r){
            return segTree[node];
      }
      int node1 = 2*node, node2 = 2*node+1;
      if(sp&1)
            swap(node1, node2);
      int ans = 0;
      int mid = (l+r)>>1;
      if(ql<=mid)
            ans = max(ans, query(node1, l, mid, (sp>>1), ql, qr));
      if(qr>=mid+1)
            ans = max(ans, query(node2, mid+1, r, (sp>>1), ql, qr));
      return ans;
}

void update(int node, int l, int r, int sp, int ql, int qr, int val){
      pushDown(node, l, r);
      if(l>=ql && r<=qr){
            lz[node] = val;
            pushDown(node, l, r);
            return;
      }
      int node1 = 2*node, node2 = 2*node+1;
      if(sp&1)
            swap(node1, node2);
      int mid = (l+r)>>1;
      pushDown(node1, l, mid);
      pushDown(node2, mid+1, r);
      if(ql<=mid)
            update(node1, l, mid, (sp>>1), ql, qr, val);
      if(qr>=mid+1)
            update(node2, mid+1, r, (sp>>1), ql, qr, val);
      segTree[node] = max(segTree[node1], segTree[node2]);
}

int main()
{
      FASTIO
      cin>>n>>q;
      ln = n;
      n = 1<<n;
      REP(i, n){
            cin>>dat[i];
      }
      CL(lz, -1);
      build(1, 0, n-1);
      k = 0;
      while(q--){
            cin>>ty;
            switch(ty){
                        case 1:
                              // cout<<"in query\n";
                              cin>>a>>b;
                              cout<<query(1, 0, n-1, k, a, b)<<"\n";
                              break;
                        case 2:
                              // cout<<"in update\n";
                              cin>>a>>b>>c;
                              update(1, 0, n-1, k, a, b, c);
                              break;
                        case 3:
                              cin>>a;
                              REP(i, ln){
                                    if((a>>i)&1)
                                          k^= (1<<(ln-i-1));
                              }
                              // cout<<"in swap : "<<k<<"\n";
                              break;
            };
      }
      return 0;
}
