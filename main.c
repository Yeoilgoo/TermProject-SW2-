#include "header.h"

void findfile(const char *dir, int tap);

int main() {
	unsigned num;

	findfile("E:\\users\\ilgoo\\desktop\\FileList", 0);
	getch();

	return 0;
}

void findfile(const char *dir, int tap) {
	struct _finddata_t fd;
	long handle;
	int result = 0;
	char buf[_MAX_PATH + 3], buf2[40];
	int i;

	sprintf(buf, "%s\\*.*", dir);
	handle = _findfirst(buf, &fd);

	if (handle == -1)
		return;

	while (result != -1) {
		if ((fd.attrib & _A_SYSTEM) == 0 && (strcmp(fd.name, ".") != 0) && (strcmp(fd.name, "..")) != 0) {
			for (i = 0; i <= tap; i++)
				buf2[i] = ' ';

			buf2[i] = NULL;

			sprintf(buf, "%s파일명 : %s, 크기 : %d", buf2, fd.name, fd.size);
			puts(buf);

			if ((fd.attrib & _A_SUBDIR) != 0) {
				sprintf(buf, "%s\\%s", dir, fd.name);
				findfile(buf, tap + 1);
			}
		}

		result = _findnext(handle, &fd);
	}

	_findclose(handle);
}