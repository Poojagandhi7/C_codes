#include <stdio.h>
#include <string.h>

void rabinKarp(char pattern[], char text[]) {
  int m = strlen(pattern);
  int n = strlen(text);
  int i;

  int val = 0;
  int x = 0;

  // Calculate the value of the pattern
  for (i = 0; i < m; i++) {
    x = (int)pattern[i] - 96;
    val += x;
  }

  // Compare
  int iv = 0;
  for (i = 0; i < m; i++) {
    iv += (int)text[i] - 96;
  }

  for (i = 0; i <= n - m; i++) {
    if (iv == val) {
      int flag = 0;
      for (int j = 0; j < m; j++) {
        if (text[i + j] == pattern[j])
          flag += 1;
      }
      if (flag == m) {
        printf("Matched at position %d\n", i + 1);
      }
    }
    iv -= (int)text[i] - 96;
    iv += (int)text[i + m] - 96;
  }
}

int main() {
  char text[] = "ABCCDDAEFG";
  char pattern[] = "CDD";
  rabinKarp(pattern, text);
  return 0;
}
