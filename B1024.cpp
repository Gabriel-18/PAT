#include<cstdio>
#include<cstring>
int main() {
	char str[10010];
	fgets(str, 10010, stdin);
	int len = strlen(str);
	//����ת�� 
	if(str[0] == '-') printf("-");
	
	// ��λE��λ�� 
	int pos = 0;
	while(str[pos] != 'E') {
		pos++;
	}
	// exp���ָ�� 
	int exp = 0;
	//+   ���������0  ����λ�� 
	for(int i = pos + 2; i < len; i++) {
		exp = exp * 10 + (str[i] - '0');
	}
	// ���⴦�� ָ��Ϊ0����� 
	if(exp == 0) {
		for(int i = 1; i < pos; i++) 
			printf("%c", str[i]);
	}
	
	if(str[pos + 1] == '-') { // ָ��Ϊ������� 
		printf("0.");
		for(int i = 0; i < exp - 1; i++) { // exp - 1 ���� 
			printf("0");
		}
		printf("%c", str[1]);//�����һ���� 
		for(int i = 3; i < pos; i++) { //-x.xxx ���С������������ 
			printf("%c", str[i]);
		}
	} else { //ָ��Ϊ�� 
		for (int i = 1; i < pos; i++) { //  
			if (str[i] == '.') { //�Թ�С���� 
				continue;
			}
			// ���С���������� 
			printf("%c", str[i]);
			
			//С����Ҫ���� exp + 2 2����С����ǰ���������� 
			 //  
			if (i == exp + 2 && pos - 3 != exp) {
				printf(".");
			}
		}
		// �������0 
		for (int i = 0; i < exp - (pos - 3); i++) {
			printf("0");
		}
	}
	return 0;
} 
