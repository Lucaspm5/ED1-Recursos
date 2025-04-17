
#include <bits/stdc++.h>
using namespace std;
 
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
using vi = vector<int>;
 
int a, b;
vi parent;
 
int main() { _
	cin >> a >> b;
	auto solve = [&]() -> bool {
		while(b > a) {
			parent.push_back(b);
			if (~b & 1) b >>= 1;
			else if (b % 10 == 1) b = (b - 1) / 10;
			else return false;
		}
		return b == a;
	};
	if (!solve()) { cout << "NO"; return 0; }
	auto path = [&]() {
		cout << "YES" << '\n';
		parent.push_back(a);
		reverse(parent.begin(), parent.end());
		cout << (int)parent.size() << '\n';
		for(auto &i : parent) cout << i << ' ';
		cout << '\n';
	};
	path();
    return 0;
}
