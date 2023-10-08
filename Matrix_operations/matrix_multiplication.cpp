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

vector<vector<int>> C;
vector<vector<int>> D;

int main(){
    C.reserve(3 * 3 * sizeof(int));
    C.resize(3, vector<int>(3));
    D.reserve(3 * 3 * sizeof(int));
    D.resize(3, vector<int>(3));

    // Hadamard product, 逐元素乘积
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            C[i][j] = A[i][j] * B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;

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
    return 1;
}