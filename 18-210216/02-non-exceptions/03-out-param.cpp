#if 0
int sqlite3_open(
  const char *filename,   /* Database filename (UTF-8) */
  sqlite3 **ppDb          /* OUT: SQLite db handle */
);
#endif

int main() {
    int err;
    sqlite3 *db;
    if ((err = sqlite3_open("hello.sqlite3", &db)) != 0) {
        // err - локальная переменная, полностью контролируем.
        if (err == ....) {
            // ....
        } else if (err == ....) {
            // ....
        } else {
            // ....
        }
    }
}
