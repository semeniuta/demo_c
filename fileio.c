#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 32
#define SEQUENCE_START 65 // 'A'
#define CHARS_TO_WRITE 5

void print_current_file_offset(int fd);
void print_bytes(char *buffer, int n_bytes);

int main(int argc, char *argv[])  {

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));

    // Prepare bytes to write:
    // five charracters ABCDE, space character, \0, '!' 
    for (int i = 0; i < CHARS_TO_WRITE; i++) {
        char c = SEQUENCE_START + i;
        buffer[i] =  c;
    }
    buffer[CHARS_TO_WRITE    ] = 32; // space
    buffer[CHARS_TO_WRITE + 1] = 0; // '\0';
    buffer[CHARS_TO_WRITE + 2] = '!'; 

    // Open file
    int fd = open("outfile", O_RDWR | O_CREAT | O_TRUNC); 
    if (fd == -1) {
        printf("Problem opening a file\n");
        return -1;
    }
    printf("File opened\n");
    print_current_file_offset(fd);

    // Print the bytes to write
    int n_bytes = CHARS_TO_WRITE + 3;
    printf("Bytes to write (%d): ", n_bytes);
    print_bytes(buffer, n_bytes);

    // Write bytes
    ssize_t n_written = write(fd, &buffer, n_bytes);
    printf("Bytes written: %ld\n", n_written);
    print_current_file_offset(fd);

    // Close file
    close(fd);

}

void print_current_file_offset(int fd) {

    off_t offset = lseek(fd, 0, SEEK_CUR);
    printf("Current offset: %lld\n", offset);
}

void print_bytes(char *buffer, int n_bytes) {

    for (int i = 0; i < n_bytes; i++) {
        char c = buffer[i];

        if (c >= 32 && c <= 126) {
            printf("%c", c);
        } else {
            printf("0x%x", c);
        }
    }
    printf("\n");
}
