#include <iostream>

using namespace std;

void output();
void truthCombinations(int A, int B, int C, int i);

int main()
{
  output();
  return 0;
}

void output(){
  string arr[4] = {"(A nor C) xor B", "(B implies C) nand (A nor B)", "(A xor B) implies (B xnor C)", "(A implies B) implies !C"};
  for (int i = 0; i<=3; i++){
    cout << arr[i] << endl;
    cout << "A" << "  ";
    cout << "B" << "  ";
    cout << "C" << "  ";
    cout << "Result" << endl;
    for (int a = 0; a<=1; a++){
      for (int b= 0; b<=1; b++) {
          int c = 0;
          truthCombinations(a, b, c, i);
          truthCombinations(a, b, !c, i);
      }
    }
    cout << endl;
  }
}

void truthCombinations(int A, int B, int C, int i) {
  cout << A << " ";
  cout << " " << B<< " ";
  cout <<  " " << C << " ";
  int q1 = (!(A || C) ^ B);
  int q2 = !(!(B && !C) && !(A || B));
  int q3 = !((A ^ B) && !(!(B ^ C)));
  int q4 = !(!(A && !B) && C);
  int arr[4] = {q1, q2, q3, q4};
  cout <<  " " << (arr[i] ? "T" : "F") << endl;
}