#include "header.h"

int main()
{
	struct sockaddr_in saddr;
	struct sockaddr_in srcaddr;
	int tfd;
	char buff[LINE];
	char ip[20];
	int len = sizeof(struct sockaddr);
	if ((tfd = socket(PF_PACKET, SOCK_DGRAM, htons(ETH_P_ALL))) < 0) 
		err("socket()");	
	
	while (1) {
		recvfrom (tfd, buff, LINE, 0, (struct sockaddr*)&srcaddr, &len);
		inet_ntop (AF_INET, &srcaddr.sin_addr.s_addr, ip, len);
		printf("%lx\n",buff);	
	}
	close(tfd);
}
