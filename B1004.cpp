#include<cstdio>
struct  stu {
	// ��С�������10 ��Ҫ��һλ�����ַ� 
	char name[12];
	char id[12];
	int score;
}temp, ans_max, ans_min;
int main() {
	int n;
	scanf("%d", &n);
	ans_max.score = -1;
	ans_min.score = 101;
	for(int i = 0; i < n; i++) {
		scanf("%s%s%d", &temp.name, &temp.id, &temp.score);
		if(temp.score > ans_max.score) {
			ans_max = temp;
		}
		if(temp.score < ans_min.score) {
			ans_min = temp;
		}
 	}
 	
 	printf("%s %s\n", ans_max.name, ans_max.id);
 	printf("%s %s\n", ans_min.name, ans_min.id);
	return 0;
}
