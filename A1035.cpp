#include<cstdio>
#include<cstring>
struct node {
	char name[11], password[11];
	bool change;
}T[1005];
//参数使用引用 可以对传入参数进行修改 
void crypt(node& t, int& cnt) {
	int len = strlen(t.password);
	// 题目给的条件 
	for (int i = 0; i < len; i++) {
		if (t.password[i] == '1') {
			t.password[i] = '@';
			t.change = true;
		} else if (t.password[i] == '0') {
			t.password[i] = '%';
			t.change = true;
		} else if (t.password[i] == 'l') {
			t.password[i] = 'L';
			t.change = true;
		} else if (t.password[i] == 'O') {
			t.password[i] = 'o';
			t.change = true;
		}
	}
	// 统计修改次数 
	if (t.change == true) {
			cnt++;
	} 
}
int main() {
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", T[i].name, T[i].password);
		T[i].change = false;
	}
	for (int i = 0; i < n; i++) {
		crypt(T[i], cnt);
	}
	
	if(cnt == 0) {
		// 注意单复数 
		if (n == 1) {
			printf("There is %d account and no account is modified",n);
		} else {
			printf("There are %d accounts and no account is modified",n);
		}
	} else {
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++) {
			if (T[i].change == true) {
				printf("%s %s\n", T[i].name, T[i].password);
			}
		}
	
	} 
	return 0;
}
