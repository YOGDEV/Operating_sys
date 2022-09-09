/*
ZOMBIE PROCESS
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
printf("\nYogesh Singh Yadav");
printf("\nSection : A\n");
printf("\nZOMBIE PROCESS\n");
int x=fork();
if(x>0)
{
 sleep(10);
 printf("\nparent process\n");
}
else
{
 printf("\nexit child process\n");
 exit(0);
}

return 0;
}
 
