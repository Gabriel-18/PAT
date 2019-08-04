#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10010;
string str[maxn];
bool cmp(string a, string b) {
	return a + b < b + a; //���a + b < b + a�� �Ͱ�a����ǰ�� 
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	
	sort(str, str + n, cmp);
	string ans;
	for (int i = 0; i < n; i++) {
		ans += str[i]; // ���������ַ�������ƴ�� 
	}
	
	while (ans.size() != 0 && ans[0] == '0') {
		ans.erase(ans.begin()); // ȥ��ǰ��0 
	} 
	
	if (ans.size() == 0) cout << 0;
	else cout << ans; 
	return 0;
}
