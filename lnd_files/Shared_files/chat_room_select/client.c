#include "header.h"
/*********************
 * client -nc v1.0b
*********************/
static char *rbuff;
static char user[LINE];
static char *buff;
static char *msg;
static int serverfd = 0;
WINDOW *inwin;
WINDOW *dispwin;

void create_window(void);

void *thread_display(void *arg)
{
	int x,y;
	while (1) {
		memset(rbuff, 0, strlen(rbuff));
		if (recv (serverfd, rbuff, LINE, 0) == -1)
			err("recv failed()");
		if (!*rbuff) {
			printf("Server closed\n");
			endwin();
			exit(0);
		}
		else {
			getyx (dispwin, y, x);
			if (y == 24) {
				werase(dispwin);
				box(dispwin, 0 ,0);
				getyx (dispwin, y, x);
			}
			wmove (dispwin, y+1, 1);
			wprintw (dispwin,"%s", rbuff);
			wrefresh(dispwin);
		}
	}
}

void *thread_input(void *arg)
{
	int x,y;
	while(1) {
		getyx (inwin, y,  x);
		wmove (inwin, y + 1, x + 1);
		wgetnstr(inwin, buff, LINE);	
		werase(inwin);
		box(inwin, 0, 0);
		if (send (serverfd, msg ,LINE, 0) == -1)
			err("send() failed\n");
		memset(buff, 0, strlen(buff));
	}
}

void create_window()
{
	dispwin = newwin (26, 109, 0, 0);
	inwin = newwin (6, 109, 26, 0);
	wsetscrreg (dispwin, 1, 24);
	scrollok (dispwin, TRUE);
	box(dispwin, 0, 0);
	box(inwin, 0, 0);
	wmove(inwin, 1, 1);
	wrefresh(inwin);
	wrefresh(dispwin);
}


void client_disconnected(int signo, siginfo_t *siginfo, void *arg) {
	printf("Disconnecting client..\n");
	close(serverfd);
	endwin();
	exit(0);
}

int main(int argc, char *argv[])
{
	struct sockaddr_in ser_addr;
	buff = malloc (LINE);
	rbuff = malloc (LINE);
	char *ip = "172.16.5.79";
	errno = 0;
	socklen_t len = sizeof(struct sockaddr_in);
	pthread_t th_id1 = 0 , th_id2 = 0;
	sigset_t mask;
	sigemptyset(&mask);	

	struct sigaction intact = {
		.sa_mask = mask,
		.sa_sigaction = client_disconnected,
		.sa_flags = SA_SIGINFO
	};

	sigaction(SIGINT, &intact, NULL);


	serverfd = socket (AF_INET, SOCK_STREAM , 0);
	
	if (serverfd == -1) 
		err("socket() failed\n");

	memset (&ser_addr, 0,len );
	ser_addr.sin_family = AF_INET;

	ser_addr.sin_port = htons (PORT);
	ser_addr.sin_addr.s_addr = inet_addr (argv[1]);
	
	getlogin_r(user, LINE);
	strcpy (buff, user);
	msg = buff;
	buff = (char*)(buff + strlen(user));
	*buff = ':';
	buff++;
	printf("----------------------------------------------------------\n");
	printf("  Client: %s     Server: %s -nc   v1.0b    \n", user, ip);
	printf("----------------------------------------------------------\n");
	printf("#Connecting..\n");		
	while (connect(serverfd,(struct sockaddr *)&ser_addr, sizeof(struct sockaddr)) == -1); 
	
	printf("#Connected to server!\n");
	/****************************
	 * Authentication
	****************************/
	/*printf("Enter the code:\n");
	fgets(buff, LINE, stdin);
	*(buff + strlen(buff) - 1) = '\0';
	send (serverfd, buff ,LINE, 0);
	recv (serverfd, rbuff, LINE, 0);
	printf("%s",rbuff);
	if (*rbuff == '0') {
		endwin();
		exit(1);	
	}*/
	initscr();
	cbreak();
	echo();
	//system("clear");
	printw("---------------------------------------------------------\n");
	printw("  Client: %s     Server: %s -nc   v1.0b    \n", user, ip);
	printw("---------------------------------------------------------\n");
	refresh();
	memset(buff, 0, strlen(buff));
	create_window();	
	if (pthread_create(&th_id1, NULL, thread_display, (void*)serverfd))
		err("create failed\n");

	if (pthread_create(&th_id2, NULL, thread_input, (void*)serverfd))
		err("create failed\n");
	
	pthread_join(th_id1, NULL);
	pthread_join(th_id2, NULL);
	close(serverfd);
	endwin();
	return 0;
}
