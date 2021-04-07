#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

int strlen(char * what) {
	int len;
	for (len = 0; what[len] != NULL; len++);
	return len;
}

void strcpy(char* first, char* second) {
	int len_second=0;
	for (len_second = 0; second[len_second] != NULL; len_second++) {
		first[len_second] = second[len_second];
	}
	first[len_second] = NULL;
}

void strncpy(char* first, char* second,int num) {
	bool over=false;
	int len_second = 0;
	int temp = 0;
	for (len_second = 0; second[len_second] != NULL && len_second < num; len_second++) {
		if (first[len_second] == NULL) over=true;
		first[len_second] = second[len_second];
	}
	if (over) first[len_second] = NULL;
}

int strcmp(char* first, char* second) {
	int def=0;
	for (int i = 0; first[i] != NULL || second[i] != NULL;i++) {
		if (first[i] == NULL || first[i] < second[i]) {
			def = -1;
			break;
		}
		else if (second[i] == NULL || first[i] > second[i]) {
			def = 1;
			break;
		}
	}
	return def;
}

int strncmp(char* first, char* second, int num) {
	int def = 0;
	for (int i = 0; i<num && (first[i] != NULL || second[i] != NULL); i++) {
		if (first[i] == NULL|| first[i] < second[i]) {
			def = -1;
			break;
		}
		else if (second[i] == NULL|| first[i] > second[i]) {
			def = 1;
			break;
		}
	}
	return def;
}

char* strchr(char* first, char second) {
	char* temp=NULL;
	int exist=0;
	int where = 0;
	for (where = 0; first[where] != NULL; where++) {
		if (first[where] == second) {
			exist = 1;
			break;
		}
	}
	
	if (exist == 1) {
	temp = first+where;
	}
	return temp;
}

char* strrchr(char* first, int second) {
	int exist = 0;
	int where = 0;
	for (where = 0; first[where] != NULL; where++) {
		if (first[where] == second) {
			exist = 1;
			break;
		}
	}
	
	if (exist == 1)	return first+where;
	else return NULL;
}

void strcat(char* first, char* second) {
	int len;
	for (len = 0; first[len] != NULL; len++);
	for (int i = 0; second[i] != NULL; i++) {
		first[len++] = second[i];
	}
	first[len] = NULL;
}

void strncat(char* first, char* second, int num) {
	int len;
	for (len = 0; first[len] != NULL; len++);
	for (int i = 0; second[i] != NULL && i < num; i++) {
		first[len++] = second[i];
	}
	first[len] = NULL;
}
char* strstr(char* first, char* second) {
	char* temp=NULL;
	int exist = 0;
	int len = 0;
	int where = 0;
	for (int i = 0; first[i] != NULL; i++) {
		if (first[i] == second[len]) {
			if (where == 0)where = i;
			len++;
			exist = 1;
			if (second[len] == NULL) {
				break;
			}
			else if (first[i + 1] == NULL && second[len] != NULL) {
				where = 0;
				exist = 0;
				break;
			}
		}
		else {
			where = 0;
			exist = 0;
		}
		
	}
	if (exist == 1) {
		int i = 0;
		temp = first+where;
	}
	return temp;
}

void clear(char* first, char* second) {
	int temp = 0;
	for (temp = 0; second[temp] != NULL; temp++) {
		first[temp] = second[temp];
	}
	first[temp] = NULL;
}

void main() {
	char a[100];
	char b[50];
	int choice=0;
	int n=0;
	char c;
	char* exist;
	char temp_a[100]="";
	char temp_b[100]="";
	printf("�Է��ϰ� ���� ���ڿ� a�� �Է��ϼ���\n");
	scanf("%s", a);
	printf("�Է��ϰ� ���� ���ڿ� b�� �Է��ϼ���\n");
	scanf("%s", b);
	strcpy(temp_a, a);
	strcpy(temp_b, b);
	while (1) {
		clear(a, temp_a);
		clear(b,temp_b);
		printf("\n\n������ �Ͻðڽ��ϱ�?\n1)strlen 2)strcpy 3)strnpy 4)strcmp 5)strncmp 6)strchr \
			\n7)strrchr 8)strcat 9)strncat 10)strstr 11)a�� ���� 12)b�� ���� 13) ��  : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("\na�� ���� : %d", strlen(a));
			printf("\nb�� ���� : %d", strlen(b));
			break;
		case 2:
			strcpy(a, b);
			printf("\n�ٲ� a�� %s �Դϴ�.", a);
			break;

		case 3:
			printf("\n�ٲٰ� ���� N�� �Է��ϼ���\n");
			scanf("%d", &n);
			strncpy(a, b, n);
			printf("�ٲ� a�� %s �Դϴ�.", a);
			break;
		case 4:
			if(strcmp(a, b)<0) printf("\na�� �� ���� �����ϴ�.");
			else if (strcmp(a, b) > 0) printf("\nb�� �� ���� �����ϴ�.");
			else if (strcmp(a, b) == 0) printf("\n�ΰ��� �����ϴ�.");
			break;
		case 5:
			printf("\n�ٲٰ� ���� N�� �Է��ϼ���\n");
			scanf("%d", &n);
			if (strncmp(a, b,n) < 0) printf("\na�� �� ���� �����ϴ�.");
			else if (strncmp(a, b,n) > 0) printf("\nb�� �� ���� �����ϴ�.");
			else if (strncmp(a, b,n) == 0) printf("\n�ΰ��� �����ϴ�.");
			break;
		case 6:
			printf("\n���ϰ� ���� C�� �Է��ϼ���\n");
			scanf("%c", &c);
			scanf("%c", &c);
			exist= strchr(a, c);
			if (exist != NULL)printf("\nã�� �� ���ڿ��� %s �Դϴ�.", exist);
			else printf("\nã�� ���߽��ϴ�.");
			break;
		case 7:
			printf("\n���ϰ� ���� C�� �Է��ϼ���\n");
			scanf("%c", &c);
			scanf("%c", &c);
			exist = strrchr(a, c);
			if (exist != NULL)printf("\nã�� ���ڴ� %d ��° �Դϴ�.", exist-a+1);
			else printf("\nã�� ���߽��ϴ�.");
			break;
		case 8:
			strcat(a, b);
			printf("\n�ٲ� a�� %s �Դϴ�.", a);
			break;
		case 9:
			printf("\n�ٲٰ� ���� N�� �Է��ϼ���\n");
			scanf("%d", &n);
			strncat(a, b,n);
			printf("\n�ٲ� a�� %s �Դϴ�.", a);
			break;
		case 10:
			exist=strstr(a, b);
			if (exist != NULL)printf("\nã�� �� ���ڿ��� %s �Դϴ�.", exist);
			else printf("\nã�� ���߽��ϴ�.");
			break;
		case 11:
			printf("\n�Է��ϰ� ���� ���ڿ� a�� �Է��ϼ���\n");
			scanf("%s", a);
			break;
		case 12:
			printf("\n�Է��ϰ� ���� ���ڿ� b�� �Է��ϼ���\n");
			scanf("%s", b);
			break;
		}
		if (choice == 13) break;
	}
	
}