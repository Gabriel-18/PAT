#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Person {
	char name[10];
	int age, worth;
}ps[maxn], valid[maxn];
bool cmp(Person a, Person b) {
	if (a.worth != b.worth) return a.worth > b.worth; // 从大到小 
	else if (a.age != b.age) return a.age < b.age; // 从小到大
	return strcmp(a.name, b.name) < 0; 
}

int Age[maxn] = {0};
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", &ps[i].name, &ps[i].age, &ps[i].worth);
	}
	sort(ps, ps + n, cmp);
	
	int validNum = 0;
	// 存储每个年龄段前100名 
	for (int i = 0; i < n; i++) {
		if (Age[ps[i].age] < 100) {
			Age[ps[i].age]++;
			// 年龄无序 
			valid[validNum++] = ps[i];
		}
	}
	
	int m, ageL, ageH;
	
	for (int i = 1; i <= k; i++) {
		scanf("%d %d %d", &m, &ageL, &ageH);
		printf("Case #%d:\n", i);
		int printNum = 0;
		// 在小范围查找 
		for (int j = 0; j < validNum && printNum < m; j++) {
			if (valid[j].age >= ageL && valid[j].age <= ageH) {
				printf("%s %d %d\n", valid[j].name,valid[j].age, valid[j].worth);
				printNum++;
			}
		}
		if (printNum == 0) {
				printf("None");
			}
	} 
	return 0;
}
