#include<iostream>
using namespace std;

const int size = 10;
int a1[size] = {1,3,7,5,2,4,6,8,9,10};
int a2[size] = {10,9,8,7,6,5,4,3,2,1};
int a3[size] = {1,10,2,9,3,8,4,7,5,6};

void sort(int a[]);
int main()
{
    sort(a1);
    sort(a2);
    sort(a3);
    return 0;
}

void print_a(int a[]) {
    cout << " (";
    for (int k = 0; k <=(size - 2); k++) {
        cout << a[k] << ",";
    }  
    cout << a[size - 1] << ") ";
}

void sort(int a[]) {
    int actions = 0;
    for(int i=0; i<(size-1); i++) {
        for(int j=0; j<(size-i-1); j++) {
          actions ++;
          if(a[j]>a[j+1]) {
              int temp = a[j];
              a[j] = a[j+1];
              a[j+1] = temp;
              actions +=2;
          }
        }
    }
    cout << "Sorted List:";
    print_a(a);
    cout << actions << " Actions Performed." << endl;
}