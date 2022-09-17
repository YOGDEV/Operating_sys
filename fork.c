#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
    // make two process which run same
    // program after this instruction
    printf("\nName : Yogesh Singh Yadav :  Sec : A\n");
    fork();
    fork();
    int i=0;
    printf("Hello world!\n");
    printf("This is process %d : and the process id is : %d \n",i,getpid());
    return 0;
}
