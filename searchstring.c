#include "header.h"

int searchstring(char* filename) {
	FILE *fp;
	int count = 0;
	int size;
	char *search;
	char *buffer = (char*)calloc(200, sizeof(char));
	char path[100] = "..\\dataset\\";

	strcat(path, filename);

	fp = fopen(path, "rt"); // ���� ��Ʈ�� ����

	if (fp == NULL) {
		printf("���Ͽ��� ����!\n");
		return -1;
	}

	/*���� ũ�⸸ŭ buffer�� �޸� �Ҵ�*/
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buffer = (char*)calloc(size + 5, 1);
	
	fread(buffer, sizeof(char), size + 1, fp); //���� ���� �ҷ�����

	strlwr(buffer); // ��ҹ��� ������ ���ֱ� ���� ��� �ҹ��ڷ� ��ȯ
	strlwr(word);

	/*���ڿ� �˻�*/
	while (1) {
		search = strstr(buffer, word);

		if (search != NULL) {
			count++;
			buffer = search + 1;
		}

		else {
			fclose(fp);
			return count;
		}
	}
}