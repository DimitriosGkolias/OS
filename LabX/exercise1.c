#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) { // Child process
            printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else if (pid > 0) { // Parent process
            printf("Parent process: Created child with PID = %d\n", pid);
        } else { // Error
            perror("fork failed");
        }
    }
    return 0;
}
