#include<bits/stdc++.h>

#include <algorithm>
#include <cassert>
#include <vector>
namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        if(0 > b || b >= _n){
            std::cout<<b<<' '<<_n;
            exit(0);
        }
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        return _leader(a);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;

    int _leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = _leader(parent_or_size[a]);
    }
};

}  // namespace atcoder

#define int long long
#define mp make_pair
#define pb push_back
#define PII pair<int,int>
#define PDD pair<double,double>
#define all(x) x.begin(), x.end()
using namespace std;

int mod=1e9+7;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> pts(k+1);
    for(int i=0;i<k+1;i++){
        cin>>pts[i].first>>pts[i].second;
        pts[i].first--,pts[i].second--;
    }
    atcoder::dsu uf(n*m);
    vector<int> self_circle(n*m,0),edges(n*m,0);
    auto f = [&] (int x,int y) -> int {return x*m+y;};
    for(int i=0;i<k;i++){
        auto [x,y]=pts[i];
        auto [xn,yn]=pts[i+1];
        int mhd=abs(xn-x)+abs(yn-y);
        if(mhd!=2){
            cout<<"0\n";
            return;
        }
        if(x==xn||y==yn){
            edges[f((x+xn)/2,(y+yn)/2)]++;
            self_circle[f((x+xn)/2,(y+yn)/2)]=1;
        }else{
            uf.merge(f(x,yn),f(xn,y));
            edges[f(x,yn)]++;
        }
    }
    for(int i=0;i<n*m;i++){
        if(uf.leader(i)!=i){
            int l=uf.leader(i);
            edges[l]+=edges[i];
            self_circle[l] |= self_circle[i];
        }
    }
    int ans=1;
    for(int i=0;i<n*m;i++){
        if(uf.leader(i)==i){
            if(edges[i]>uf.size(i)){
                ans=0;
            }else if(edges[i]==uf.size(i)){
                if(self_circle[i]==0){
                    ans=2*ans%mod;
                }
            }else{
                ans=ans*uf.size(i)%mod;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}