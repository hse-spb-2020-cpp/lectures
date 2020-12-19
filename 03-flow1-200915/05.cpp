auto fib(int n) {
/*    if (n > 1) {
//        return fib(n - 1) + fib(n - 2);
        return 1.0;
    } else {
        return 1;
    }*/

    if (n <= 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
}
