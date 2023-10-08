#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<vector<int>> A = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}}; 

vector<vector<int>> B = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}}; 


vector<vector<int>> MatrixHadaM(const vector<vector<int>> &A, const vector<vector<int>> &B){
    int m = A.size();
    int n = B[0].size();
    vector<vector<int>> C(m, vector<int>(n));

    // Hadamard product, 逐元素乘积
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            C[i][j] = A[i][j] * B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return C;
}


vector<vector<int>> MatrixDotM(const vector<vector<int>> &A, const vector<vector<int>> &B){
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> D(m, vector<int>(n));

    // Dot product, 矩阵点乘，标准矩阵相乘
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            D[i][j] = 0;
            for(int k = 0; k < 3; ++k){
                D[i][j] += A[i][k] * B[k][j];
            }
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    return D;
}


vector<vector<int>> operator*(const vector<vector<int>> &A, const vector<vector<int>> &B){
    return MatrixHadaM(A, B);
}



int main(){
    vector<vector<int>> C;
    C = MatrixHadaM(A, B);
    cout << endl;
    C = MatrixDotM(A, B);
    cout << endl;

    C = A * B;

    return 1;
}