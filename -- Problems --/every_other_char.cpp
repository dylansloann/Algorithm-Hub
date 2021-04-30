void resize(char*& input, int* cap, int size) {    
    *cap = 2 * (*cap);
    char* new_string = new char[*cap];
    for (int i = 0; i < size; i++) {
        new_string[i] = input[i];
    }
    delete[] input;
    input = new_string;
}

char* strdup_every_other_char(const char* s) {
    char* final = new char[1];
    int size = 0;
    int cap = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        if (i % 2 == 0) {
            final[size] = s[i];
            size++;
        }

        if (size == cap)
            resize(final, &cap, size);
    }
    final[size] = '\0';
    return final;
}