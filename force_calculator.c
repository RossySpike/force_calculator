#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_help();

int is_number(const char *string);

int main(int argc, char **argv) {
  switch (argc) {
  case 2:
    if (strcmp(argv[1], "--help") == 0) {
      show_help();
      return 0;
    }
    return 1;
  case 4:
    if (is_number(argv[1]) == 0 || is_number(argv[2]) == 0 ||
        is_number(argv[3]) == 0) {
      perror("Error: Invalid types\n");
      return 1;
    }
    break;
  default:
    printf("Error: Invalid number of arguments\n");
    show_help();
    return 1;
  }

  double weight = strtod(argv[1], NULL), distance = strtod(argv[2], NULL),
         time = strtod(argv[3], NULL),
         force = weight * 2 * distance / (time * time);
  printf("|\tWeight\t|\tDistance\t|\tTime\t|\tForce\t|\n");
  printf("|\t%.2lfKg\t|\t%.2lfm\t|\t%.2lfs\t|\t%.2lfN\t|\n", weight, distance,
         time, force);

  return 0;
}

void show_help() {
  printf("Usage: force_calculator <Weight> <Distance> <Time>\n");
}

int is_number(const char *string) {
  char *endptr;
  errno = 0;
  strtod(string, &endptr);
  if (errno != 0 || endptr == string || *endptr != '\0') {
    return 0;
  }
  return 1;
}
