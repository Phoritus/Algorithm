#include <bits/stdc++.h>
using namespace std;

struct Gift{
	int i1, i2;
	int differ;
};

bool compareD(Gift a, Gift b) {
	return a.differ > b.differ;
}

int main() {	
	int n;
	cin >> n;
	vector<Gift> gift(n);
	for (int i = 0; i < n; i++) {
		cin >> gift[i].i1 >> gift[i].i2;
		gift[i].differ = abs(gift[i].i1-gift[i].i2);
	}
	
	vector<int> k1(n),k2(n);
	sort(gift.begin(), gift.end(), compareD);	
	int v_max = INT_MIN, v_min = INT_MAX;
	int sum1 = gift[0].i1, sum2 = gift[0].i2;
	k1[0] = gift[0].i1; k2[0] = gift[0].i2;
	
	for (int i = 1; i < n; i++) {
		v_max = max(gift[i].i1, gift[i].i2);
		v_min = min(gift[i].i1, gift[i].i2);
		
		if (sum1 <= sum2) {
			sum1 += v_max;
			k1[i] = v_max;
			
			sum2 += v_min;
			k2[i] = v_min;
			
		} else {
			sum1 += v_min;
			k1[i] = v_min;
			
			sum2 += v_max;
			k2[i] = v_max;
		}
	}	
	cout << abs(sum1 - sum2);
}
