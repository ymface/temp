#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char** argv) {
	if(argc != 2) {
		printf("argument not enough");
		exit(1);
	}

	char* origName = argv[1];
	int nameBodyLen = 0;
	for(int i = 0; ; i++) {
		if(origName[i] == 0) { break; }
		if(origName[i] == '.') { nameBodyLen = i; }
	}

	const int fullNameLen = nameBodyLen + 4;
	char lnkName[fullNameLen + 1];
	memcpy(lnkName, origName, nameBodyLen);
	strcpy(&lnkName[fullNameLen - 4], ".sym");

	if(symlink(origName, lnkName) == -1) {
		perror("symbolik link failed");
		exit(1);
	}

	char path[100];
	if(getcwd(path, sizeof(path)) == NULL) {
		perror("get cwd failed");
		exit(1);
	}

	printf("original : %s%s", path, origName);
	printf("symbolik link : %s%s", path, lnkName);
	return 0;
}
