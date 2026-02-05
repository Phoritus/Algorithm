#include <bits/stdc++.h>
using namespace std;

struct Queen{
	int row, col;
};

bool isSafe(int row, int col, vector<Queen> &placed) {
	
	for (const auto& q : placed) {
		if (abs(col - q.col) == abs(row - q.row) || (col == q.col)) {
			return false;
		}
	}
	return true;
}

void solvedNqueen(vector<Queen> &placed, int &solveCount, int i, int n) {
	
	if (i == n) {
		solveCount++;
		vector<int> rowPos(n);
	    for (const auto& q : placed) {
	        rowPos[q.col] = q.row; 
	    }
	    for (int r : rowPos) {
	        cout << r << " ";
	    }
	    cout << endl;
	    return;
	}
	
	for (int j = 0; j < n; j++) {
		if (isSafe(i, j, placed)) {
			placed.push_back({i, j});
			solvedNqueen(placed, solveCount, i + 1, n);
			placed.pop_back();
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<Queen> placed;
	int solveCount = 0;
	solvedNqueen(placed, solveCount, 0, n);
	cout << solveCount;
}