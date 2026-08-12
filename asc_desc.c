#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void sort_asc(int arr[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1]) {
                int temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
}

void sort_desc(int arr[], int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] < arr[j+1]) {
                int temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
}

int main() {
    int n = 5;
    int arr[] = {4, 1, 3, 5, 2};
    pid_t pid = fork();

    if (pid == 0) {
        sort_asc(arr, n);
        printf("Child (Ascending): ");
        for(int i=0; i<n; i++) printf("%d ", arr[i]);
        printf("\n");
        exit(0); 
    } else if (pid > 0) {
        wait(NULL); 
        sort_desc(arr, n);
        printf("Parent (Descending): ");
        for(int i=0; i<n; i++) printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit asc_desc.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc asc_desc.c -o exp2
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./exp2
Child (Ascending): 1 2 3 4 5
Parent (Descending): 5 4 3 2 1
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$
*/

