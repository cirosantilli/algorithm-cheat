/**
Reads fixed chunk sizes from file not to overflow RAM.

If a line is larger than this chunk size,
the program exits with `EXIT_FAILURE` and gives an error message.

Mimics GNU cat 8.2, which require that the file
end in a newline to print the last line properly, e.g.:

    a b \n c d \n

Gets printed as:

    cd
    ab

But:

     a b \n c d

Gets printed as:

     cdab
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    /* Maximum accepted line length is buf_size including the newline. */
    enum Constexpr { buf_size = 8 };
    char buffer[buf_size], buffer_leftover[buf_size];
    size_t print_up_to, leftover_bytes, file_size, seek_end_offset, nbytes_read;
    size_t i;

    if (argc < 2) {
        fprintf(stderr, "Error: input path missing.\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: input path not found: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    /* TODO check file eixsts. */
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    nbytes_read = buf_size;
    leftover_bytes = 0;
    /* Unsigned type loop: use two variables idiom. */
    for (seek_end_offset = buf_size; seek_end_offset < file_size + buf_size; seek_end_offset += buf_size) {
        /* Last iteration. */
        if (seek_end_offset > file_size) {
            nbytes_read = buf_size - (seek_end_offset - file_size);
            seek_end_offset = file_size;
        }
        fseek(fp, -seek_end_offset, SEEK_END);
        fread(buffer, sizeof(char), nbytes_read, fp);
        print_up_to = nbytes_read - 1;
        /* Unsigned type loop. Use wrap around idiom. */
        /* TODO replace with strrchr */
        for (i = nbytes_read - 1; i < nbytes_read; --i) {
            if (buffer[i] == '\n') {
                if (i < nbytes_read - 1) {
                    fwrite(&buffer[i + 1], sizeof(char), print_up_to - i, stdout);
                }
                print_up_to = i;
                if (leftover_bytes > 0) {
                    fwrite(buffer_leftover, sizeof(char), leftover_bytes, stdout);
                    leftover_bytes = 0;
                }
            }
        }
        if (print_up_to == buf_size) {
            fprintf(stderr, "Error: line longer than buffer size. Buffer size: %d\n", buf_size);
            exit(EXIT_FAILURE);
        }
        leftover_bytes = print_up_to + 1;
        /* memmove */
        memcpy(buffer_leftover, buffer, leftover_bytes);
    }
    fwrite(buffer_leftover, sizeof(char), leftover_bytes, stdout);
    exit(EXIT_SUCCESS);
}
