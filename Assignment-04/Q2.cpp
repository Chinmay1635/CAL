#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;


Matrix add(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix sub(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

Matrix strassen(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int k = n/2;

    Matrix A11(k, vector<int>(k)), A12(k, vector<int>(k)),
           A21(k, vector<int>(k)), A22(k, vector<int>(k));
    Matrix B11(k, vector<int>(k)), B12(k, vector<int>(k)),
           B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }
    }

    Matrix M1 = strassen(add(A11,A22), add(B11,B22));
    Matrix M2 = strassen(add(A21,A22), B11);
    Matrix M3 = strassen(A11, sub(B12,B22));
    Matrix M4 = strassen(A22, sub(B21,B11));
    Matrix M5 = strassen(add(A11,A12), B22);
    Matrix M6 = strassen(sub(A21,A11), add(B11,B12));
    Matrix M7 = strassen(sub(A12,A22), add(B21,B22));


    Matrix C11 = add(sub(add(M1, M4), M5), M7);
    Matrix C12 = add(M3, M5);
    Matrix C21 = add(M2, M4);
    Matrix C22 = add(sub(add(M1, M3), M2), M6);

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            C[i][j] = C11[i][j];
            C[i][j+k] = C12[i][j];
            C[i+k][j] = C21[i][j];
            C[i+k][j+k] = C22[i][j];
        }
    }

    return C;
}

int main() {
    int n = 3;
    Matrix A(4, vector<int>(4, 0));
    Matrix B(4, vector<int>(4, 0));

    cout << "Enter 3x3 Matrix A:\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> A[i][j];

    cout << "Enter 3x3 Matrix B:\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> B[i][j];

    Matrix C = strassen(A, B);

    cout << "Resultant 3x3 Matrix:\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
