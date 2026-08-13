#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>


int main() {
    int fd[2]; 
    char read_msg[100]; 

    pipe(fd); 

    if (fork() != 0) { 
        close(fd[0]); 
        write(fd[1], "Hi from Parent!", sizeof("Hi from Parent!")); 
        close(fd[1]); 
        wait(NULL);   
    } else { 
        close(fd[1]); 
        read(fd[0], read_msg, sizeof(read_msg)); 
        printf("Child received: %s\n", read_msg); 
        close(fd[0]); 
    }
    
    return 0;
}

/*
gargi_007@LAPTOP-113399:~$ prog

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit pipe.c

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc pipe.c -o p

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./p

Child received: Hi from Parent!

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$
*/

