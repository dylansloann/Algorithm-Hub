int romanToInt(string s) {
    int final = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I' && s[i + 1] == 'V') { final += 4; i++; }
        else if (s[i] == 'I' && s[i + 1] == 'X') { final += 9; i++; }
        else if (s[i] == 'X' && s[i + 1] == 'L') { final += 40; i++; }
        else if (s[i] == 'X' && s[i + 1] == 'C') { final += 90; i++; }
        else if (s[i] == 'C' && s[i + 1] == 'D') { final += 400; i++; }
        else if (s[i] == 'C' && s[i + 1] == 'M') { final += 900; i++; }
        
        else if (s[i] == 'I') { final += 1; }
        else if (s[i] == 'V') { final += 5; }
        else if (s[i] == 'X') { final += 10; }
        else if (s[i] == 'L') { final += 50; }
        else if (s[i] == 'C') { final += 100; }
        else if (s[i] == 'D') { final += 500; }
        else if (s[i] == 'M') { final += 1000; }
    }
    
    return final;
}