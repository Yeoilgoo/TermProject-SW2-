#include "header.h"

int main(int argc, char *argv[]) {
	int count = 0;

	/*검색 키워드 입력*/
	strcpy(word, argv[1]);

	findfile();

	/*결과 출력*/
	while (head != NULL) {
		printf("파일명 : %s, 키워드 개수 : %d \n", head->filename, head->num);
		count++;

		head = head->next;
	}

	printf("\n키워드 %s를 포함하고 있는 %d개의 파일을 찾았습니다!\n", word, count);

	return 0;
}
