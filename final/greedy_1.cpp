#include <bits/stdc++.h>
using namespace std;

struct Item {
	int id;
	double w, v, ratio;
};

bool compareR(Item a, Item b){
	return a.ratio > b.ratio;
}

int main() {
	int n;
	double maxW;
	cin >> n >> maxW;
	
	vector<Item> data(n);
	for (int i = 0; i < n; i++) data[i].id = i;
	for (int i = 0; i < n; i++) cin >> data[i].w;
	for (int i = 0; i < n; i++) {
		cin >> data[i].v;
		data[i].ratio = data[i].v/data[i].w;
	}
	
	sort(data.begin(), data.end(), compareR);
	double totalValue = 0.0, fraction;
	vector<double> x(n, 0.0);
	
	for (int i = 0; i < n; i++) {
		if (maxW <= 0) break;
		
		if (data[i].w <= maxW) {
			x[data[i].id] = 1.0;
			totalValue += data[i].v;
			maxW -= data[i].w;
		} else {
			fraction = maxW/data[i].w;
			x[data[i].id] = fraction;
			totalValue += (fraction*data[i].v);
			maxW -= maxW;
		}
	}
	
	for (int i = 0; i < n; i++) {
		printf("%.2f ", x[i]);
	}
	printf("\n%.2f", totalValue);
}