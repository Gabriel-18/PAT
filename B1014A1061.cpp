#include<cstdio>
#include<cstring>
int main() {
	char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	char str1[70], str2[70], str3[70], str4[70];
	
	fgets(str1, 70, stdin);
	fgets(str2, 70, stdin);
	fgets(str3, 70, stdin);
	fgets(str4, 70, stdin);
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	
	int i;
	//一个星期7天
	//A B C D E F G 
	for(i = 0; i < len1 && i < len2; i++ ){
		if(str1[i] == str2[i] && str1[i] >='A' && str2[i] <= 'G') {
			printf("%s ", week[str1[i] - 'A']);
			break;
		}
	}
	//0 - 9 A - N  题目给的信息 
	for(i++ ; i < len1 && i < len2; i++ ){
		if(str1[i] == str2[i]) {
			if(str1[i] >= '0' && str2[i] <= '9') {
				printf("%02d:", str1[i] - '0');
				break;
			} else if (str1[i] >= 'A' && str1[i] <= 'N' ) {
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			}
		}
	}	
	
	for(i = 0; i < len3 && i < len4; i++) {
		if(str3[i] == str4[i]) {
			if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z')) {
				printf("%02d", i);
				break;
			}
		}
	}
	return 0;
} 
