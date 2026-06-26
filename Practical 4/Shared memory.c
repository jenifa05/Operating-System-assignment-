#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = 1234;

    int shmid = shmget(key, SHM_SIZE, 0666);

    if (shmid == -1)
    {
        printf("Shared memory not found.\n");
        return 1;
    }

    char *data = (char *)shmat(shmid, NULL, 0);

    if (data == (char *)-1)
    {
        printf("Failed to attach shared memory.\n");
        return 1;
    }

    printf("Data read from shared memory:\n%s\n", data);

    shmdt(data);

    shmctl(shmid, IPC_RMID, NULL);

    printf("Shared memory removed successfully.\n");

    return 0;
}
