#include "header.h"

int searchstring(char* filename) {
	FILE *fp;
	int count = 0;
	int size;
	char *search;
	char *buffer = (char*)calloc(200, sizeof(char));
	char path[100] = "..\\dataset\\";

	strcat(path, filename);

	fp = fopen(path, "rt"); // 파일 스트림 생성

	if (fp == NULL) {
		printf("파일오픈 실패!\n");
		return -1;
	}

	/*파일 크기만큼 buffer에 메모리 할당*/
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buffer = (char*)calloc(size + 5, 1);
	
	fread(buffer, sizeof(char), size + 1, fp); //파일 내용 불러오기

	strlwr(buffer); // 대소문자 구분을 없애기 위해 모두 소문자로 전환
	strlwr(word);

	/*문자열 검색*/
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