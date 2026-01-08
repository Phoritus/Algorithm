#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> Matrix;

Matrix add(Matrix A, Matrix B) {
	int n = A.size();
	Matrix ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = A[i][j] + B[i][j];
		}
	}
	return ans;
}

Matrix multiply(vector<vector<int>> A, vector<vector<int>> B, int n) {
	Matrix C(n, (vector<int>(n, 0)));
	int newsize = n / 2;
	if (n == 1) {
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	
	Matrix A11(newsize, vector<int>(n ,0)), A12(newsize, vector<int>(n, 0)),
		   B11(newsize, vector<int>(n, 0)), B12(newsize, vector<int>(n, 0)),
		   A21(newsize, vector<int>(n, 0)), A22(newsize, vector<int>(n, 0)),
		   B21(newsize, vector<int>(n, 0)), B22(newsize, vector<int>(n, 0));
	
	for (int i = 0; i < newsize; i++) {
		for (int j = 0; j < newsize; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + newsize];
			A21[i][j] = A[i + newsize][j];
			A22[i][j] = A[i + newsize][j + newsize];
			
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][j + newsize];
			B21[i][j] = B[i + newsize][j];
			B22[i][j] = B[i + newsize][j + newsize];
		}
	}
	
	
	Matrix C11 = add(multiply(A11, B11, newsize), multiply(A12, B21, newsize));
	
	Matrix C12 = add(multiply(A11, B12, newsize), multiply(A12, B22, newsize));
	
	Matrix C21 = add(multiply(A21, B11, newsize), multiply(A22, B12, newsize));
	
	Matrix C22 = add(multiply(A21, B12, newsize), multiply(A22, B22, newsize));
	
	for (int i = 0; i < newsize; i++) {
		for (int j = 0; j < newsize; j++) {
			C[i][j] = C11[i][j];
			C[i][j + newsize] = C12[i][j];
			C[i + newsize][j] = C21[i][j];
			C[i + newsize][j + newsize] = C22[i][j];
		}
	}
	
	return C;
	
}

int main() {
	vector<vector<int>> A = {
        {1, 0, 1, 0},
        {2, 0, 2, 0},
        {3, 0, 3, 0},
        {4, 0, 0, 0}
    };
    vector<vector<int>> B = {
        {-1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {1, 1, 0, 0}
    };
	int size = A.size();
	Matrix C = multiply(A, B, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size;j ++) {
			cout << C[i][j] << " ";
		} 
		cout << endl;
	}
	

	return 0;
}