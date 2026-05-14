#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0)
        exit(1);
    if (pid > 0) {
        printf("parent: hello from parent\n");
        wait((int*) 0);
    } else {
        printf("child: hello from child\n");
        exit(1);
    }

    return 0;
}
