#ifndef _LIBS_HEAD_
#define _LIBS_HEAD_

#define SH_BUFFER 1024


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

void sh_active(void);
void sh_passive(void);

#endif
