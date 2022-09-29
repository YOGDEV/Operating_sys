/*
Orphan process
The process whose parent process has finished (Completed execution) or terminated and do not exists in the process table are called orphan process. Usually, a parent process waits for its child to terminate or finish their job and report to it after execution but if he fails to do so it results in the Orphan process.

In most cases, the Orphan process is immediately adopted by the init process (a very first process of the system).

Note: fork() is a UNIX system call so following program will work only on UNIX based operating systems.

Program for orphan process in C

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // fork() Create a child process

    int pid = fork();
    if (pid > 0) {
        //getpid() returns process id
        // while getppid() will return parent process id
        printf("Parent process\n");
        printf("ID : %d\n\n", getpid());
    }
    else if (pid == 0) {
        printf("Child process\n");
        // getpid() will return process id of child process
        printf("ID: %d\n", getpid());
        // getppid() will return parent process id of child process
        printf("Parent -ID: %d\n\n", getppid());

        sleep(10);

        // At this time parent process has finished.
        // So if u will check parent process id
        // it will show different process id
        printf("\nChild process \n");
        printf("ID: %d\n", getpid());
        printf("Parent -ID: %d\n", getppid());
    }
    else {
        printf("Failed to create child process");
    }

    return 0;
}
