#include<iostream>
#include <vector>
using namespace std;

string encrypt(string input, int shift);
string conversion(int number, int base);
void decrept_output(string input);
void transmit(int input);
void receive(string input);
vector<int> get_union(vector<int> a, vector<int> b);
vector<int> get_intersect(vector<int> a, vector<int> b);
void output(vector<int> answer, string a);
void truthCombinations(int A, int B, int C);

int main()
{
    vector<int> A = {1,2,3,5,8,13};
    vector<int> B = {1,3,5,7,9,11,13,15,17,19};
    vector<int> C = {1,2,3,5,7,11,13,17,19};
    vector<int> answer;
    decrept_output("Lo cebo dy nbsxu iyeb Yfkvdsxo");
    cout << conversion(871, 7) << endl << endl;
    transmit(12);
    receive("0111101");
    answer = get_intersect(get_union(A, B), C);
    output(answer, "elements");
    for (int a = 0; a<=1; a++){
      for (int b= 0; b<=1; b++) {
          int c = 0;
          truthCombinations(a, b, c);
          truthCombinations(a, b, !c);
      }
    }
    return 0;
}

void decrept_output(string input){
    for (int i = 0; i < 26; i++) {
        cout << i << " " << encrypt(input, i) << endl;
    }
    cout << endl;
}

string encrypt(string input, int shift) {
    string encrypted = "";
    while (shift >= 26) {
        shift-=26;
    }
    for (int i = 0; i <input.length(); i++) {
        if (islower(input[i])) {
            encrypted += char((input[i] + shift - 97) % 26 + 97);
        } else if (isupper(input[i])) {
            encrypted += char((input[i] + shift - 65) % 26 + 65);
        }
        else {
            encrypted += input[i];
        }
    }  
    return encrypted;
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

void receive(string str_input){
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


vector<int> get_union(vector<int> a, vector<int> b) {
    vector<int> u;
    int i = 0;
    int j = 0;
    int k = 0;
    int aSize = a.size();
    int bSize = b.size();
    while (i < aSize && j < bSize) {
        if (a[i] < b[j]) {
            u.push_back(a[i]);
            i++;
        }
        else if (b[j] < a[i]) {
            u.push_back(b[j]);
            j++;
        }
        else {
            u.push_back(b[j]);
            i++;
            j++;
        }
    }

    while (i < aSize) {
        u.push_back(a[i]);
        i++;
        k++;
    }
    while (j < bSize) {
        u.push_back(b[j]);
        j++;
    }
    return u;
        
}

vector<int> get_intersect(vector<int> a, vector<int> b) {
    vector<int> u;
    int i = 0;
    int j = 0;
    int aSize = a.size();
    int bSize = b.size();
    while (i < aSize && j < bSize) {
        if (a[i] < b[j]) {
            i++;
        }
        else if (b[j] < a[i]) {
            j++;
        }
        else {
            u.push_back(b[j]);
            i++;
            j++;
        }
    }
    return u;
}

void output(vector<int> answer, string a) {
    if (answer.size() == 0){
        cout << "E" << " ";
        cout << endl;
    } else {
        if (a == "elements"){
            for (int i = 0; i < answer.size(); i++) {
                cout << answer[i] << " ";
                }
            cout << endl;
        } else if (a == "size"){
            cout << answer.size() << " ";
            cout << endl;
        }
    }
    cout << endl;
}


void truthCombinations(int A, int B, int C) {
  cout << A << " ";
  cout << " " << B<< " ";
  cout <<  " " << C << " ";
  int q = !(!((A ^ B) && (A || C)));
  cout <<  " " << (q ? "T" : "F") << endl;
}