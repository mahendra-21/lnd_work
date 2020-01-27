#include <stdio.h>

void CreateDBidx(FILE *sfd, FILE *dfd);

int main(int argc, char **argv) {
	

	if (argc == 2) {

		CreateDBidx(fopen(argv[1], "r"), fopen("db.idx", "w+"));
		puts("File created successfully");
	}

	else
		puts("File is not found");
	return 0;
}
