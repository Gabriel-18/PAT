#include<cstdio>
int main() {
	int count[10];//记录0 - 9的个数 
	for (int i = 0; i < 10; i++) {
		scanf("%d", &count[i]);
	}
	
	for (int i = 1; i < 10; i++) { //1 - 9 中开始挑选 
		if (count[i] > 0) {
			printf("%d", i);
			count[i]--;
			break;
		}
	}
	
	
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d", i);
		}
	}
	return 0;
} 
