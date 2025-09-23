#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// getinput() inspired by lab example
char *getinput() {
  char *line = NULL;
  size_t len;
  printf("Enter input: ");
  ssize_t read = getline(&line, &len, stdin);

  if (read == -1) {
    perror("reading command failed");
    exit(1);
  }
  line[read - 1] = '\0';
  return line;
}

int main() {

  char **arr = malloc(5 * sizeof(char *));
  for (int i = 0; i < 5; i++) {
    arr[i] = NULL;
  }

  while (true) {
    char *currentline = getinput();
    if (strcmp(currentline, "print") == 0) {
      for (int i = 0; i < 5; i++) {
        if (arr[i]) {
          printf("%s\n", arr[i]);
        }
      }
    } else {
      if (arr[4])
        free(arr[4]);
      for (int i = 4; i > 0; i--) {
        arr[i] = arr[i - 1];
      }

      arr[0] = strdup(currentline);
    }
  }
  for (int i = 0; i < 5; i++) {
    free(arr[i]);
  }
  free(arr);
}
