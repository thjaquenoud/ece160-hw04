#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  NAME_ONLY = 0,
  MAJOR_AND_NAME = 1, 
  YEAR_AND_NAME = 2,
  YEARS_LEFT_AND_NAME = 3
} Mode;

typedef struct {
  char *first_name;
  char *last_name;
  char *major; 
  int year;

} Student;

void print_student(Mode m, Student s) {
  switch (m) {
    case NAME_ONLY:
      printf("%s %s\n", s.first_name, s.last_name);
      break;
    case MAJOR_AND_NAME:
      printf("%s %s %s\n", s.major, s.first_name, s.last_name);
      break;
    case YEAR_AND_NAME:
      printf("%d %s %s\n", s.year, s.first_name, s.last_name);
      break; 
    case YEARS_LEFT_AND_NAME:
      printf("%d %s %s\n", (s.year - 2017), s.first_name, s.last_name);
      break;
    default:
      printf("ERROR\n");

  }
}

int main(int argc, char* argv[]) {

  char *filename = argv[1];   //declare filename
  FILE *fp;
  char buffer[256];     // declare buffer
  fp = fopen(filename, "r");   // open file for reading
  
  Student struct_array[256];
  char first_name[256];
  char last_name[256];
  char major[256];
  int year;
  int years_left;

  if (fp == NULL) {
    printf("Could not open %s\n", filename);
    return -1;
  }

  //char *c;
  int i = 0;
  while (fgets(buffer, 255, fp) != NULL) {
    Student s;

    size_t length = strlen(buffer);
    size_t length_bytes = (length + 1) * sizeof(char);
    char *new_string = malloc(length_bytes);
    s.first_name = malloc(length_bytes);
    s.last_name = malloc(length_bytes);
    s.major = malloc(length_bytes);

    memcpy(new_string, buffer, length_bytes);
   
    sscanf(buffer, "%s %s %s %d ", s.first_name, s.last_name, s.major, &s.year);
    struct_array[i] = s;
    i++;

    }
  fclose(fp);

  while(1) {
    int index;
    int mode;
    fscanf(stdin, "%d %d", &index, &mode);
    print_student(mode, struct_array[index]);

  }
  return 0;
} 
