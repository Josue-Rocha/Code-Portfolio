/* library.c: string utilities library */

#include "str.h"

#include <ctype.h>
#include <string.h>

/**
 * Convert all characters in string to lowercase.
 * @param   s       String to convert
 **/
void	str_lower(char *s) {
    while(*s){
        *s = tolower(*s);
        s++;
    }
}

/**
 * Convert all characters in string to uppercase.
 * @param   s       String to convert
 **/
void	str_upper(char *s) {
    while(*s){
        *s =toupper(*s);
        s++;
    }
}

/**
 * Convert all characters in string to titlecase.
 * @param   s       String to convert
 **/
void	str_title(char *s) {
    *s = toupper(*s);
    char *c = s;
    s++;
    while(*s){
        if(!isalpha(*c)){
            *s = toupper(*s);
        }
        else if(isalpha(*c) && isalpha(*s)){
            *s = tolower(*s);
        }
        c++;
        s++;
    }
}

/**
 * Removes trailing newline (if present).
 * @param   s       String to modify
 **/
void    str_chomp(char *s) {
    int len = strlen(s);
    char *c = s;
    c += len;
    s += len -1;
    if ((*s == '\n') && (*c == '\0')){
        *s = '\0';
        //s++;
        //*s = '';
    }
}

/**
 * Removes whitespace from front and back of string (if present).
 * @param   s       String to modify
 **/
void    str_strip(char *s) {
    int len = strlen(s);
    char *h = s;
    char *t = s + len-1;

    while(isspace(*h)){
        h++;
    }
    while((isspace(*t)) && t >= h){
        t--;
    }
    *(t+1) = '\0';
    while(*h){
        *s = *h;
        h++;
        s++;
    }
    *s = '\0';
}

/**
 * Reverses a string.
 * @param   s       String to reverse
 **/
void    str_reverse(char *s) {
    int len = strlen(s);
    char *c = s + len -1;

    while(s < c){
        char temp = *s;
        *s = *c;
        *c = temp;

        s++;
        c--;
    }
}

/**
 * Deletes characters from a string.
 * @param   s       String to reverse
 * @param   from    String with letters to remove
 **/
void    str_delete(char *s, char *from) {
    int table[1<<8] = {0};
    char *f = from;
    while(*f){
        table[(int)(*f)] = 1;
        f++;
    }
    char *p = s;
    while(*p){
        if(!table[(int)(*p)]){
            *s = *p;
            s++;
        }
        p++;
    }
    *s = '\0';
}

/**
 * Replaces all instances of 'from' in 's' with corresponding values in 'to'.
 * @param   s       String to translate
 * @param   from    String with letters to replace
 * @param   to      String with corresponding replacment values
 **/
void    str_translate(char *s, char *from, char *to) {
    char *f = from;
    char *t = to;
    char table[1<<8] = {0};
    while(*f){
        table[(int)(*f)] = *t;
        f++;
        t++;
    }
    while(*s){
        if(table[(int)(*s)]){
            *s = table[(int)(*s)];
        }
        s++;
    }
}

/* vim: set sts=4 sw=4 ts=8 expandtab ft=c: */
