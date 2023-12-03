#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Read input data.
  string s1, s2;
  int pos;
  cin >> s1 >> s2 >> pos;

  // Generate the sequence of strings s1, s2, ..., sn.
  vector<string> strings;
  strings.push_back(s1);
  for (int i = 1; i < s2.length(); i++) {
    strings.push_back(s1.substr(0, s1.length() - i));
  }

  // Find the character in position pos of the string S.
  int i = 1;
  int j = 0;
  while (i <= pos) {
    if (j == strings[i - 1].length()) {
      i++;
      j = 0;
    } else if (S[i - 1] == strings[i - 1][j]) {
      i++;
      j++;
    } else {
      // The character in position i - 1 of string S is the character that was removed from strings[i - 1] to obtain strings[i].
      break;
    }
  }

  // Print the answer.
  cout << strings[i - 1][j] << endl;

  return 0;
}
