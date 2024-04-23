#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <L0/sym_lib.h>
#include <L1/stack_switch.h>

extern void ixgbe_sym_napi_disable(void);

int
main(int argc, char **argv)
{
  SYM_ON_KERN_STACK();
  ixgbe_sym_napi_disable();
  SYM_ON_USER_STACK();

  return 0;
}

