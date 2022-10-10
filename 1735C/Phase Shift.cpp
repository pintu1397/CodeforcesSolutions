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


struct sdsu{
   map<char ,char>point;
   map<char , char>head;
   map<char , char>tail;
   vector<int>rank;
   sdsu(){
      rank.resize(26); 
      for(int i = 0; i<26 ; i++){rank[i] = 1;}
      for(char c = 'a'; c<='z' ; c++){head[c] = c; tail[c] = c;point[c]  = c;}
   }

   void merge(char c1 , char c2){
    
     char h1 = head[c1];
     char t1 = tail[c1];
     char h2 = head[c2];
     char t2 = tail[c2];
     if(h1 == h2 && rank[h1]<26){
      cout << "lvda h kya\n"; exit(0);
     }
     if(rank[h1-'a']<26)rank[h1-'a']+=rank[h2-'a'];
     point[t1] = h2;
     // updating heads of second group
     for(auto e:head){
      if(e.second == h2){
        head[e.first] = h1;
      }
     }
    // updating taills 
     for(auto e:tail){
      if(e.second == t1){
        tail[e.first] = t2;
      }
     }
   }


   char find(char ch){
    if(point[ch]!=ch)return point[ch];
    bool f = 0;
    for(char cc = 'a' ; cc<='z'; cc++){
      if(ch == cc)continue;
      if(head[cc] != cc)continue;
      if(head[ch]==head[cc] && rank[ch-'a']<26)continue;
      f  = 1;
      merge(ch , cc); break;
    }
    if(!f){
      point[ch] = head[ch];
    }
    return point[ch];
   }
   
};

void solve(){
   int n ; cin>> n ; string t;; cin >> t;

   string ans ; 
   sdsu pp;


   for(int i=  0; i<n ; i++){
    ans.push_back(pp.find(t[i]));
   
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
  
  int t; cin >> t; 
 
  for(TEST = 0; TEST<t ; TEST++){
  // google();
  solve();}
  // solve();
}