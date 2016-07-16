#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("A-small-practice.in","rt",stdin);
	freopen("A_large13.out","wt",stdout);
	int T;
	cin >> T;
	for(int kase = 1; kase <= T; ++kase) {
		int p;
		cin >> p;
		vector<int> w(p);
		for(int i = 0; i < p; ++i)
			cin >> w[i];
		int n;
		cin >> n;
		map<string, vector<int>> scores;
		for(int i = 0; i < n; ++i) {
			int s;
			cin >> s;
			for(int j = 0; j < p; ++j) {
				string name;
				cin >> name;
				scores[name].push_back(s * w[j]);
			}
		}
		int m;
		cin >> m;
		vector<pair<int, string>> ranks;
		for(auto &it : scores) {
			sort(it.second.begin(), it.second.end(), greater<int>());
			int sum = 0;
			for(size_t i = 0; i < it.second.size() and i < m; ++i)
				sum += it.second[i];
			ranks.emplace_back(sum, it.first);
		}
		sort(ranks.begin(), ranks.end(), [](pair<int, string> a, pair<int, string> b) {
			if(a.first != b.first) return a.first > b.first;
			return a.second < b.second;
		});
		printf("Case #%d:\n", kase);
		int r = 0;
		for(size_t i = 0; i < ranks.size(); ++i) {
			if(i == 0 or ranks[i].first < ranks[i - 1].first)
				r = i + 1;
			printf("%d: %s\n", r, ranks[i].second.c_str());
		}
	}
	return 0;
}
