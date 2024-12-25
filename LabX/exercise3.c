#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();

    if (pid == 0) { // Child process
        signal(SIGUSR1, signal_handler);
        printf("Child waiting for signal...\n");
        pause(); // Wait for signal
    } else if (pid > 0) { // Parent process
        sleep(2); // Give the child time to set up the handler
        printf("Parent sending signal to child.\n");
        kill(pid, SIGUSR1);
    } else {
        perror("fork failed");
    }

    return 0;
}
