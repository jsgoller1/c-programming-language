#include <stdio.h>
#define MAXLINE 1000

int mygetline(char line[], int max);
int strrindex(char source[], int s_len, char searchfor[]);

char pattern[] = {"ould"};

// Find all lines matching pattern
int main()
{
  // 9
  char good1[] = "goodfoodwouldmold";
  printf("%d\n", strrindex(good1, 17, pattern));

  // 11
  char good2[] = "wouldwouldwould";
  printf("%d\n", strrindex(good2, 15, pattern));

  // -1
  char good3[] = "g0000000000000d";
  printf("%d\n", strrindex(good3, 15, pattern));
  return 0;
}

// strindex: return the rightmost index of t in s, -1 if not found.
// start at the right and go left until either the beginning of the string occurs or
// a match is found
int strrindex(char s[], int s_len, char t[])
{
  int i, j, k;

  for (i = s_len-1; i > 0; i--)
  {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
    {
      // noop
    }
    if ((k > 0) && (t[k] == '\0'))
    {
      return i;
    }
  }
  return -1;
}