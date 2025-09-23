#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (pid) { // if parent
    execl("/usr/bin/ls", "/usr/bin/ls", "-a", (char *)NULL);
  } else {
    execl("/usr/bin/ls", "/usr/bin/ls", "-a", "-l", "-h", (char *)NULL);
  }
  printf("DONE %d\n", pid);
}
