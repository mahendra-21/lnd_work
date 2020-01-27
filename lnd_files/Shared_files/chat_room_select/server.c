#include "header.h"
#include <poll.h>
#define pf(msg) printf("%s",msg);
#define CNO 20

static char *wbuff;
static mqd_t mid;
static int count = 0;
static int serverfd;
static int wait = 0;
int inx = 0;
int nfds;

struct pollfd rfds[CNO];

typedef struct client_info {
	char cip[20];//client ip
	int cfd;//client fd
} c_info;

c_info cinf[CNO];//client info

void client_disconnect(int ind);



/****************************
 * Client read
****************************/
void *thread_client_read (void *arg)
{
	int i = (int)arg;
	char tbuff[LINE];
	int cltfd = 0;
	printf("Read thread created \n");
	memset(tbuff , 0,LINE);

/*
	if (recv (cltfd, tbuff, LINE, 0)) {
		//perror("recv th()");
		if (strcmp(tbuff, "cr11")) {
			send (cltfd, "0Authentication failure,reconnect again!\n", LINE, 0);
			close(cltfd);
			cinf[i].cfd = 0;
			count--;	
			return NULL;
		} else {
			if (send (cltfd, "1Authenticated\n", LINE, 0) == -1)
				perror("Authentication failure\n");
			else {
				printf("T1 %s authenticated\n",cinf[i].cip);
			}
		}
 	}	
	memset(tbuff, 0 ,LINE);	*/
	while (1) {
	//	while(wait);
		int j = 0;
		poll (rfds, count, -1);
		printf("event\n");
		for (j = 0;j < count;j++) {
				printf("Event occured\n");
				if (rfds[i].revents == POLLIN) {
						recv (rfds[j].fd, tbuff, LINE ,0); 
						if (*tbuff != '\0') {
								mq_send(mid, tbuff, 128, 0);
						} else {
								client_disconnect(i);
						}
					memset(tbuff, 0, LINE);
				}
				rfds[i].revents = 0;
		}
	}
}

/***********************
 * Client disconnect
*************************/


void client_disconnect(int ind)
{
	//printf("client_disconnect()..\n");
	printf("%s quit\n",cinf[ind].cip);
	close(cinf[ind].cfd);
	rfds[ind].fd = 0;	
	cinf[ind].cfd = 0;
	memset(&cinf[ind], 0, sizeof(c_info));
	count--;
	return;
}


void *thread_client_broadcast (void *arg)
{
	int i = 0;
	printf("Thread broadcast created\n");
	while(1) {
		if (mq_receive(mid, wbuff, LINE, NULL) == -1)
			       err("mrev() failed\n");
			for(i = 0; i < CNO; i++) {
				if (cinf[i].cfd != 0) {
					if (send (cinf[i].cfd, wbuff, LINE, 0) == -1)
						perror("send failed");
				}
			}
	}	
}

/***********************
 * Client disconnected
************************/

void client_disconnected(int signo, siginfo_t *siginfo, void *arg)
{
	int i = 0;
	count--;
	printf("###SIGPIPE Client disconnected\n");
	if (count == 0)
		wait = 1;
	for (i = 0;i <= count; i++) {
		if (cinf[i].cfd == siginfo->si_fd) {
			close(cinf[i].cfd);
			cinf[i].cfd = 0;
			printf("%s quit\n",cinf[i].cip);
			break;
		}
	}
}

/***********************
 * Server disconnected
***********************/

void server_disconnected(int signo, siginfo_t *siginfo, void *arg)
{
	int i = 0;
	printf("Closing connections..\n");
	for (i = 0;i < count;i++) {
			close(cinf[i].cfd);
	}
	close(serverfd);
	killpg(getpid(),SIGKILL);
}

int main()
{
	int backlog = 24;
	char ip[20];
	int i = 0;
	struct sockaddr_in ser_addr;
	struct sockaddr_in con_addr;
	pthread_t id = 0;
	pthread_attr_t tattr;
	socklen_t len = sizeof(struct sockaddr_in);
	struct mq_attr attr;

	pthread_attr_init(&tattr);
	/**********************
	 * SIGPIPE handling
	 *******************/
	sigset_t mask;
	sigemptyset(&mask);
	
	struct sigaction act = {
		.sa_sigaction = client_disconnected,
		.sa_mask = mask,
		.sa_flags = SA_SIGINFO
	};
	sigaction(SIGPIPE, &act, NULL);

	struct sigaction intact = {
		.sa_mask = mask,
		.sa_sigaction = server_disconnected,
		.sa_flags = SA_SIGINFO
	};

	sigaction(SIGINT, &intact, NULL);

	/***************************
	*	MSG QUEUE
	***************************/
	attr.mq_maxmsg = LINE;
	attr.mq_msgsize = LINE;
	wbuff = malloc(LINE);

	mid = mq_open("/nchatq", O_CREAT | O_RDWR , 0666, &attr);
		
	if (mid < 0) 
		err("mq failed\n");

	/*********************
	 * Listen socket
	*********************/
	serverfd = socket (AF_INET, SOCK_STREAM, 0);
	
	if (serverfd == -1) 
		err("socket() failed\n");
	
	memset (&ser_addr, 0, len);

	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons (PORT);
	ser_addr.sin_addr.s_addr = inet_addr ("172.16.5.79");

	if (bind(serverfd, (S_A)&ser_addr, len) == -1) 
		err("bind() failed\n");	
	
	system("clear");
	printf("------------------------------------------\n");
	printf("  Server: 172.16.5.128  Max clients:%d\n",CNO);	
	printf("------------------------------------------\n");
	
	if (listen(serverfd, backlog) == -1)
			err("listen() failed\n");

	pthread_attr_setstacksize(&tattr, 0x2000);
	pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_DETACHED);
	if (pthread_create (&id, &tattr, thread_client_broadcast, NULL))
			err("create() failed\n");

	if (pthread_create (id, NULL, thread_client_read, (void*)inx))
			err("create() failed\n");
	inx = 0;
	while (1){
		while (count < CNO) {
			for(i = 0;i < CNO; i++) {
				if (cinf[i].cfd == 0) {
					inx = i;
					break;
				}
			}

			if ((cinf[inx].cfd = accept(serverfd, (S_A) &con_addr, &len)) == -1)
				err("accept() failed\n");
			//extract ip address
			inet_ntop(AF_INET, &con_addr.sin_addr.s_addr, ip, len);
			
			//validate whether ip is already connected
			for(i = 0; i < count; i++) {
				if (!strcmp(ip, cinf[i].cip)) {
					printf("%s already connected\n",cinf[inx].cip);
					close(cinf[inx].cfd);
					cinf[inx].cfd = 0;
				}
			}

			if (cinf[inx].cfd != 0) {
				send (cinf[inx].cfd, "1Authenticated\n", LINE, 0);
				strcpy(cinf[inx].cip, ip);	
				printf("%s connected\n Number of clients %d\n",
						cinf[inx].cip, count + 1);
				rfds[inx].fd = cinf[inx].cfd;
				rfds[inx].events = POLLIN;
				count++;
			}
		}
	}
	pthread_exit(NULL);	
}
