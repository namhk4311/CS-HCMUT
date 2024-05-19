#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FILENAME "shared_file.txt"
#define FILESIZE 4096

int main(int argc, char * argv[]) {
	char fname[100], op[100], oparg[100];
    if (argc < 2) {
        printf("USAGE %s [-filename FILEPATH] write|read op [textstring]\n", argv[0]);
        return 0;
    }

    if (strcmp(argv[1], "-filename") == 0) {
        if(argc >= 3) strcpy(fname, argv[2]);
        if(argc >= 4) strcpy(op, argv[3]);
        if(argc >= 5) strcpy(oparg, argv[4]);
    } else {
        strcpy(fname, FILENAME);
        strcpy(op, argv[1]);
        strcpy(oparg, argv[2]);
    }

	printf("%s %s %s", fname, op, oparg);
	int fd;

	// Create a new file
	fd = open(FILENAME, O_CREAT | O_RDWR, 0666);
	if (fd == -1) {
		perror("Error opening the file!!");
		exit(EXIT_FAILURE);
	} else {
		printf("Successfully opening the file!!\n");
	}

	// Truncate the file
	if (ftruncate(fd, FILESIZE) == -1) {
		perror("Error truncating the file!!");
		exit(EXIT_FAILURE);
	} else {
		printf("Successfully truncating the file!!\n");
	}

	// Map the file into memory
	char * ptr = mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (ptr == MAP_FAILED) {
		perror("Error while mapping file to memory");
	} else {
		printf("Successfully mapping file to memory\n");
	}

	// Close the file description

	pid_t pid = fork();
	if (pid < 0) {
		perror("Create child process failed");
	} else if (pid == 0) { //Child process
		printf("This is child process!!\n");
		if (strcmp(op, "write") == 0) {
			printf("-> Child process writing to shared memory...\n");
			sprintf(ptr, "%s", oparg);
		} else if (strcmp(op, "read") == 0) {
			printf("-> Child process reading from shared memory...\n");
			if (ptr == NULL) {
				printf("Nothing in here to read\n");
			} else {
				printf("Message read from shared memory: %s\n", ptr);
			}
		}
		exit(EXIT_SUCCESS);
	} else { // Parent process
		wait(NULL); 
		printf("This is parent process\n");
		if (strcmp(op, "write\0") == 0) {
			printf("-> Parent process read message from child: %s\n", ptr);
		} 	
	}

	close(fd);
	// Unmap the memory
	if (munmap(ptr, FILESIZE) == -1) {
        perror("Error unmapping memory");
        exit(EXIT_FAILURE);
    }

	// Remove the shared_file.txt
    // if (unlink(FILENAME) == -1) {
    //     perror("Error removing file");
    //     exit(EXIT_FAILURE);
    // }

    return 0;
}

