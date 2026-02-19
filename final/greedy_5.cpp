#include <bits/stdc++.h>
using namespace std;

struct Point{
	int xi, xj;
};

bool compareP(Point a, Point b) {
	if (a.xi != b.xi) return a.xi < b.xi;
	return a.xj > b.xj;
}

int main() {
	
	int n;
	cin >> n;
	vector<Point> data(n);
	for (int i = 0; i < n; i++) cin >> data[i].xi >> data[i].xj;
	
	int xa, xb;
	cin >> xa >> xb;
	
	sort(data.begin(), data.end(), compareP);
	int currentEnd = xa;
	int i = 0;
	vector<Point> res;
	
	while (currentEnd < xb) {
		int bestEnd = currentEnd;
		int bestIdx = -1;
		
		while (i < n && data[i].xi <= currentEnd) {
			if (data[i].xj > bestEnd) {
				bestEnd = data[i].xj;
				bestIdx = i;
			}
			i++;
		}
		
		res.push_back({data[bestIdx].xi, data[bestIdx].xj});
		currentEnd = bestEnd;
	}
	
	cout << res.size() << endl;
	for (const auto& val : res) {
		cout << val.xi << " " << val.xj << endl;
	}
}