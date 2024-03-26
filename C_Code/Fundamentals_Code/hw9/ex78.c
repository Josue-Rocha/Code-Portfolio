// ex78.c
// using a random number generator (RNG)
#include <stdio.h>  
#include <stdlib.h>  // needed for rand() and srand()
#include <time.h>    // needed for time()

int main()
{
  int n;

  srand(time(0));  // set up the seed for the RNG 

  // generate 5 random integers between 0 and 9
  for (int i = 1; i <= 10; i++) {
    n = rand()%20; 
    printf("%d\n", n);
  }

  return 0;
}

