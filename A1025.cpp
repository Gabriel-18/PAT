#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student {
	char id[15];
	int score;
	int location_number;
	int local_rank;
}stu[30010];
bool cmp(Student a, Student b) {
	if (a.score != b.score) return a.score > b.score; // 分数由高到低 
	else return strcmp(a.id, b.id) < 0; //  分数相同 按准考证排 
} 

int main() {
	int n, k, num = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%s %d", &stu[num].id, &stu[num].score);
			stu[num].location_number = i; // 该考生的考厂号i 
			num++; //考生总数 
		}
		// 当前考场排序  当前考察区间为 num - k , num
		sort(stu + num - k, stu + num, cmp); 
		// 把当前考场第一名设置为1 
		stu[num - k].local_rank = 1;
		
		// 处理该考场剩下的考生 
		for (int j = num - k + 1; j < num; j++) {
			if (stu[j].score == stu[j - 1].score) {
				stu[j].local_rank = stu[j-1].local_rank;
			} else {
				stu[j].local_rank = j + 1 - (num - k);
			}
		} 
	}
	
	//处理总体 
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;
	
	for (int i = 0;i < num; i++) {
		if (i > 0 && stu[i].score != stu[i - 1].score) {
			r = i + 1;
		}
		
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
} 
