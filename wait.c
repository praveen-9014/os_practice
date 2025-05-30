#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        printf("\nProcess creation failure\n");
        exit(-1);
    }
    else if (pid > 0) {
        // Parent process
        wait(NULL);  // Wait for child to finish
        printf("\nParent starts\nEven Nos: ");
        for (i = 2; i <= 10; i += 2)
            printf("%3d", i);
        printf("\nParent ends\n");
    }
    else {
        // Child process
        printf("Child starts\nOdd Nos: ");
        for (i = 1; i < 10; i += 2)
            printf("%3d", i);
        printf("\nChild ends\n");
    }

    return 0;
}
