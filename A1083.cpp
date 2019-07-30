#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100;
struct Student {
	char name[12];
	char id[12];
	int score;
}stu[maxn]; 
bool cmp(Student a, Student b) {
	return a.score > b.score;
} 
int main() {
	int n, left, right;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", &stu[i].name, &stu[i].id, &stu[i].score);
	}
	scanf("%d %d", &left, &right);
	sort(stu, stu + n, cmp);
	bool flag = false;
	
	for (int i = 0; i < n; i++) {
		if (stu[i].score >= left && stu[i].score <= right) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = true;
		}
	}
	
	if (flag == false) {
		printf("NONE\n");
	}
	return 0;
}
