#include "my_functions.h"
int str_len(const char *str);

int str_ncomp(char *s1, char *s2, int c)
{
  int i,first,second,t,n;
  i = 0;
  t = 0;
  first=str_len(s1);
  second=str_len(s2);
  n = (first >= second) ? first : second;
  n = (c > n) ? n : c;
  while(i<n)
  {
    if(s1[i]!=s2[i]) /*compare strings */
    {
      t=s1[i]-s2[i];
      break;
    }
    else{
      t=0;
    }
    i++;
  }
  return (t);
}
