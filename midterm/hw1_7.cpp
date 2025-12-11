#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> A = {5, 15, -30, 10, -5, 40, 10};
	int target = 20;
	unordered_map<int, int> map;
	vector<pair<int,int>> ans;
	
	for (int i = 0; i < A.size(); i++){
		
		int diff = target - A[i];
		if (map.find(diff) != map.end()) {
			ans.push_back({diff, A[i]});
			map.erase(diff);
		} else {
			map.insert({A[i], i});
		}
		
	}
	for (auto &val : ans){
		cout << "{" << val.first << "," << val.second << "}" << endl;
	}
	
}