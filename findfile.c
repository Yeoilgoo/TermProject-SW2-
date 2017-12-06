#include "header.h"

void findfile()
{
	char name[260];
	struct _finddata_t fd;
	long handle;
	int i, result = 1;
	handle = _findfirst("..\\dataset\\*.txt", &fd); // 첫번째 파일 찾음

	if (handle == -1)
	{
		printf("There were no files.\n");
		return;
	}

	while (result != -1)
	{
		ranking(fd.name, searchstring(fd.name)); //파일 이름을 ranking.c로 보내줌
		result = _findnext(handle, &fd); // 다음 파일
	}
	_findclose(handle);

	return;
}
