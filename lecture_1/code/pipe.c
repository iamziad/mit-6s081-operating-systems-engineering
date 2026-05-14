#include <stdio.h>
#include <unistd.h>

int main()
{
    int pfd[2];
    pipe(pfd); // Creating the pipe.

    if (fork() > 0) {
        close(pfd[0]); // Closing the read end
        write(pfd[1], "msg", 4);
        close(pfd[1]); // Closing the write end
    } else {
        char buf[4];
        close(pfd[1]); // Closing the write end
        read(pfd[0], buf, 4);
        printf("%s", buf); // msg
        close(pfd[0]); // Closing the read end
    }
    return 0;
}
