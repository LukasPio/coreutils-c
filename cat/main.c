#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define NOARGS -1

int getFd(const char* path);
int getStringLen(const char* s);
void die(const char *exitmessage, const int errorcode);
void handleErrno();

int main(int argc, char* argv[]) {
    if (argc != 2) die("Usage: cat [FILE]\n", NOARGS);
    
    char* filePath = argv[1];
    
    int fd = getFd(filePath);
    
    char buffer[4096];
    ssize_t rbytes;

    while((rbytes = read(fd, buffer, sizeof(buffer))) > 0) {
        ssize_t wbytes = write(STDOUT_FILENO, buffer, rbytes);
        if (wbytes == -1) handleErrno();
    }

    if (rbytes == -1) handleErrno();

    close(fd);

    return 0;
}

int getFd(const char* path) {
    int fd = open(path, O_RDONLY);

    if (fd == -1) handleErrno();

    return fd;
}

int getStringLen(const char *s) {
    int counter = 0;
    while (s[counter] != '\0') counter++;
    return counter;
}

void handleErrno() {
    char* errmsg = strerror(errno);
    die(errmsg, errno);
}

void die(const char *exitmessage, const int errorcode) {
    write(STDERR_FILENO, exitmessage, getStringLen(exitmessage));
    write(STDERR_FILENO, "\n", 1);
    _exit(errorcode);
}