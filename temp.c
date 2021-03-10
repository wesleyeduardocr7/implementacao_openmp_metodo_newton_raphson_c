#include <omp.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  /* OpenMP does not provide a parallel while loop,
     so we're going to have to make one ourselves... */
  int sj, sstop, tn, tj, tstop;
  int foo(int j);
  omp_set_num_threads(8);

  /* Start carefully - we don't want all threads
     to (re!)initialize the two shared variables */
  sj = -1;     // shared loop counter
  sstop = 0;   // shared stopping condition

  #pragma omp parallel private(tn,tj,tstop)
  {
    tn = omp_get_thread_num();
    while (!sstop)
    {
      /* Threads update the shared counter by turns */
      #pragma omp critical
      {
        sj++;      // increment the shared loop counter...
        tj = sj;   // ...and keep a private copy of it
      }
      /* Threads evaulate function foo in parallel */
      tstop = foo(tj);
      /* Flip sstop for everyone if tstop is true in a thread */
      if (tstop)
      {
        sstop = 1;
        #pragma omp flush(sstop)
      }
      /* When sstop=1, most threads continue to this statment */
      printf("Thread %d, iteration %d, sstop=%d\n",tn,tj,sstop);
    }
  }
}
int foo(int j)
{
  /* This function simply compares counter j to its limit -
     a real code would likely do something more interesting  */
  int jmax=250, condition;
  condition = (j == jmax);
  usleep(100);   // usleep stands in for real work
  return condition;
}
