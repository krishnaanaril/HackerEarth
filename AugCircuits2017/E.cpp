/*
	Swamy Saranam

	Date	: 27/01/2018 22:44:32
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
const int N = 2e5+5;

ll t, xs, ys, xt, yt, l;
ll fact[N], ifact[N];
ll dx, dy, res, S, lim;

ll bigExp(ll a, ll b){
      if(b==0)
            return 1;
      if(b==1)
            return a;
      if(b&1)
            return (a*bigExp(a, b-1))%MOD;
      ll res = bigExp(a, b>>1);
      return (res*res)%MOD;
}

inline void init(){
      fact[0] = fact[1] = 1;
      FOR(i, 2, N){
            fact[i] = (fact[i-1]*i)%MOD;
      }
      ifact[N-1] = bigExp(fact[N-1], MOD-2);
      for(int i=N-2; i>=0; i--){
            ifact[i] = (ifact[i+1]*(i+1))%MOD;
      }
      assert(ifact[10]==bigExp(fact[10], MOD-2));
}


int main()
{
      FASTIO
      init();
      cin>>t;
      while(t--){
            res = 0;
            cin>>xs>>ys>>xt>>yt>>l;
            dx = abs(xs-xt);
            dy = abs(ys-yt);
            S = dx+dy;
            lim = l - S;
            if(l<S || lim&1){
                  cout<<"0\n";
                  continue;
            }
            for(int k=0; k<=lim; k+=2){
                  ll tmp = fact[l];
                  tmp = (tmp*ifact[k/2])%MOD;
                  tmp = (tmp*ifact[(lim-k)/2])%MOD;
                  tmp = (tmp*ifact[dx+(k/2)])%MOD;
                  tmp = (tmp*ifact[dy+((lim-k)/2)])%MOD;
                  res = (res + tmp)%MOD;
            }
            cout<<res<<"\n";
      }
      return 0;
}
