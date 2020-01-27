#include <stdio.h>

void CreateDBidx(FILE *sfd, FILE *dfd) {

	char ch;
	int offset = 0;
	
	while ((ch = getc(sfd)) != EOF) {
		
		while ((ch != ',') || (ch != '|')) {
			putc(ch, dfd);
			ch = getc(sfd);
		}
		while ((ch = getc(sfd)) != '\n');
		if (offset == 0)
			fprintf(dfd, " %d\n", offset);
		else
			fprintf(dfd, " %d\n", offset+1);
		offset = ftell(sfd);
	}
	fclose(sfd);
	fclose(dfd);

}
