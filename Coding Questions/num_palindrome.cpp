bool isPalindrome(int x) {
    if (x < 0) { return false; }

    int reversed = 0, pop, tmp = x;
    
    while (tmp > 0) {
        pop = tmp % 10;
        tmp /= 10;
        if (reversed < INT_MIN / 10 || reversed > INT_MAX / 10) { return false; } 
        reversed = reversed * 10 + pop;
    }
    
    if (x == reversed) { return true; }
    else { return false; }
}