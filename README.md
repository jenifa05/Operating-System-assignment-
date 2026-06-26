Synchronization in C – Practical Sessions

This repository contains C programs demonstrating fundamental operating system synchronization concepts using POSIX threads, mutexes, semaphores, and shared memory.

Practical Sessions

Practical 1: Mutex Lock Demonstration

- Implemented thread synchronization using "pthread_mutex_t".
- Compared program behavior with and without a mutex to demonstrate race conditions.

Practical 2: Producer-Consumer Problem

- Simulated the producer-consumer problem using a circular buffer.
- Used semaphores ("mutex", "empty", and "full") to synchronize producer and consumer threads.

Practical 3: Semaphore Implementation

- Demonstrated the use of binary and counting semaphores.
- Protected shared resources using "sem_wait()" and "sem_post()".
- Compared semaphore-based synchronization with mutex-based synchronization.

Practical 4: Shared Memory Programming

- Implemented inter-process communication (IPC) using System V shared memory.
- Created separate writer and reader programs to exchange data through a shared memory segment.

Technologies Used

- C Programming
- POSIX Threads (Pthreads)
- POSIX Semaphores
- System V Shared Memory
- GCC Compiler

How to Compile

gcc filename.c -o output -lpthread

For the shared memory programs:

gcc writer.c -o writer
gcc reader.c -o reader

Learning Objectives

This project demonstrates thread synchronization, mutual exclusion, semaphore operations, producer-consumer synchronization, and inter-process communication using shared memory in C.
