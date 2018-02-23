#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

/*
Extend atof to handle scientific notation of the form 123.45e-6 
where a floating-point number may be followed by e or E and an 
optionally signed exponent.
*/

double atof(char s[]);
int atoi(char s[]);
int mygetline(char s[], int max);
float mypow(float exp, float base);

// atof() - convert string s to double
double atof(char s[])
{
    char sn_exp[MAXLINE];
    double val, power;
    int i, j, sign, sn_sign, sn_val;

    for (i = 0; isspace(s[i]); i++){} // no-op, skip whitespace

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.')
    {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // call atoi() on the remaining values in the string,
    // and combine result to our power converstion depending
    // on its sign.
    if (s[i] == 'e' || s[i] == 'E')
    {

        i++;
        if (s[i] == '-') 
        {
            sn_sign = 1;
            i++;
        } else {
            sn_sign = 0;
        }
        for (j = 0; isdigit(s[i]); i++, j++)
        {
            sn_exp[j] = s[i];
        }
        sn_exp[j] = '\0';

        sn_val = atoi(sn_exp);

        // Normally for scientific notation, you
        // multiply for positive exponents, but
        // we are dividing in the return statement 
        // of atof(), so multiplying power by 10 
        // here makes the returned value smaller.
        if (sn_sign)
        {
            while (sn_val > 0)
            {
                power *= 10.0;
                sn_val--;
            }
        } 
        else {
            while (sn_val > 0)
            {
                power /= 10.0;
                sn_val--;
            }
        }
    }

    return sign * (val / power);
}

// atoi: convert string s to integer using atof
int atoi(char s[])
{
    double atof(char s[]);
    return (int) atof(s);
}

// mygetline(): get line into s, return length
int mygetline(char s[], int max)
{
  int c, i;
  i = 0;

  while ((--max > 0) && ((c=getchar()) != EOF) && (c != '\n'))
  {
    s[i++] = c;
  }
  if (c == '\n')
  {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
int main() {
    double sum;
    char line[MAXLINE];

    while (mygetline(line, MAXLINE) > 0)
    {
        printf("%f\n", atof(line));
    }
   
    return 0;
}
