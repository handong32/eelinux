#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <L0/sym_lib.h>
#include <L1/stack_switch.h>

extern int ixgbe_sym_hello(unsigned int);

int
main(int argc, char **argv)
{
  int rc;
  unsigned int mcpu;
  mcpu = sched_getcpu();
  printf("sched_getcpu=%u\n", mcpu);
  
  SYM_ON_KERN_STACK();
  rc = ixgbe_sym_hello(mcpu);
  SYM_ON_USER_STACK();

  return 0;
}

