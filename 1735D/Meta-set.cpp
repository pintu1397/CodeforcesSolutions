#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less_equal<int> ,rb_tree_tag , tree_order_statistics_node_update> indexed_set;


// Defines
#define int long long
#define nl cout << '\n'
#define FF first
#define SS second  
#define all(x) x.begin() , x.end()
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
// Constansts 
const int mod = 998244353;
const int inf = 1e18;

// Helpers
template<typename U,typename V>ostream& operator<<(ostream&os,pair<U,V>&p){os<<p.FF<<' '<<p.SS;nl;return os;}
template<typename T>ostream& operator<<(ostream&os,vector<T>&p){for(auto& e:p){os << e << ' ';}nl;return os;}
template<typename...  Args>void de(Args&&... args){((cout << args << ' '),...);}

template<typename U,typename V>istream& operator>>(istream&is,pair<U,V>&p){is>>p.FF>>p.SS;return is;}
template<typename T>istream& operator>>(istream&is,vector<T>& p){for(auto& e:p){is>>e;}return is;}
template<typename...  Args>void le(Args&&... args){((cin >> args),...);}
int TEST = 0;
void google(){
    cout << "Case #" << TEST+1 << ": " ;
}
// CODE /////////////////////////////////////////////////////////////////////////////////////////////////////

using ld = long double ;
const ld PI = 3.1415926535;
const ld eps = 1e-10;

struct deck{
   vector<int>cards;

   deck(int k){
    cards.resize(k);
   }


   bool operator<(const deck d1)const{
      int sz = d1.cards.size();
      for(int i = 0; i<sz ; i++){
        if(d1.cards[i] == this->cards[i])continue;
        return d1.cards[i] > this->cards[i];
      }
      return 1;
   }

};

void solve(){
   int n , k; cin >> n >> k;
    
   vector<deck>vec(n , deck(k));
   for(int i =0; i<n ; i++){
    for(int j = 0; j<k ; j++){
      cin >> vec[i].cards[j];
    }
   }
   // for each card i try forming cards 
   map<vector<int> , int> mp;
   
   auto resi = [k](deck d1 , deck d2)->deck{
    deck res(k);
    for(int  i= 0; i<k ; i++){
      if(d1.cards[i] == d2.cards[i])res.cards[i] = d1.cards[i];
      else res.cards[i] = 3 - d1.cards[i] - d2.cards[i];
    }
    return res;
   };
int ans = 0;
// cout << (st.find(resi(vec[0] , vec[1]).cards)!=st.end()) << '\n';
   for(int i = 0; i<n ; i++){
    // i is my central card ;(
    for(int j = i+1; j<n ; j++){
      mp[resi(vec[i], vec[j]).cards]++;        
    }
   }
   

   for(auto e:vec){
    
    ans = ans +((mp[e.cards])*(mp[e.cards]-1))/2;
   }
   cout << ans << '\n';
}


signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) ;
  #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif
  
  // int t; cin >> t; 
 int t  = 1;
  for(TEST = 0; TEST<t ; TEST++){
  // google();
  solve();}
  // solve();
}