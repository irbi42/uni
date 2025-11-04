#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int minint (int *mass, int l)
{
    int min = 2147483647;
    int min_index = 0;
    for (int i = 0; i < l; i++)
    {
        if (mass [i] < min)
        {
            min = mass[i];
            min_index = i;
        };
    };
    return min_index;
}

int maxint (int *mass, int l)
{
    int max = -2147483648;
    int max_index = 0;
    for (int i = 0; i < l; i++)
    {
        if (mass [i] > max)
        {
            max = mass[i];
            max_index = i;
        };
    };
    return max_index;
}

void print_mass(int* mass, int l)
{
    for (int i = 0; i < l; i++) 
    {
        printf("%3d ", mass[i]);
    };   
   printf("\n");
    return;
}

void fill_mass(int *mass, int l, int mode)
{
    srand(time(NULL));
    switch(mode)
    {
        case 0 :
        {
            for (int i = 0; i < l; i++) 
            {
                mass[i] = i;

            };
            break;
        };
        case 1 :
        {
            for (int i = 0; i < l; i++) 
            {
                mass[i] = l - i;
            };
            break;
        }
        case 2 :
        {
            for (int i = 0; i < l; i++) 
            {
                mass[i] = rand()%20 - 8;
            };
            break;
        }
        case 3 :
        {
            for (int i = 0; i < l; i++) 
            {
                scanf("%d", &mass[i]);
            };
            break;
        }
        case 4 :
        {
            for (int i = 0; i < l; i++) 
            {
                int f = 0;
                int t;
                while (!f) {
                    t = rand()%l;
                    if (i == 0) break;
                    for (int j = 0; j < i; j++) {
                        if (mass[j] == t) break;
                        else if (j == (i - 1)) {
                            f = 1;
                        }
                    }
                };
                mass[i] = t;
            };
            break;
        };
    };

    return;
}

void copy_mass(int *copy, int *paste, int l)
{
    for (int i = 0; i < l; i++)
    {
        paste[i] = copy[i];
    }

    return;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int intl2 (int n)
{
    int i = 0;
    while (n >= 2)
    {
        n = n / 2;
        i++;
    }
    return i;
}


int seq_decr(int *mass,int l){
    int sequence = 1;  
    for (int i = 0; i < (l - 1); i++)
        if(mass[i] < mass[i + 1]) sequence++;
    return sequence;
}

int seq_incr(int *mass,int l){
    int sequence = 1;  
    for (int i = 0; i < (l - 1); i++)
        if(mass[i] > mass[i + 1]) sequence++;
    return sequence;
}

int check_sum(int *mass,int l){
    int sum = 0;
    for (int i = 0; i < l; i++)
        sum += mass[i];
    return sum;
}

