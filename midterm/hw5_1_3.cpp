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

Matrix subtract(Matrix A, Matrix B) {
	int n = A.size();
	Matrix ans(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = A[i][j] - B[i][j];
		}
	}
	return ans;
}

Matrix multiply(Matrix A, Matrix B, int n) {
	Matrix C(n, vector<int>(n,0));
	if (n == 1) {
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	
	int newsize = n/2;
	Matrix A11(newsize, vector<int>(newsize, 0)), A12(newsize, vector<int>(newsize, 0)),
		   A21(newsize, vector<int>(newsize, 0)), A22(newsize, vector<int>(newsize, 0)),
		   B11(newsize, vector<int>(newsize, 0)), B12(newsize, vector<int>(newsize, 0)),
		   B21(newsize, vector<int>(newsize, 0)), B22(newsize, vector<int>(newsize, 0));
	
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
	
	Matrix M1 = multiply(add(A11, A22), add(B11, B22), newsize);
	Matrix M2 = multiply(add(A21, A22), B11, newsize);
	Matrix M3 = multiply(A11, subtract(B12, B22), newsize);
	Matrix M4 = multiply(A22, subtract(B21, B11), newsize);
	Matrix M5 = multiply(add(A11, A12), B22, newsize);
	Matrix M6 = multiply(subtract(A21, A11), add(B11, B12), newsize);
	Matrix M7 = multiply(subtract(A12, A22), add(B21, B22), newsize);
	
	Matrix C11 = add(subtract(add(M1, M4), M5), M7);
	Matrix C12 = add(M3, M5);
	Matrix C21 = add(M2, M4);
	Matrix C22 = add(add(subtract(M1, M2), M3), M6);
	
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

void input_matrix(Matrix &A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
}

int main() {
	
	int n;
	cin >> n;
	Matrix A(n, vector<int>(n, 0));
	Matrix B(n, vector<int>(n, 0));
	
	input_matrix(A, n);
	input_matrix(B, n);
	
	Matrix C = multiply(A, B, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}