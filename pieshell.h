#ifndef PIESHELL_H
#define PIESHELL_H
/** Libs */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/** Launch Function */
void runit(char *test, char **envp);

/** Utility Functions */
int _strlen(char *s);

#endif
