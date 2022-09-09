/*
fork(): there are two process that run behind fo single fork()...
ORPHEN PROCESS
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
printf("\nYogesh Singh Yadav");
printf("\nSection : A\n");
printf("\nORPHEN PROCESS\n");

int x=fork();

if(x>0)
{
 printf("\nparent process\n");
}
else if(x==0)
{  sleep(5);
 printf("\nexit child process\n");
}

return 0;
}
 
