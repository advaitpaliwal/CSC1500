#include<iostream>
#include <string>

using namespace std;

void deal();
int check_suit(string input, int total);
float get_odds(string arr[], int total);

int main()
{   
    deal();
    return 0;
}

void deal(){
    string arr[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
    string conclusion;
    srand(time(0));
    int r1 = (rand() % 12) + 0;
    int r2 = (rand() % 12) + 0;
    cout << "First card: " << arr[r1] << endl;
    cout << "Second card: " << arr[r2] << endl;
    int value_1 = check_suit(arr[r1], 0);
    int value_2 = check_suit(arr[r2], 0);
    arr[r1] = "0";
    arr[r2] = "0";
    int total = value_1 + value_2;
    float detrimential = get_odds(arr, total);
    if (detrimential > 0.50) {
        conclusion = "No";
    } else {
        conclusion = "Yes";
    }
    cout << "Odds of detrimential card: " << detrimential << endl;
    cout << "Odds of beneficial card: " << 1- detrimential << endl;
    cout << "Deal another card? " << conclusion << endl;
}

int check_suit(string input, int total){
    if (input == "J" || input == "Q" || input == "K"){
        return 10;
    } else if (input == "A"){
        if (total > 10){
            return 1;
        }
        return 11;
    }
    return stoi(input);
}


float get_odds(string arr[], int total){
    float detrimental = 0.0;
    for (int i = 0; i < 13; i++) {
        int amount = check_suit(arr[i], total);
        if (total + amount > 21){
            detrimental+=1;
        }
    }
    float odds = detrimental/11.0;
    return odds;
}