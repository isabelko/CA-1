#include "producer_consumer.h"

int main() {
    int fd = shm_open("/producer-consumer", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);

    //open shared memory object and make sure space is avaliable for our buffer
    if (fd == -1) errExit("Failed to open shared memory object");
    if (ftruncate(fd, sizeof(struct pcbuf)) == -1) errExit("Failed to allocated to shared memory object");

    // create a pcbuf struct named pcbufs and map to the shared memory space
    struct pcbuf *pcbufs = mmap(NULL, sizeof(*pcbufs), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (pcbufs == MAP_FAILED) errExit("Failed to map a pcbuf struct to the shared memory space");

    // init two process shared semaphores
    if (sem_init(&pcbufs->empty, 1, 0) == -1) errExit("Failed to init the writer semaphore");
    if (sem_init(&pcbufs->full, 1, 0) == -1) errExit("Failed to init the reader semaphore");

    // loop and wait for the consumer to post to the semaphore before producing any data
    char item = 'a';
    int in = 0;
    printf("\n");
    for (int i = 0; i < MAX_BUF; ++i) {
        //printf("hello?");
        if (sem_wait(&pcbufs->empty) == -1) errExit("Failed to wait on the reader semaphore");      
        pcbufs->buf[in] = item;
        printf("producer sent item %d :%c\n", in, item);
        in = (in + 1) % BUF_SIZE;
        item++;
        if (sem_post(&pcbufs->full) == -1) errExit("Failed to post on the writer semaphore"); 
        
    }

    shm_unlink("/producer-consumer"); // unlink
    exit(EXIT_SUCCESS); // exit with success
}

