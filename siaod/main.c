#include <stdio.h>
#include <stdlib.h>
#include "pr1.h"
#include "pr2.h"
#include "pr3.h"
#include "pr4.h"
#include "pr5.h"

#define CLEAR() system("cls||clear")

int main () {
    int menu;
    
    do {
        printf("Введите номер работы, которую хотите запустить(0 - Выход): ");
        scanf("%d", &menu);
        CLEAR();
        switch(menu)
        {
            case 1 :
                run_pr1();
                break;
            case 2 :
                run_pr2();
                break;
            case 3 :
                run_pr3();
                break;
            case 4 :
                run_pr4();
                break;
            case 5 :
                run_pr5();
                break;
            case 0 :
                return 0;
            default : printf("неверный режим\n");
        }
        
        printf("\n");
        scanf("%d", &menu);

    } while (!(menu == 0));

   return 0;
}
