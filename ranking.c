#include "header.h"

int index = 1;

int ranking(char *filename, int count) {
	if (count != 0) { //�ǹ��ִ� �����Ͱ� ���� ��쿡�� ����Ʈ ����
		int i;
		data* temp = head;
		data *new_data = (data*)calloc(1, sizeof(data)); //���ο� ������

		if (searchstring(filename) == -1)
			return -1;

		new_data->num = count;
		strcpy(new_data->filename, filename);

		/*ó�� �Է¹��� ���*/

		if (index == 1) {
			head = new_data;
			index++;
			return 0;
		}

		/*�Է°��� ó�� ������ ū ���*/

		if (new_data->num > head->num) {
			new_data->next = head;
			head = new_data;
			return 0;
		}

		else {
			while (1) {
				/*�Է� ���� ���� ���� �ִ� ���*/
				if (new_data->num == temp->num) {
					new_data->next = temp->next;
					temp->next = new_data;
					break;
				}

				/*�Է� ���� ���� ���� ���*/
				if (temp->next == NULL) {
					temp->next = new_data;
					break;
				}

				/*�߰��� ���� ���*/
				if (new_data->num > temp->next->num) {
					new_data->next = temp->next;
					temp->next = new_data;
					break;
				}

				temp = temp->next;
			}
		}
	}

	return 0;
}