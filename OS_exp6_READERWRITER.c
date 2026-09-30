#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt, mutex;
int readcount = 0;
int shared_data = 1;

void* writer(void* arg) {
    int id = *((int*)arg);
    
    sem_wait(&wrt);
    
    shared_data += 5; 
    printf("Writer %d modified shared_data to %d\n", id, shared_data);
    
    sem_post(&wrt);
    
    return NULL;
}

void* reader(void* arg) {
    int id = *((int*)arg);
    
    sem_wait(&mutex);
    readcount++;
    if (readcount == 1) {
        sem_wait(&wrt);
    }
    sem_post(&mutex);

    printf("Reader %d read shared_data as %d\n", id, shared_data);

    sem_wait(&mutex);
    readcount--;
    if (readcount == 0) {
        sem_post(&wrt);
    }
    sem_post(&mutex);
    
    return NULL;
}

int main() {
    int r, w;
    pthread_t r_tid[20], w_tid[20];
    int ids[20];

    printf("Enter number of readers and writers: ");
    scanf("%d %d", &r, &w);

    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < 20; i++) ids[i] = i + 1;

    for (int i = 0; i < w; i++) pthread_create(&w_tid[i], NULL, writer, &ids[i]);
    for (int i = 0; i < r; i++) pthread_create(&r_tid[i], NULL, reader, &ids[i]);

    for (int i = 0; i < w; i++) pthread_join(w_tid[i], NULL);
    for (int i = 0; i < r; i++) pthread_join(r_tid[i], NULL);

    sem_destroy(&wrt);
    sem_destroy(&mutex);

    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit OS_exp6_READERWRITER.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc OS_exp6_READERWRITER.c -o readerwriter
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./readerwriter
Enter number of readers and writers: 3
2
Writer 1 modified shared_data to 6
Writer 2 modified shared_data to 11
Reader 1 read shared_data as 11
Reader 2 read shared_data as 11
Reader 3 read shared_data as 11
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$
*/

