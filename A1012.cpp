#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct Student{
	int id; // ��λ���� 
	int grade[4];
} stu[2010];
char course[4] = {'A', 'C', 'M', 'E'};
//������λ 
int rank[1000000][4] = {0}; // �γ����� 
int now;

bool cmp(Student a, Student b) {
	return a.grade[now] > b.grade[now]; // stu���鰴now�ųɼ����������� 
}
int main()  {
	int n, m;
	scanf("%d%d", &n, &m);
	
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
	}
	
	for(now = 0; now < 4; now++) {
		sort(stu, stu + n, cmp);
		rank[stu[0].id][now] = 1; // ������ɺ���߷ֵ����ó�rank1
		for (int i = 1; i < n; i++) { // ʣ�µĿ��� 
			if (stu[i].grade[now] == stu[i - 1].grade[now]) { // ��ǰһλ������ͬ 
				rank[stu[i].id][now] = rank[stu[i - 1].id][now];
			} else {
				rank[stu[i].id][now] = i + 1; // ��ȷ���� 
			}
		} 
	}
	
	int query; // ����ѯid 
	for (int i = 0; i < m; i++) {
		scanf("%d", &query);
		if (rank[query][0] == 0) {
			printf("N/A\n");
		} else {
			int k = 0;
			for (int j = 0; j < 4; j++) {
				if (rank[query][j] < rank[query][k]) { // �ҳ���С�� 
					k = j;
				}
			}
			printf("%d %c\n", rank[query][k], course[k]);
		}
	}
	return 0;
}
