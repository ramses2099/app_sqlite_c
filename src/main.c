#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // printf("%s\n", sqlite3_version);
  const char *file_name = "./test.db";
  sqlite3 *db;
  char *zErrMsg = NULL;
  int rc = 0;

  rc = sqlite3_open(file_name, &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return EXIT_FAILURE;
  }
  int result = 0;
  sqlite3_stmt *stmt;
  rc = sqlite3_prepare_v2(db, "select 2 + 2;", -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to execute quey: %s\n", zErrMsg);
    sqlite3_close(db);
    return EXIT_FAILURE;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    result = sqlite3_column_int(stmt, 0);
    printf("%d\n", result);
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return EXIT_SUCCESS;
}
