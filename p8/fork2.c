#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int ret;

    printf("Antes do fork: PID = %d, PPID = %d\n", getpid(), getppid());
    ret = fork();
    if (ret < 0) { 
        perror("erro na duplicação do processo");
        return EXIT_FAILURE;
    }

    if (ret > 0) {
        // This is the parent process
        sleep(1); // Ensure that the child process prints first
        printf("PAI\n");
    } else {
        // This is the child process
        printf("FILHO\n");
    }

    printf("Quem sou eu?\nApós o fork: PID = %d, PPID = %d, retorno do fork = %d\n",
           getpid(), getppid(), ret);

    return EXIT_SUCCESS;
}
