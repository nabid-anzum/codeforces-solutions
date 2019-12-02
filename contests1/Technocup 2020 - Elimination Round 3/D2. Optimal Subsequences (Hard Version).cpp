#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> kset;
 
pair<int,int> a [ 200002 ] ;
int ans [ 200002 ] ;
vector<pair<int,int> > Q [ 200002 ] ;
int main(){
	ios::sync_with_stdio(0);
	int n ; 
	cin >> n ; 
	for ( int i = 0 , x ; i < n ; i ++ ) cin >> x , a [ i ] = { -x , i } ;
	sort ( a , a + n ) ;
	kset s ;
	int m ; 
	cin >> m ; 
	for ( int i = 0 ; i < m ; i ++ ) {
		int k , pos ; 
		cin >> k >> pos ;
		Q [ k - 1 ].push_back ( { pos - 1 , i } ) ;
	}
	for ( int i = 0 ; i < n ; i ++ ) {
		s.insert ( { a [ i ].second , - a [ i ].first } ) ;
		for ( auto u : Q [ i ] ) ans [ u.second ] = (*s.find_by_order(u.first)).second ;
	}
	for ( int i = 0 ; i < m ; i ++ ) cout << ans [ i ] << endl ;
}
