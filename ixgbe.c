#include <stdio.h>
#include <sys/types.h>
#include <L0/sym_lib.h>
#include <L1/stack_switch.h>

extern int ixgbe_test(unsigned int i);

int
main(int argc, char **argv)
{
  int rc;
  int i;

  SYM_ON_KERN_STACK();
  rc=ixgbe_test(1234);
  SYM_ON_USER_STACK();

  printf("rc=%d\n", rc);
  return rc;
}

