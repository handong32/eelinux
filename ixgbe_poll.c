#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>
#include <sys/types.h>
#include <L0/sym_lib.h>
#include <L1/stack_switch.h>

extern int ixgbe_sym_hello(unsigned int i);
extern int ixgbe_sym_poll(unsigned int i, int budget);

int
main(int argc, char **argv)
{
  int rc;
  unsigned int i;
  unsigned int mcpu;
  int count;

  count = atoi(argv[1]);
  unsigned int ncpus = sysconf(_SC_NPROCESSORS_ONLN);
  
  mcpu = sched_getcpu();
  printf("count=%d sched_getcpu = %u ncpus=%u\n", count, mcpu, ncpus);
  
  while (count) {
    //rc=han_ixgbe_test(mcpu);
    //rc=han_ixgbe_poll(mcpu, 1);
    SYM_ON_KERN_STACK();
    for(i=0;i<ncpus;i++) {
      rc=ixgbe_sym_poll(i, 64);
    }        
    SYM_ON_USER_STACK();
    //sleep(1);
    //count --;
  }
  
  printf("rc=%d\n", rc);
  return 0;
}

