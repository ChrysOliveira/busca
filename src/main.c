#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_lines_with_word(const char *filename, const char *word) {
  int fd = open(filename, O_RDONLY);
  if (fd == -1) {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  char line[BUFFER_SIZE];
  ssize_t bytes_read;
  size_t line_length = 0;

  while ((bytes_read = read(fd, buffer, BUFFER_SIZE - 1)) > 0) {
    buffer[bytes_read] = '\0';
    for (int i = 0; i < bytes_read; i++) {
      line[line_length++] = buffer[i];

      if (buffer[i] == '\n' || line_length == BUFFER_SIZE - 1) {
        line[line_length] = '\0';

        if (strstr(line, word) != NULL) {
          printf("%s", line);
        }
        line_length = 0;
      }
    }
  }

  if (bytes_read == -1) {
    perror("Error reading file");
    close(fd);
    exit(EXIT_FAILURE);
  }

  close(fd);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <filename> <word>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  print_lines_with_word(argv[1], argv[2]);
  return 0;
}
