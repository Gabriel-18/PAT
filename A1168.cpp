//
// Created by kelper on 2020/8/24.
//
#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
     string s;
     cin >> s;
     int flag = 0;
    for (int i = 0; i < s.size(); ++i) {
        string s1 = s.substr(i);
        int num = stoi(s1);
//        cout << s1 << " " << num << endl;


        if (isPrime(num)) {
            cout << s1 << " " << "Yes" << endl;
        } else {
            cout << s1 << " " << "No" << endl;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "All Prime!" << endl;
    }
    return 0;
}