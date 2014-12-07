/* 
 * File:   strings.h
 * Author: antoniocs
 *
 * Created on 23 de Novembro de 2014, 17:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#ifndef STRINGS_H
#define	STRINGS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DYNSTR_INIT_SIZE 15
#define DYNSTR_READ_FILE_BUFFER_SIZE 1024

typedef struct dynstr {
    char *str;

    int size; //Total size of reserved memory for string
    int length; //Actual length of the string. Add 1 for the \0

    int increase_by; //will have the default of 15 but can be customized per instance
} dynstr, *pdynstr;

pdynstr dynstr_init(char *);
void dynstr_add_char(pdynstr, int);
void dynstr_add_str(pdynstr, char *);
void dynstr_add_str_num(pdynstr, char *, int);
void dynstr_resize(pdynstr);
void dynstr_destroy(pdynstr);
void dynstr_clear(pdynstr);
char *dynstr_text(pdynstr);

#ifdef	__cplusplus
}
#endif

#endif	/* STRINGS_H */

