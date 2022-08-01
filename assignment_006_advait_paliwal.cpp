#include <iostream>

using namespace std;

int sum1(int number);
int sum2(int number);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int operations1 = n - 1;
    int operations2 = 3;
    cout << "Looping\n" << "Sum: " << sum1(n) << "\nOperations: " << operations1 << endl;
    cout << "Formula\n" << "Sum: " << sum2(n) << "\nOperations: " << operations2 << endl;
    return 0;
}

int sum1(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number;
        number -= 1;
    }
    return sum;
}

int sum2(int number) {
    int sum = (number*(number + 1))/2;
    return sum;
}