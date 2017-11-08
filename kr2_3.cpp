#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if(p1.first > p2.first) return true;
	if(p1.first == p2.first && p1.second < p2.second) return true;
	return false;
}

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
		auto cur = v.begin();
		sort(v.begin(), v.end(), cmp);
		for(auto itv = v.begin() + 1; itv != v.end(); ++itv) {
			if(itv->first + itv->second <= cur->first) {
				++ans; cur = itv;
			}
		}
	}
	cout << ans;
	return 0;
}
