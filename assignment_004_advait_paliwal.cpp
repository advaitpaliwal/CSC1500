#include <iostream>
#include <string>  

using namespace std;

void output();
void truthCombinations(int A, int B, int C, int D);

int main()
{
  output();
  return 0;
}

void output(){
    //A is Rocket
    //B is Astronaut
    //C is Highly Trained
    //D is Educated
    //D -> A is Conclusion
    cout << "A  B  C  D  A -> B  B -> C  C -> D  D -> A  Result" << endl;
    for (int a = 0; a<=1; a++){
      for (int b= 0; b<=1; b++) {
          for (int c= 0; c<=1; c++) {
            int d = 0;
            truthCombinations(a, b, c, d);
            truthCombinations(a, b, c, !d);
          }
      }
    }
    cout << endl;
}

void truthCombinations(int A, int B, int C, int D) {
  int p1 = !(A && !B);
  int p2 = !(B && !C);
  int p3 = !(C && !D);
  int c = !(D && !A);
  if (((p1 && p2 && p3) == 1) && c == 0) {
    cout << A << " ";
    cout << " " << B << " ";
    cout <<  " " << C << " ";
    cout <<  " " << D << " ";
    string p1_ = to_string(p1);
    string p2_ = to_string(p2);
    string p3_ = to_string(p3);
    string c_ = to_string(c);
    cout <<  " " << p1_ + "\t" +  "\t" + p2_ + "\t" +  "\t" + p3_ + "\t" +  "\t" + c_ + "\t" +  "\t" + "Invalid" << endl;
  }
}