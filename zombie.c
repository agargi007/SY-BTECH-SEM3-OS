#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid > 0) {
        sleep(10); 
        printf("Parent waking up.\n");
    } else if (pid == 0) {
        printf("Child process terminating, becoming a zombie.\n");
        exit(0);
    }
    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit zombie.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc zombie.c -o z
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./z
Child process terminating, becoming a zombie.
Parent waking up.
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$
*/
