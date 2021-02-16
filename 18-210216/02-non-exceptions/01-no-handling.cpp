void read_people() {
    FILE *f = fopen(filename "r");
    if (!f) {  // Не удалось открыть файл — вернули nullptr.
        printf("Unable to open file\n");
        // return;
        exit(1);  // Завершаем всю программу.
    }
    // ...
    fclose(f);
}
