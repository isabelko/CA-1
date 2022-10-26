
#include "producer_consumer.h"

int main() {
    int fd = shm_open("/producer-consumer", O_RDWR, 0);
    if (fd == -1) errExit("Failed to open shared memory space in consumer");

    // create a pcbuf struct named pcbufs and map to the shared memory space
    struct pcbuf *pcbufs = mmap(NULL, sizeof(*pcbufs), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (pcbufs == MAP_FAILED) errExit("Failed to map a pcbuf struct to the shared memory space");

    // tell producer we're ready for the data
    if (sem_post(&pcbufs->empty) == -1) errExit("Failed to post on the reader semaphore");  
    int out = 0;
    for (int i = 0; i < MAX_BUF; ++i) {
        if (sem_wait(&pcbufs->full) == -1) errExit("Failed to wait on the writer semaphore");
        char item = pcbufs->buf[out];
        printf("Recieved data %d: %c\n", out, item);
        out = (out + 1) % BUF_SIZE;
        if (sem_post(&pcbufs->empty) == -1) errExit("Failed to post on the reader semaphore");
    }

    shm_unlink("/producer-consumer"); // unlink
    exit(EXIT_SUCCESS); // exit with success
}
