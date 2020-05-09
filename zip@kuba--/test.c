#include <zip.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#if defined(_MSC_VER) || defined(__MINGW64__) || defined(__MINGW32__)
#define MZ_FILE_STAT_STRUCT _stat
#define MZ_FILE_STAT _stat
#else
#define MZ_FILE_STAT_STRUCT stat
#define MZ_FILE_STAT stat
#endif

#define UNUSED(x) (void)x


int on_extract_entry(const char *filename, void *arg) {
  static int i = 0;
  int n = *(int *)arg;
  printf("Extracted: %s (%d of %d)\n", filename, ++i, n);

  return 0;
}
int main(int argc, char** argv) {
  UNUSED(argc);

  int arg = 2;
  zip_extract(argv[1], ".", on_extract_entry, &arg);
  return 0;
}
