#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define CURDIR 1
#define SINGLEDIR 2

int getmode(int argc);
void rsingledir(const char* path);
int getStringLen(const char *s);

int main(int argc, char* argv[]) {
    int mode = getmode(argc);

    if (mode == 1) {
        rsingledir("./");
        return 0;
    }

    rsingledir(argv[1]);
    return 0;
}

int getmode(int argc) {
    int mode;
    if (argc == 1) mode = CURDIR;
    else if (argc == 2) mode = SINGLEDIR;
    else printf("Warning: only the first directory will be read\n");

    return mode;
}

void rsingledir(const char* path) {
    DIR* dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        exit(errno);
    }

    struct dirent *current;
    
    while ((current = readdir(dir)) != NULL) {
        char *name = current->d_name; 
        if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0) continue;
        printf("%s ", name);
    }
}

int getStringLen(const char *s) {
    int counter = 0;
    while (s[counter] != '\0') counter++;
    return counter;
}