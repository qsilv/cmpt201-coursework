#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
int main() {
  fork();
  for (int i = 0; i < 20; i++) {
    printf("going to sleep\n");
    sleep(5);
  }
  printf("done\n");
}
