#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

struct sockaddr_un init_address(const char *path) {

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(struct sockaddr_un));

    addr.sun_family = AF_UNIX;
    
    int max_len = sizeof(addr.sun_path) - 1;
    strncpy(addr.sun_path, path, max_len);

    return addr;
}

int main() {

    struct sockaddr_un addr = init_address("/tmp/myscoket");

    printf("Socket address (length %ld): %s\n", strlen(addr.sun_path), addr.sun_path);
    printf("sun_len: %d\n", addr.sun_len);
    printf("size of sun_path: %ld\n", sizeof(addr.sun_path));

    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd == -1) {
        printf("Error creating the socket\n");
        return -1;
    }

    if (bind(fd, (struct sockaddr *) &addr, sizeof(struct sockaddr_un)) == -1) {
        printf("Error binding to the address\n");
        return -1;
    }

    // TODO listen

    // TODO accept

    if (close(fd) == -1) {
        printf("Error closing the socket\n");
        return -1;
    }

    return 0;
}