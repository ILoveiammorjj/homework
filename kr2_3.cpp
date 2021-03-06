#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin >> n;
	int cab, st, dur;
	map<int, vector<pair<int, int> > > m;
	for(int i = 0; i < n; ++i) {
		cin >> cab >> st >> dur;
		m[cab].push_back(make_pair(st, dur));
	}
	int ans = m.size();
	for(auto it = m.begin(); it != m.end(); ++it) {
		auto v = it->second;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		auto cur = v.begin();
		for(auto itv = v.begin() + 1; itv != v.end(); ++itv) {
			if(itv->first + itv->second <= cur->first) {
				++ans; cur = itv;
			}
		}
	}
	cout << ans;
	return 0;
}
