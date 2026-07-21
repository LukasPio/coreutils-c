#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define EARG 1
#define EPATH 2
#define EOPEN 3
#define EREAD 4

int getFd(char* path);

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: cat [FILE]\n");
        exit(EARG);
    }
    char* filePath = argv[1];
    
    int fd = getFd(filePath);
    
    char buffer[4096];
    int result;

    while((result = read(fd, buffer, sizeof(buffer))) != 0) {
        if (result == -1) {
            perror("read");
            exit(EREAD);
        }
        write(STDOUT_FILENO, buffer, result);
    }

    close(fd);

    return 0;
}

int getFd(char* path) {
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(EOPEN);
    }

    return fd;
}