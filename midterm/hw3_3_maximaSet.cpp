#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

long long cmp_M1_M2 = 0;

bool compareX(Point a, Point b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

vector<Point> mergeSet(vector<Point> &left, vector<Point> &right) {
    vector<Point> result = right;

    int maxY = -1;

    for (auto &p : right) {
        maxY = max(maxY, p.y);
    }
	int count = 0;
	
    for (auto &p : left) {
        cmp_M1_M2++;
        count++;
        if (p.y > maxY) {
            result.push_back(p);
        }
    }
    cout << "Comparision M1 and M2: " << count << endl;
    
    cout << "Left: " << endl;
    for (auto &p : left) {
        cout << "(" << p.x << "," << p.y << ")\n";
    } cout << endl;
    
    cout << "Right: " << endl;
	for (auto &p : right) {
        cout << "(" << p.x << "," << p.y << ")\n";
    } cout << endl;
    
    cout << "Result: " << endl;
    for (auto &p : result) {
        cout << "(" << p.x << "," << p.y << ")\n";
    } 
    cout << endl;
    
    for (int i = 0; i < 20; i++) cout << "-";
    cout << endl;
    return result;
}

vector<Point> maximaSet(vector<Point> &arr, int l, int r) {
    if (l == r) return {arr[l]};

    int m = (l + r) / 2;

    vector<Point> M1 = maximaSet(arr, l, m);
    vector<Point> M2 = maximaSet(arr, m + 1, r);

    return mergeSet(M1, M2);
}

int main() {
    vector<Point> arr = {
        {7,2}, {3,1}, {9,3}, {4,5}, {1,4},
        {6,9}, {2,6}, {5,7}, {8,6}
    };

    sort(arr.begin(), arr.end(), compareX);

    vector<Point> res = maximaSet(arr, 0, arr.size() - 1);

    cout << "Maxima set:\n";
    for (auto &p : res) {
        cout << "(" << p.x << "," << p.y << ")\n";
    }

    cout << "\nNumber of comparisons between M1 and M2 = "
         << cmp_M1_M2 << endl;
}