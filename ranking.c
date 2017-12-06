#include "header.h"

int index = 1;

int ranking(char *filename, int count) {
	if (count != 0) { //의미있는 데이터가 들어올 경우에만 리스트 연결
		int i;
		data* temp = head;
		data *new_data = (data*)calloc(1, sizeof(data)); //새로운 데이터

		if (searchstring(filename) == -1)
			return -1;

		new_data->num = count;
		strcpy(new_data->filename, filename);

		/*처음 입력받은 경우*/

		if (index == 1) {
			head = new_data;
			index++;
			return 0;
		}

		/*입력값이 처음 값보다 큰 경우*/

		if (new_data->num > head->num) {
			new_data->next = head;
			head = new_data;
			return 0;
		}

		else {
			while (1) {
				/*입력 값과 같은 값이 있는 경우*/
				if (new_data->num == temp->num) {
					new_data->next = temp->next;
					temp->next = new_data;
					break;
				}

				/*입력 값이 가장 작은 경우*/
				if (temp->next == NULL) {
					temp->next = new_data;
					break;
				}

				/*중간에 끼는 경우*/
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