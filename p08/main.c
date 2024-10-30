#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
	if(argc != 2) {
		perror("argument not enough");
		exit(1);
	}

	char* nameBuff = argv[1];
	printf("file name : ");

	struct stat sbuff;

	if(stat(nameBuff, &sbuff) == -1) {
		perror("get stat failed");
		exit(1);
	}

	printf("inode : %d\n", sbuff.st_ino);
	printf("file category : ");
	switch(sbuff.st_mode & S_IFMT) {
	case S_IFBLK:
		printf("Block special\n");
		break;
	case S_IFCHR:
		printf("Character special\n");
		break;
	case S_IFIFO:
		printf("FIFO spaecial\n");
		break;
	case S_IFREG:
		printf("Regular file\n");
		break;
	case S_IFDIR:
		printf("Directory\n");
		break;
	case S_IFLNK:
		printf("Symbolik link\n");
		break;
	case S_IFSOCK:
		printf("Socket file\n");
		break;
	default:
		perror("file type failed");
		exit(1);
	}
	printf("access authorization : %o\n", sbuff.st_mode);
	printf("uid : %d\n", sbuff.st_uid);
	return 0;
}
