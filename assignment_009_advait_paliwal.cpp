#include<iostream>
#include <vector>
using namespace std;

vector<int> get_union(vector<int> a, vector<int> b);
vector<int> get_intersect(vector<int> a, vector<int> b);
vector<int> get_inverse(vector<int> b);
vector<int> get_difference(vector<int> a, vector<int> b);
void output(vector<int> answer, string a);

int main()
{
    vector<int> A = {1,2,3,4,5,6,7,8,9,10};
    vector<int> B = {2,4,6,8,10};
    vector<int> C = {1,3,5,7,9};
    vector<int> D = {1,2,3,5,7};
    vector<int> answer;
    cout << "Problem 1) A ∩ D" << endl;
    answer = get_intersect(A, D);
    output(answer, "elements");
    cout << "Problem 2) ( B ∪ C ) ∩ A" << endl; 
    answer = get_intersect(get_union(B, C), A);
    output(answer, "elements");
    cout << "Problem 3) (!C  ∪ C)  ∩ A" << endl; 
    answer = get_intersect(get_union(get_inverse(C), C), A);
    output(answer, "elements");
    cout << "Problem 4) A – D" << endl; 
    answer = get_difference(A, D);
    output(answer, "elements");
    cout << "Problem 5) N(!A  ∪ ( C  ∪ D))" << endl; 
    answer = get_union(get_inverse(A), get_union(C, D));
    output(answer, "size");
    cout << "Problem 6) D  ∩ C" << endl; 
    answer = get_intersect(D, C);
    output(answer, "elements");
    cout << "Problem 7) N(B  ∩ C)" << endl; 
    answer = get_intersect(B, C);
    output(answer, "size");
    cout << "Problem 8) A  ∪ B  ∪ C  ∪ D" << endl; 
    answer = get_union(get_union(get_union(A, B), C), D);
    output(answer, "elements");
    return 0;
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

vector<int> get_difference(vector<int> a, vector<int> b) {
    vector<int> u;
    for (int i = 0; i < a.size(); i++) {
        bool equal = false;
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                equal = true;
                break;
            }
        } 
        if (!equal) {
            u.push_back(a[i]);
        }
    }
    return u;
}

vector<int> get_inverse(vector<int> b) {
    vector<int> u;
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    int i = 0;
    int j = 0;
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
}