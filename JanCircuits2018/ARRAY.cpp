#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double, double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FASTIO          ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back
#define x               first
#define y               second
#define EPS             1e-6
#define	endl			"\n"

const int mod = 1000000007;
const int N = 1e6+5;

int n, k, tmp;
int dat[N][3];
int cnt[N], sz;
vi s, q[N][3];
multiset<int, greater<int>> ms;

int main()
{
    FASTIO
    cin>>n>>k;
    REP(i, n){
    	REP(j, 3){
    		cin>>tmp;
    		dat[i][j] = tmp;
    		s.push_back(k-tmp);
    	}
    }
    UN(s);
 //   for(int it : s){
	// cout<<it<<" ";
 //   }
 //   cout<<"\n";
 //   cout<<(lower_bound(s.begin(), s.end(), 3) - s.begin())<<"\n";
    REP(i, n){
    	REP(j, 3)
    		cnt[i] += dat[i][j];
    	ms.insert(cnt[i]);
    }
    REP(i, n){
    	REP(j, 3){
    		q[lower_bound(s.begin(), s.end(), k-dat[i][j]) - s.begin()][j].push_back(i);
    	}
    }
    sz = s.size();
 //   REP(i, sz){
	// REP(j, 3){
	// 	cout<<q[i][j].size()<<" ";
	// }
	// cout<<"\n";
 //   }
    int ans = *ms.begin();
    REP(i, n)
	cout<<cnt[i]<<" ";
    cout<<"\n";
    REP(i, sz){
    	REP(j, 3){
    		for(int it : q[i][j]){
    			ms.erase(ms.find(cnt[it]));
    			cnt[it]-=k;
    			ms.insert(cnt[it]);
    		}
    	}
    	REP(i, n)
		cout<<cnt[i]<<" ";
	    cout<<"\n";
    	ans = min(ans, *ms.begin()+3*s[i]);
    }
    cout<<ans<<"\n";

    return 0;
}
