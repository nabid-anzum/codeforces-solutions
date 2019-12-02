#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int T, a, b, k;
	for(cin >> T; T; T--){
		cin >> a >> b >> k;
		int gcd = __gcd(a, b);
		cout << ((max((a + b - 2*gcd) / b, (b + a - 2*gcd) / a) >= k)? "REBEL\n":"OBEY\n");
	}
}
