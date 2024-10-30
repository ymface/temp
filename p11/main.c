#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main() {
	DIR* p_dir;
	struct dirent* p_dent;
	if((p_dir = opendir(".")) == NULL) {
		perror("opendir failed");
		exit(1);
	}

	while((p_dent = readdir(p_dir)) != NULL) {
		if(strcmp(p_dent->d_name, ".") == 0 || strcmp(p_dent->d_name, "..") == 0) { continue; }

		struct stat sbuff;
		if(stat(p_dent->d_name, &sbuff) == -1) {
			perror("get file stat failed");
			exit(1);
		}

		if((sbuff.st_mode & S_IFMT) != S_IFDIR) { continue; }
		
		printf("%s\n", p_dent->d_name);
	}

	return 0;
}
