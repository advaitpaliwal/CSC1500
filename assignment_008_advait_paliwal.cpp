#include<iostream>
using namespace std;

string encrypt(string input, int shift);
void output(string input);

int main()
{
    output("Wkh qljkw lv orqj dqg zh doo suhwhqg wr vohhs");
    output("F xrfqq hnyd mfx gjjs inxhtajwji zsijw ymj gtbqnsl fqqjd");
    output("Yx Drebcnki dro vslbkbi gsvv lo exuxygklvo");
    output("Epht bsf opu bmmpxfe jo uif eph qbsl");
    output("Jrypbzr gb Avtug Inyr");
    return 0;
}

void output(string input){
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
