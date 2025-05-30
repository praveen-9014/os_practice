#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int x = 5;

    pid = fork(); // Create a new process
    x++;

    if (pid < 0) {
        printf("Process creation error\n");
        exit(-1);
    } 
    else if (pid == 0) {
        // Child process
        printf("\nChild process:");
        printf("\nProcess ID: %d", getpid());
        printf("\nValue of x: %d", x);
        printf("\nParent process ID: %d\n", getppid());
    } 
    else {
        // Parent process
        printf("\nParent process:");
        printf("\nProcess ID: %d", getpid());
        printf("\nValue of x: %d", x);
        printf("\nParent (shell) process ID: %d\n", getppid());
    }

    return 0;
}
