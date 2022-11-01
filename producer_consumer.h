#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

#define BUF_SIZE 2
#define TOTAL_CONS_PRODUCE 20

struct pcbuf {
    sem_t empty;
    sem_t full;
    size_t index;
    char buf[BUF_SIZE];
};