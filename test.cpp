#include<bits/stdc++.h>
using namespace std;
//typedef
typedef long long ll;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
//template
template<class T> inline bool chmin(T &a, T b) {if (a > b){a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b) {if (a < b){a = b; return true;} return false;}
//repetition
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPS(i,N) for(int i=0; i<=int(N); ++i)
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

int main() {
    int N; cin >> N;
    VVL tate,yoko;
    ll ans = 10000;

    REP(i,N) {
        VL tmp(4); cin>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3];
        if (tmp[0] == tmp[2]) tate.PB(tmp);
        else yoko.PB(tmp);
    }

    sort(ALL(tate));
    sort(ALL(yoko),[](const vector<ll> &alpha,const vector<ll> &beta){return alpha[1] < beta[1];});

    REP(i,tate.size()-1)FOR(j,i+1,tate.size())REP(k,yoko.size()-1)FOR(l,k+1,yoko.size()) {
        if (tate[i][0]<yoko[k][0] || tate[i][0]<yoko[l][0] || tate[j][2]>yoko[k][2] || tate[j][2]>yoko[l][2]) continue;
        if (yoko[l][3]>tate[i][3] || yoko[l][3]>tate[j][3] || yoko[k][1]<tate[i][1] || yoko[k][1]<tate[j][1]) continue;
        ans = min(ans,(yoko[l][1]-yoko[k][1])*(tate[j][0]-tate[i][0]));
    }

    cout << ans << endl;
}