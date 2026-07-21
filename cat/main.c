#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define EARG -1

int getFd(const char* path);
int getStringLen(const char* s);
void die(const char *exitmessage, const int errorcode);
void handleErrno(const char *message);

int main(int argc, char* argv[]) {
    if (argc != 2) die("Usage: cat [FILE]\n", EARG);
    
    char* filePath = argv[1];
    
    int fd = getFd(filePath);
    
    char buffer[4096];
    ssize_t result;

    while((result = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, result);
    }

    if (result == -1) handleErrno(":22 error at read()");

    close(fd);

    return 0;
}

int getFd(const char* path) {
    int fd = open(path, O_RDONLY);

    if (fd == -1) handleErrno(":33 error at open()");

    return fd;
}

int getStringLen(const char *s) {
    int counter = 0;
    while (s[counter] != '\0') counter++;
    return counter;
}

void handleErrno(const char* message) {
    die(message, errno);
}

void die(const char *exitmessage, const int errorcode) {
    write(STDERR_FILENO, exitmessage, getStringLen(exitmessage));
    write(STDERR_FILENO, "\n", 1);
    _exit(errorcode);
}