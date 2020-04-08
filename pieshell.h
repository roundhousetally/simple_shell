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
void runit(char **test, char **envp);
void moneyp(void);

/** Utility Functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _putchar(char c);
int _arraylength(char *string, char *delim);
char **strtotok(char *s, char *delim);
void freestrtok(char **string);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif
