/*
	Swamy Saranam

	Date	: 27/01/2018 15:02:00
	Author	: Krishna Mohan A M
	Problem	: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/vizard-and-turns-a8c61c7e/
	Status	: Accepted, Dijkstra
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
const int N = 1e3+5;

struct Node{
      pii pos;
      int dir;
      Node(int _x, int _y, int _d): pos({_x, _y}), dir(_d){}
};

int dp[N][N][4];
string dat[N];
int n, m, ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<Node> q;
pii st, en;

int main()
{
      FASTIO
      cin>>n>>m;
      REP(i, n){
            cin>>dat[i];
            REP(j, m){
                  if(dat[i][j]=='V'){
                        st = pii(i, j);
                  }
                  if(dat[i][j]=='H'){
                        en = pii(i, j);
                  }
            }
      }
      CL(dp, -1);
      // cout<<st.F<<" : "<<st.S<<"\n";
      // cout<<en.F<<" : "<<en.S<<"\n";
      REP(i, 4){
            dp[st.F][st.S][i] = 0;
            q.push(Node(st.F, st.S, i));
      }
      while(!q.empty()){
            Node cur = q.front();
            q.pop();
            REP(i, 4){
                  Node nxt = {cur.pos.F+dx[i], cur.pos.S+dy[i], i};
                  if(nxt.pos.F <0 || nxt.pos.F>=n)
                        continue;
                  if(nxt.pos.S<0 || nxt.pos.S >=m)
                        continue;
                  if(dat[nxt.pos.F][nxt.pos.S]=='*')
                        continue;
                  if(dp[nxt.pos.F][nxt.pos.S][i]==-1 ||
                        (dp[nxt.pos.F][nxt.pos.S][i] > dp[cur.pos.F][cur.pos.S][cur.dir]+(cur.dir != i))){
                        dp[nxt.pos.F][nxt.pos.S][i] = dp[cur.pos.F][cur.pos.S][cur.dir]+(cur.dir != i);
                        q.push(nxt);
                  }
            }
      }
      ans = MOD;
      REP(i, 4){
            // cout<<dp[en.F][en.S][i]<<"\n";
            if(dp[en.F][en.S][i]==-1)
                  continue;
            ans = min(ans, dp[en.F][en.S][i]);
      }
      if(ans==MOD)
            ans = -1;
      cout<<ans<<"\n";
      return 0;
}
