#include "libmx.h"

char *mx_file_to_str(const char *file) {
	int fd = open(file, O_RDONLY);
	char *res = mx_strnew(0);
	ssize_t byte;
	if (fd == -1)
	{
		return NULL;
	}
	char c;
	while ((byte = read(fd, &c, 1)) > 0)
	{
		res = mx_strjoin(res, &c);
	}
	close(fd);
	return res;
}
