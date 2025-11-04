#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include <windows.h>

typedef struct Record {
    char author[12];
    char title[32];
    char publisher [16];
    unsigned short year;
    unsigned short pages;
} Record;

Record * readDB ();


#endif