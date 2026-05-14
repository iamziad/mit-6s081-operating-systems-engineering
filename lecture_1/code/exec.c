#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    char *argv[] = {"echo", "hello", 0};

    execv("/bin/echo", argv);
    fprintf(stderr, "exec error");
}
