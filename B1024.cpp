#include<cstdio>
#include<cstring>
int main() {
	char str[10010];
	fgets(str, 10010, stdin);
	int len = strlen(str);
	//负数转正 
	if(str[0] == '-') printf("-");
	
	// 定位E的位置 
	int pos = 0;
	while(str[pos] != 'E') {
		pos++;
	}
	// exp存放指数 
	int exp = 0;
	//+   还有起点是0  右移位数 
	for(int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	// 特殊处理 指数为0的情况 
	if(exp == 0) {
		for(int i = 1; i < pos; i++) 
			printf("%c", str[i]);
	}
	
	if(str[pos + 1] == '-') { // 指数为负的情况 
		printf("0.");
		for(int i = 0; i < exp - 1; i++) { // exp - 1 个零 
			printf("0");
		}
		printf("%c", str[1]);//输出第一个数 
		for(int i = 3; i < pos; i++) { //-x.xxx 输出小数点后面的数字 
			printf("%c", str[i]);
		}
	} else { //指数为正 
		for (int i = 1; i < pos; i++) { //  
			if (str[i] == '.') { //略过小数点 
				continue;
			}
			// 输出小数点后面的数 
			printf("%c", str[i]);
			
			//小数点要右移 exp + 2 2代表小数点前面两个东西 
			 //  
			if (i == exp + 2 && pos - 3 != exp) {
				printf(".");
			}
		}
		// 额外输出0 
		for (int i = 0; i < exp - (pos - 3); i++) {
			printf("0");
		}
	}
	return 0;
} 
