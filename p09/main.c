#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char** argv) {
	if(argc != 2) {
		perror("argument not enough");
		exit(1);
	}

	char* fname = argv[1];

	struct stat sbuff;
	if(stat(fname, &sbuff) == -1) {
		perror("file access failed");
		exit(1);
	}

	printf("%s ", fname);
	printf("%d ", sbuff.st_uid);

	if((sbuff.st_mode & S_IRUSR) != 0) { printf("%c", 'r'); }
	else { printf("%c", '-'); }
	if((sbuff.st_mode & S_IWUSR) != 0) { printf("%c", 'w'); }
	else { printf("%c", '-'); }
	if((sbuff.st_mode & S_IXUSR) != 0) { printf("%c", 'x'); }
	else { printf("%c", '-'); }
	
	if((sbuff.st_mode & S_IRGRP) != 0) { printf("%c", 'r'); }
	else { printf("%c", '-'); }
	if((sbuff.st_mode & S_IWGRP) != 0) { printf("%c", 'w'); }
	else { printf("%c", '-'); }
	if((sbuff.st_mode & S_IXGRP) != 0) { printf("%c", 'x'); }
	else { printf("%c", '-'); }
	
	if((sbuff.st_mode & S_IROTH) != 0) { printf("%c", 'r'); }
	else { printf("%c", '-'); }
	if((sbuff.st_mode & S_IWOTH) != 0) { printf("%c", 'w'); }
	else { printf("%c", '-'); }
	if((sbuff.st_mode & S_IXOTH) != 0) { printf("%c", 'x'); }
	else { printf("%c", '-'); }

	return 0;
}
