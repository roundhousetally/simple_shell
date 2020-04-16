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
int runit(char **test, char **envp, char *zero, int count);
void moneyp(void);
int getpath(char **s, char **envp, char *zero, int count);
int pathhelp(char **s, char *path, char **envp, char *zero, int count);
int pathexec(char **s, char **tokedpath, char **envp, int i, char *z, int c);
int builtins(char *buf, char **envp, char *filename, int count);

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
void notfound(char *zero, char *file, int count);
int comparepath(char **s, char **envp, int i, int n, char *zero, int count);
char *itos(int num);
int runexec(char **args, char **envp, char *zero, int count);
void denied(char *zero, char *file, int count);
int pathexechelp(pid_t pid, char **args);

#endif
