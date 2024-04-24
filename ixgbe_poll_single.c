#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>
#include <sys/types.h>
#include <L0/sym_lib.h>
#include <L1/stack_switch.h>

extern int ixgbe_sym_poll(unsigned int i, int budget);

int main(int argc, char **argv)
{
  int rc;
  unsigned int mcpu;
  int count=1;

  mcpu = atoi(argv[1]); 
  //mcpu = sched_getcpu();
  printf("count=%d sched_getcpu=%u\n", count, mcpu);
  
  while (count) {
    SYM_ON_KERN_STACK();
    rc=ixgbe_sym_poll(mcpu, 64);
    SYM_ON_USER_STACK();
  }
  
  printf("rc=%d\n", rc);
  return 0;
}

