#include <iostream>
#include <string>
using namespace std;
int n;
string deal(string s, int& e) {
    int k = 0;
	while (s.length() > 0 && s[0] == '0') {
		// 去掉s的前导0 
		s.erase(s.begin());
	}	
	// 去掉前导0之后是小数点 说明s是小于1的 
	if (s[0] == '.') {
		// 去掉小数点 
		s.erase(s.begin()); 
		while (s.length() > 0 && s[0] == '0') {
			// 去掉小数点后非零位前的所有零 
			s.erase(s.begin());
			e--; 
		}
	} else {// s大于1的情况 
		while (k < s.length() && s[k] != '.') { // 寻找小数点 
			k++;
			e++; 
		}
		if (k < s.length()) { // 遇到了小数点 
		// 把小数点删除 
			s.erase(s.begin() + k); 
		}
	}
	// 去掉前导0之后长度为0 说明就是0 
	if (s.length()==0) {
		e = 0;
	} 
	int num = 0;
	k = 0;
	string res;
	
	while (num < n) {
		if (k < s.length()) res += s[k++];
		else res += '0';
		num++;
	}
	return res;
} 
int main() {
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	
	if (s3 == s4 && e1 == e2) {
		cout << "YES 0." <<s3<<"*10^"<<e1<<endl;
	} else {
		cout << "NO 0." <<s3<<"*10^"<<e1<<" 0." <<s4<<"*10^"<<e2<<endl;
	}
	return 0;
}
