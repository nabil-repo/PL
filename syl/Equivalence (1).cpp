#include <iostream>
using namespace std;

const int MAX=10;

bool isReflexive(int matrix[MAX][MAX], int n) {
    for (int i=0; i<n; ++i) {
        if (matrix[i][i] != 1) {
            return false;
        }
    }
    return true;
}

bool isSymmetric(int matrix[MAX][MAX], int n) {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (matrix[i][j]!=matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(int matrix[MAX][MAX], int n) {
    for (int i=0;i<n; ++i) {
        for (int j=0; j<n; ++j) {
            for (int k=0; k<n; ++k) {
                if (matrix[i][j] && matrix[j][k] && !matrix[i][k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isEquivalence(int matrix[MAX][MAX], int n) {
    return isReflexive(matrix, n) && isSymmetric(matrix, n) && isTransitive(matrix, n);
}

int main() {
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    int matrix[MAX][MAX];
    cout<<"Enter the matrix elements (0 or 1):\n";
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> matrix[i][j];
        }
    }
    if (isEquivalence(matrix, n)) {
        cout<<"The given matrix represents an equivalence relation.\n";
    } else {
        cout<<"The given matrix does not represent an equivalence relation.\n";
    }
    return 0;
}
