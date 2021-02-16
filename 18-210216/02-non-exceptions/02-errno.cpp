int main() {
    // ....
    if (chdir("hello-dir") != 0) {
        // errno - глобальная переменная.
        // А что если несколько функций подряд?
        if (errno == EACCES) {
            // ....
        } else if (errno == EBADF) {
            // ....
        } else {
            // ....
        }
    }
}
