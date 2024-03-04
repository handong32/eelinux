#include <sys/types.h>
#include <L0/sym_lib.h>

#define __user
extern ssize_t ksys_write(unsigned int fd, const char __user *buf, size_t count);

char mystr[]="hello world!!\n";

int
main(int argc, char **argv)
{
  int rc;
  
  sym_elevate();
  rc=ksys_write(1, mystr, 14);
  sym_lower();
  
  return rc;
}
  

 


