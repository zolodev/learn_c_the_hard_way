/*****************************************************************************
 * Filename      : logfind.c
 * Created       : Thu Mar 23 2023
 * Author        : Zolo
 * Github        : https://github.com/zolodev
 * Description   : Exercise 26 - Create a program (logfind) similar to grep
 * Features      :
 *      1. Takes any sequences of word and assume "AND" when searching in files.
 *      2. It takes an optional argument (-o)  to change from "AND" to "OR"
 *      3. It loads the list of allowed log files from ~/.logfind
 *      4. The list of files can be anything that 'glob' function allows.
 *      5. Out matching lines as it scans them, as fast as possible
 *
 *****************************************************************************/
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "dbg.h"

char *get_fullpath(char *dir, char *filename) {
  // +2, because of the '/' and terminating 0
  char *tmp_path = malloc(strlen(dir) + strlen(filename) + 2);
  check_mem(tmp_path);
  sprintf(tmp_path, "%s/%s", dir, filename);

  return tmp_path;
error:
  return NULL;
}

int SearchInDir(char *dir, char *words_to_find[]) {
  struct dirent *de = NULL;  // Pointer for directory entry
  FILE *fp = NULL;
  char *fullpath = NULL;

  // opendir() returns a pointer of DIR type.
  DIR *dr = opendir(dir);
  check(dr != NULL, "Could not open current directory %s\n", dir);

  int found = 0;
  // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
  while ((de = readdir(dr)) != NULL) {
    int next = (telldir(dr) > 0L);
    int line = 0;
    // Ignore path '.' and '..' in linux
    if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, "..")) continue;

    if (strstr(de->d_name, ".log") != NULL ||
        strstr(de->d_name, ".txt") != NULL) {
      int wc = sizeof(*words_to_find) / sizeof(words_to_find[0]);

      fullpath = get_fullpath(dir, de->d_name);

      fp = fopen(fullpath, "r");
      check(fp != NULL, "Could not open file: %s", fullpath);

      // Search for the words...
      for (int i = 0; i < wc; i++) {
        char buf[4096];

        while ((fgets(buf, 4096, fp)) != NULL) {
          ++line;
          if (strstr(buf, words_to_find[i]) != NULL) {
            if (found++ == 0 && next++) {
              printf("%s (Line: %d)\n", fullpath, line);
            } else if (found++ != 0) {
              printf("\t\t| %s (Line: %d)\n", fullpath, line);
            }
          }
        }

        fclose(fp);
      }

      free(fullpath);
    }
  }

  closedir(dr);
  return found;
error:
  return 0;
}

int main(int argc, char *argv[]) {
  check(argc > 1, "Need at least one argument.");

  int opt = 0;
  char *path = " ";

  while ((opt = getopt(argc, argv, "op:")) != -1) {
    switch (opt) {
      case 'p':
        path = optarg;
        break;
      default:
        (opt == '?') ? printf("Unknow option: %c\n", optopt)
                     : log_err("Unknow error. Option: %c\n", opt);
        break;
    }
  }

  // optind is for the extra arguments
  // which are not parsed
  printf("-----------------------------------------------------------\n");
  printf("Search Word:\t| Found in File (Line)\n");
  printf("-----------------------------------------------------------\n");
  for (; optind < argc; optind++) {
    char **searchWord = &argv[optind];
    printf("%s\t\t| ", *searchWord);
    int found = SearchInDir(path, searchWord);

    if (!found) printf("[Not Found in any file]\n");
    printf("-----------------------------------------------------------\n");
  }

  return 0;
error:
  return -1;
}