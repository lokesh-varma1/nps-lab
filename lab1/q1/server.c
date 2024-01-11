#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

main()
{
int sockfd,newsockfd,retval;
socklen_t actuallen;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr,clientaddr;

sockfd=socket(AF_INET,SOCK_STREAM,0);

if(sockfd==-1)
{
printf("\nSocket creation error");
}

serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==1)
{
printf("Binding error");
close(sockfd);
}

retval=listen(sockfd,1);
if(retval==-1)
{
close(sockfd);
}

actuallen=sizeof(clientaddr);
newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);


if(newsockfd==-1)
{
close(sockfd);
}int y;
int a[10];
recedbytes=recv(newsockfd,&y,sizeof(y),0);
if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
}
recedbytes=recv(newsockfd,a,sizeof(a),0);
if(recedbytes==-1)
{
close(sockfd);
close(newsockfd);
}
switch (y){
case 1:
printf("enter the number to be searched");
int z;
scanf("%d",&z);
for(int i=0;i<10;i++)
if(z==a[i])
printf("element found at %d",(i+1));
else
printf("element not found");
break;

case 2:

for (int i = 0; i < 10; ++i)
{
for (int j = i + 1; j < 10; ++j)
{
if (a[i] > a[j])
{
int tem =  a[i];
a[i] = a[j];
a[j] = tem;
}}
}
printf("ascending order:");
for(int i=0;i<10;i++)
printf("%d",a[i]);
printf("\ndescending order\n");
for(int i=9;i>=10;i--)
printf("%d",a[i]);
break;

case 3:
printf("even numbers");
for(int i=0;i<10;i++){
if(a[i]%2==0)
printf("%d",a[i]);}
printf("odd numbers");
for(int i=0;i<10;i++){
if(a[i]%2!=0)
printf("%d",a[i]);}
break;}



close(sockfd);
close(newsockfd);
}

