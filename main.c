#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* memory = NULL;
unsigned long allocated_memory = 0;

void execute(char* cmd) {
  if (strcmp(cmd, "exit") == 0) {
    printf("exiting...\n");
    free(cmd);
    free(memory);
    exit(0);
  }

  else if (strcmp(cmd, "help") == 0) {
    const char* msg = "list of commands:\n"
                      " memory - show count of use memory (bytes).\n"
                      " exit - exit from program, also you can press Ctrl+C.\n"
                      " allocate - allocate 200MB.\n"
                      " free - free all allocate memory.\n"
                      " overflow - this command start infinity loop of allocating memory!\n"
                      " clear - clear console output.\n"
                      " help - show this message.\n";
    printf("%s", msg);
  }
  
  else if (strcmp(cmd, "memory") == 0) {
    printf("Allocating memory (bytes): %lu.\n", allocated_memory);
  }

  else if (strcmp(cmd, "allocate") == 0) {
    allocated_memory += 200*1024*1024;
    void* new_memory = realloc(memory, allocated_memory);
    if (new_memory == NULL) {
        fprintf(stderr, "Memory allocation failed!");
        free(memory);
        free(cmd);
        exit(1);
    }

    memory = new_memory;
    memset(memory, 1, allocated_memory);
    printf("Successfully allocated 200MB.\n");
}

  else if (strcmp(cmd, "free") == 0) {
    allocated_memory = 0;
    free(memory);
    memory = NULL;
    printf("Success free memory.\n");
  }

  else if (strcmp(cmd, "clear") == 0) {
    #ifdef _WIN32
      system("cls");
    #elif __linux__
      system("clear");
    #endif
  }

  else if (strcmp(cmd, "overflow") == 0) {
    printf("Starting...\n");
    while (1) {
      allocated_memory += 200*1024*1024;
      void* new_memory = realloc(memory, allocated_memory);
      if (new_memory == NULL) {
        fprintf(stderr, "Memory allocation failed!");
        free(memory);
        free(cmd);
        exit(1);
      }

      memory = new_memory;
      memset(memory, 1, allocated_memory);
      printf("Allocated memory: %lo\r", allocated_memory);
    }
  }
}

int main(int argc, char* argv[]) {
  const char* welcome_message = "Welcome to memory manager!\n"
                                "You can type 'help' to get list of commands.\n";
  printf("%s", welcome_message);

  char* cmd = (char*)malloc(1024); // sizeof(char) == 1
  if (cmd == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    return 1;
  }

  while (1) {
    printf("~# ");
    fgets(cmd, 1024, stdin);
    cmd[strcspn(cmd, "\n")] = '\0';

    if (strcmp(cmd, "") != 0) {
      execute(cmd);
    }
  }

  free(memory);
  free(cmd);
  return 0;
}
