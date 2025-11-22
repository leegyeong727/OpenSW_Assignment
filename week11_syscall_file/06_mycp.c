#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUF_SIZE 32

int main(int argc, char* argv[])
{
    if (argc < 3) {
        printf("Usage: %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
        exit(0);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        exit(1);
    }

    int num_files = argc - 2;
    int* dest_fd_list = (int*)malloc(sizeof(int) * num_files);
    for (int i = 0; i < num_files; i++) {
        dest_fd_list[i] = open(argv[i + 2],
                               O_WRONLY | O_CREAT | O_TRUNC,
                               S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if (dest_fd_list[i] == -1) {
            perror("open");
            exit(1);
        }
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while (1)
    {
        read_result = read(src_fd, readStr, BUF_SIZE);

        if (read_result == 0) {
            break;
        }

        if (read_result < 0) {
            perror("read");
            break;
        }

        write(STDOUT_FILENO, readStr, read_result);

        if (read_result < BUF_SIZE && readStr[read_result - 1] != '\n') {
            write(STDOUT_FILENO, "\n", 1);
        }

        for (int i = 0; i < num_files; i++) {
            if (write(dest_fd_list[i], readStr, read_result) < 0) {
                perror("write");
                break;
            }
        }
    }

    close(src_fd);
    for (int i = 0; i < num_files; i++) {
        close(dest_fd_list[i]);
    }

    free(readStr);
    free(dest_fd_list);

    write(STDOUT_FILENO, "program end...\n", 15);

    return 0;
}
