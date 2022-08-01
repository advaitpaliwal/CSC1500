#include<iostream>
#include <string>

using namespace std;


void check(string input);


int main()
{   
    check("0001111");
    return 0;
}

void check(string str_input){
    int input = stoi(str_input);
    int array[7];
    for (int i = 6; i >= 0; i--) {
        array[i] = input % 10;
        input /= 10;
    }
    int s1 = array[0] + array[2] + array[4] + array[6];
    int s2 = array[1] + array[2] + array[5] + array[6];
    int s4 = array[3] + array[4] + array[5] + array[6];
    int corrupted = (s1 % 2) + (2 * (s2 % 2)) + (4 * (s4 % 2));
    if (corrupted){
        cout << "Original input: " << str_input << endl;
        cout << "Incorrect bit at place " << corrupted << endl;
        array[corrupted-1] = !array[corrupted-1];
        cout << "Corrected code: ";
        for (int i = 0; i < 7; i++) {
            cout << array[i];
        }
        cout << endl;
    }
    else {
        cout << "Not incorrect" << endl;
    }
    cout << "Decimal value: " << (8 * array[2]) + (4 * array[4]) + (2 * array[5]) + array[6] << endl << endl;
}
