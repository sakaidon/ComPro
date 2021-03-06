#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
//repetition
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
//container util
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//constant
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

void dfs(VVI G, int x, int y, VVB &seen) {
    seen[x][y] = true;
    FOR(i,-1,2)FOR(j,-1,2) {
        int nx = x + i;
        int ny = y + j;
        if (nx<0 || nx>=G[0].size() || ny<0 || ny>=G.size()) continue;
        if (seen[nx][ny]) continue;
        if (G[nx][ny] == 0) continue;
        dfs(G,nx,ny,seen);
    }
}

int main() {
    int W, H; cin>>W>>H;
    VVI G(H,VI(W));
    REP(i,H)REP(j,W) cin>>G[i][j];
    VVB seen(H,VB(W,false));

    int res = 0;
    REP(i,H)REP(j,W) {
        if (seen[i][j] == true) continue;
        if (G[i][j] == 0) continue;
        
        res++;
        dfs(G,i,j,seen);
    }

    cout<<res;
}