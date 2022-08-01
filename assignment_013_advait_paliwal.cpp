#include<iostream>

using namespace std;

void mult(int a[][2], int b[][2]);
void mult2(int a[][2], int b);

int main()
{   
    int A[2][2] = {{2, 0},{4, 2}};
    int B[2][2] = {{1, 3},{2, 0}};
    int C[2][2] = {{1, 0},{0, 1}};
    cout << "Matrix A * Matrix B" << endl;
    cout << "-------------------" << endl;
    mult(A, B);
    cout << "Matrix B * Matrix A" << endl;
    cout << "-------------------" << endl;
    mult(B, A);
    cout << "Matrix C * Matrix B" << endl;
    cout << "-------------------" << endl;
    mult(C, B);
    cout << "2 * Matrix A" << endl;
    cout << "-------------------" << endl;
    mult2(A, 2);
    cout << "-4 * Matrix B" << endl;
    cout << "-------------------" << endl;
    mult2(B, -4);
    return 0;
}

void mult(int a[][2], int b[][2]){
    int m[2][2] =  {{0, 0},{0, 0}};
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                m[i][j] += a[i][k] * b[k][j];
            }
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void mult2(int a[][2], int b){
    int m[2][2] =  {{0, 0},{0, 0}};
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
                m[i][j] += a[i][j] * b;
                cout << m[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}