#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("texto.txt", O_RDONLY);
	struct stat st;
	fstat(fd, &st);

	void *mem = mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
	write(STDOUT_FILENO, mem, st.st_size);

	return 0;
}


