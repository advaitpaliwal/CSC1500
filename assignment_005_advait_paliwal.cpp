#include <iostream>
#include <string>  

using namespace std;

string  conversion(int number, int base);

int main()
{
    cout << "A: 15, base 2" << endl;
    cout << conversion(15, 2) << endl << endl;
    cout << "B: 38, base 16" << endl;
    cout << conversion(38, 16) << endl << endl;
    cout << "C: 54, base 6" << endl;
    cout << conversion(54, 6) << endl << endl;
    cout << "D: 19, base 8" << endl;
    cout << conversion(19, 8) << endl << endl;
    cout << "E: 27, base 3" << endl;
    cout << conversion(27, 3) << endl << endl;
    return 0;
}

string conversion(int number, int base) {
    string binary = "";
    while (number > 0) {
        string remainder = to_string(number % base);
        number /= base;
        binary = remainder + binary;
    }
    return binary;
}