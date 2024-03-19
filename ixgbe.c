#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>
#include <sys/types.h>
#include <L0/sym_lib.h>
#include <L1/stack_switch.h>

extern int han_ixgbe_test(unsigned int i);
extern int han_ixgbe_poll(unsigned int i, int budget);

int
main(int argc, char **argv)
{
  int rc;
  int i;
  unsigned int mcpu;
  int count;

  count = atoi(argv[1]);
  
  mcpu = sched_getcpu();
  printf("count=%d sched_getcpu = %u\n", count, mcpu);

  while (count) {
    SYM_ON_KERN_STACK();
    
    //rc=han_ixgbe_test(mcpu);
    rc=han_ixgbe_poll(mcpu, 1);
    
    SYM_ON_USER_STACK();
    sleep(1);
    count --;
  }
  printf("rc=%d\n", rc);
  return rc;
}

