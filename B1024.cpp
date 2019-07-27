#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std; 
int main() {
	string s;
	cin >> s;
	int i = 0;
	while (s[i] != 'E') i++;
	string t = s.substr(1, i-1);
	int n = stoi(s.substr(i+1));
	if(s[0] == '-') cout << "-";
	if(n < 0) {
		
	}
	return 0;
} 
