#include "header.h"

int main() {
	int count = 0;

	/*�˻� Ű���� �Է�*/

	printf("�˻��� Ű���带 �Է��ϼ���: ");
	gets(word); 

	findfile();

	/*��� ���*/
	while (head != NULL) {
		printf("���ϸ� : %s, Ű���� ���� : %d \n", head->filename, head->num);
		count++;

		head = head->next;
	}

	printf("\nŰ���� %s�� �����ϰ� �ִ� %d���� ������ ã�ҽ��ϴ�!\n", word, count);

	return 0;
}