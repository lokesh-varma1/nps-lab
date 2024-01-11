#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;

sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("\nSocket Creation Error");

}
//printf("%i",sockfd);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
printf("Connection error");

}
int a[10];
printf("enter the 10 numbers");
for(int i=0;i<10;i++)
scanf("%d",&a[i]);

printf("enter your choice:\n1.serach for a number\n2.sort\n3.spit to odd or even");

int y;
scanf("%d",&y);

sentbytes=send(sockfd,&y,sizeof(y),0);
if(sentbytes==-1)
{
printf("!!");
close(sockfd);
}

sentbytes=send(sockfd,a,sizeof(a),0);
if(sentbytes==-1)
{
printf("!!");
close(sockfd);
}

close(sockfd);
}
