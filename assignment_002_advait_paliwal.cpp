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
  string arr[5] = {"((A && B)||(A && C))", "((A && C) && (B && !C))", "((A || B) && !(B || C))", "((A || (B && C)) && (!A && !B))", "(((B && C) || (C && A)) && (!(A || B) && C))"};
  for (int i = 0; i<=4; i++){
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
  int q1 = ((A && B)||(A && C));
  int q2 = ((A && C) && (B && !C));
  int q3 = ((A || B) && !(B || C));
  int q4 = ((A || (B && C)) && (!A && !B));
  int q5 = (((B && C) || (C && A)) && (!(A || B) && C));
  int arr[5] = {q1, q2, q3, q4, q5};
  cout <<  " " << (arr[i] ? "T" : "F") << endl;
}