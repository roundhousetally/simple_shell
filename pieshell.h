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
#include <string.h>

/** Launch Function */
void runit(char **test, char **envp, char *zero);
void moneyp(void);
void getpath(char **s, char **envp, char *zero);
void pathhelp(char **s, char *path, char **envp, char *zero);
int pathexec(char **s, char **tokedpath, char **envp, int i);

/** Utility Functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);
int _arraylength(char *string, const char *delim);
char **strtotok(char *s, const char *delim);
void freestrtok(char **string);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void notfound(char *zero, char *file);

#endif
