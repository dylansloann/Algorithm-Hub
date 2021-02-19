int reverse(int x) {
    int reversed = 0;
    int tmp;
    while (x != 0) {
        int tmp = x % 10;
        x /= 10;
        if (reversed < INT_MIN / 10 || reversed > INT_MAX / 10) { return 0; } 
        reversed = reversed * 10 + tmp;
    }
    return reversed;
}