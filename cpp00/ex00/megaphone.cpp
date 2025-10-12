#include <iostream>

char *upper_str(char *s) {
  int i = 0;
  while (s[i]) {
    if ('a' <= s[i] && s[i] <= 'z')
      s[i] -= 'a' - 'A';
    i++;
  }
  return s;
}

int main(int argc, char *argv[]) {
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  else {
    for (int i = 1; i < argc; i++)
      std::cout << upper_str(argv[i]);
  }
  std ::cout << "\n";
  return 0;
}
