#include "header.h"

void findfile()
{
	char name[260];
	struct _finddata_t fd;
	long handle;
	int i, result = 1;
	handle = _findfirst("..\\dataset\\*.txt", &fd); // ù��° ���� ã��

	if (handle == -1)
	{
		printf("There were no files.\n");
		return;
	}

	while (result != -1)
	{
		ranking(fd.name, searchstring(fd.name)); //���� �̸��� ranking.c�� ������
		result = _findnext(handle, &fd); // ���� ����
	}
	_findclose(handle);

	return;
}
