string reverse_string(string input) {
  string reverse;
  for (int i = input.length() - 1; i >= 0; i--) {
    reverse.push_back(input[i]);
  }
  return reverse;
}

string amount_palindrome(string input) {
  
    // create reversed string to use as other input in longest common subsequence
    string reverse = move(reverse_string(input));

    // create 2d array to store values for LCS sub sequence comparison between original and reversed
    int LCS_arr[input.length() + 1][input.length() + 1];

    // fill intitial row and coloumn with zeros
    for (int i = 0; i < input.length() + 1; i++) {
      LCS_arr[0][i] = 0;
      LCS_arr[i][0] = 0;
    }

    for (int i = 1; i < input.length() + 1; i++) {
      for (int j = 1; j < input.length() + 1; j++) {
        // if characters are equal in corresponding index, add 1 to diagonal element in previous row
        if (input[j - 1] == reverse[i - 1])
          LCS_arr[i][j] = 1 + LCS_arr[i - 1][j - 1];
        
        // if not equal take the larger of the previous column with previous row
        else {
          if (LCS_arr[i][j - 1] > LCS_arr[j][i - 1])
            LCS_arr[i][j] = LCS_arr[i][j - 1];
          else
            LCS_arr[i][j] = LCS_arr[i - 1][j];
        }
      }
    }

    // take value in final column & row to get value of the longest common sub sequence
    int LCS_value = LCS_arr[input.length()][input.length()];

    // obtain the amount of values not in the common subsequence to determine how many needed to insert to obtain palindrome
    return to_string(input.length() - LCS_value);
}