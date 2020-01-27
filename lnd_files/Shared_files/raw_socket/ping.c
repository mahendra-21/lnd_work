#include "header.h"
#include <netdb.h>
#define DLEN 68
#define HLEN 8
#define LEN (DLEN+HLEN)


struct icmp *pkt;

unsigned short chksum(unsigned short *ip, int len){
	long sum = 0;						 /* assume 32 bit long, 16 bit short */

	while(len > 1){
		sum += *ip++;
		if(sum & 0x80000000)			 /* if high order bit set, fold */
			sum = (sum & 0xFFFF) + (sum >> 16);
		len -= 2;
	}

	if(len)								 /* take care of left over byte */
		sum += (unsigned short) *(unsigned char *)ip;

	while(sum>>16)
		sum = (sum & 0xFFFF) + (sum >> 16);

	return ~sum;
}

/*
unsigned int chksum(unsigned short *pkt, int len)
{
	int sum = 0;
	while (len > 1) {
		sum = sum + *pkt++;
		len = len - 2;
	}
	
	if (len == 1) {
		sum = sum + *pkt;
	}

	sum = (sum >> 16) + (sum & 0xFFFF);
	sum = sum + (sum >> 16);
	sum = ~sum;
}
*/
int main(int argc, char *argv[])
{
	struct sockaddr_in pingaddr;
	int pingfd;
	char packet[LEN];
	struct hostent *hent;
	int len = sizeof(struct sockaddr_in);
	int c;

	printf("%d %s\n",sizeof(struct icmp), argv[1]);

	if ((pingfd = socket(AF_INET, SOCK_RAW, 1)) == -1)
		err("bind() failed\n");

	memset(&pingaddr, 0, len);
	pingaddr.sin_family = AF_INET;
	pingaddr.sin_port = htons(PORT);
	hent = gethostbyname(argv[1]);
	memcpy(&pingaddr.sin_addr, hent->h_addr, sizeof(pingaddr.sin_addr));
	
	pkt = (struct icmp *) packet;
	memset(pkt, 0, sizeof(packet));

	pkt->icmp_type = ICMP_ECHO;
	pkt->icmp_cksum = chksum((unsigned short *) pkt, sizeof(packet));

	if (sendto(pingfd, packet, sizeof(packet), 0,
			(struct sockaddr *) &pingaddr, sizeof(struct sockaddr_in)) == -1)
		err("send failed");
	printf("Sent\n");
	/* listen for replies */
	while (1) {
		struct sockaddr_in from;
		size_t fromlen = sizeof(from);

		if ((c = recvfrom(pingfd, packet, sizeof(packet), 0,
						(struct sockaddr *) &from, &fromlen)) < 0) {
			perror("ping: recvfrom");
			printf("rec\n");
			continue;
		}
		if (c >= 76) {                   /* ip + icmp */
			struct iphdr *iphdr = (struct iphdr *) packet;
			pkt = (struct icmp *) (packet + (iphdr->ihl << 2));      /* skip ip hdr */
			if (pkt->icmp_type == ICMP_ECHOREPLY) {
				printf("recieved\n");
				break;
			}
		}
	}
	return;
}
