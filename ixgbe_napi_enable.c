#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <L0/sym_lib.h>
#include <L1/stack_switch.h>

extern void han_napi_enable(void);

int
main(int argc, char **argv)
{
  SYM_ON_KERN_STACK();
  han_napi_enable();
  SYM_ON_USER_STACK();

  return 0;
}

