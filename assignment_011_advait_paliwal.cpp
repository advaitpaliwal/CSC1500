#include<iostream>
#include <string>

using namespace std;

void transmit(int input);

int main()
{   
    transmit(15);
    transmit(7);
    transmit(12);
    transmit(2);
    transmit(6);
    return 0;
}

void transmit(int dec_input){
    cout << "Original Decimal: " << dec_input << endl;
    int array[7];
    array[6] = dec_input % 2;
    dec_input /= 2;
    array[5] = dec_input % 2;
    dec_input /= 2;
    array[4] = dec_input % 2;
    dec_input /= 2;
    array[2] = dec_input % 2;
    array[0] = (array[2] + array[4] + array[6]) % 2;
    array[1] = (array[2] + array[5] + array[6]) % 2;
    array[3] = (array[4] + array[5] + array[6]) % 2;
    cout << "Hamming Code: ";
    for (int i = 0; i < 7; i++) {
        cout << array[i];
    }
    cout << endl << endl;
}