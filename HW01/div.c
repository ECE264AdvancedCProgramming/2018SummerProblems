#include "pe01.h"
#ifdef TEST_DIV
long divop (long a, long b)
{
  if (b == 0)
    {
      fprintf(stderr, "divided by zero\n");
      return 0;
    }
  return (a / b);
}
#endif
