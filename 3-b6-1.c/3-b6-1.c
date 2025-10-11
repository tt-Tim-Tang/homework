//2453805 ÌÆÏÈÔó µçÐÅ
# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main()
{
    double num;
    int num_1, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_10, decimal_part, num_11, num_12;
    int num_2;
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
    scanf("%lf", &num);
    printf("´óÐ´½á¹ûÊÇ:\n");
    num_1 = (int)(num / 1000000000);
    num_2 = (int)((num - num_1 * 1000000000.0) / 100000000);
    num_3 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0) / 10000000);
    num_4 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0) / 1000000);
    num_5 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0) / 100000);
    num_6 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0) / 10000);
    num_7 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0) / 1000);
    num_8 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0) / 100);
    num_9 = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0) / 10);
    num_10 = (int)(num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0);
    decimal_part = (int)((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0 - num_10 * 1.0) * 100 + 0.5);
    num_11 = decimal_part / 10;
    num_12 = decimal_part - 10 * num_11;
    // Ê®ÒÚ-ÒÚ
    bool has_billion = false;
    switch (num_1) {
    case 9:
       printf("¾ÁÊ°");
        break;
    case 8:
        printf("°ÆÊ°");
        break;
    case 7:
        printf("ÆâÊ°");
        break;
    case 6:
        printf("Â½Ê°");
        break;
    case 5:
        printf("ÎéÊ°");
        break;
    case 4:
        printf("ËÁÊ°");
        break;
    case 3:
        printf("ÈþÊ°");
        break;
    case 2:
        printf("·¡Ê°");
        break;
    case 1:
        printf("Ò¼Ê°");
        break;
    case 0:
        break;
    }
    switch (num_2) {
    case 9:
        printf("¾Á");
        break;
    case 8:
        printf("°Æ");
        break;
    case 7:
        printf("Æâ");
        break;
    case 6:
        printf("Â½");
        break;
    case 5:
        printf("Îé");
        break;
    case 4:
        printf("ËÁ");
        break;
    case 3:
        printf("Èþ");
        break;
    case 2:
        printf("·¡");
        break;
    case 1:
        printf("Ò¼");
        break;
    case 0:
        break;
    }
    if (num_1 != 0 || num_2 != 0) {
        printf("ÒÚ");
        has_billion = true;
    }

    // Ç§Íò-Íò
    bool has_wan = false;
    if (has_billion) {
        switch (num_3) {
        case 9:
            printf("¾ÁÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 0:
            break;
        }
        if (num_4 == 0 && (num_5 != 0 || num_6 != 0)) {
            printf ("Áã");
        }
        if (num_3 == 0 && num_4 != 0) {
            printf ("Áã");
        }

        switch (num_4) {
        case 9:
            printf("¾Á°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 0:
            break;
        }
        if (num_4 != 0 && num_5 == 0 && num_6 != 0) {
            printf("Áã");
        }
        switch (num_5) {
        case 9:
            printf("¾ÁÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 0:
            break;
        }
        switch (num_6) {
        case 9:
            printf("¾Á");
            break;
        case 8:
            printf("°Æ");
            break;
        case 7:
            printf("Æâ");
            break;
        case 6:
            printf("Â½");
            break;
        case 5:
            printf("Îé");
            break;
        case 4:
            printf("ËÁ");
            break;
        case 3:
            printf("Èþ");
            break;
        case 2:
            printf("·¡");
            break;
        case 1:
            printf("Ò¼");
            break;
        case 0:
            break;
        }

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            printf("Íò");
            has_wan = true;
        }
    }
    if (has_billion == false) {
        switch (num_3) {
        case 9:
            printf("¾ÁÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 0:
            break;
        }

        switch (num_4) {
        case 9:
            printf("¾Á°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 0:
            break;
        }
        if (num_3 != 0 && num_4 == 0 && (num_5 != 0 || num_6 != 0)) {
            printf("Áã");
        }
        if (num_4 != 0 && num_5 == 0 && num_6 != 0) {
            printf("Áã");
        }
        switch (num_5) {
        case 9:
            printf("¾ÁÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 0:
            break;
        }
        switch (num_6) {
        case 9:
            printf("¾Á");
            break;
        case 8:
            printf("°Æ");
            break;
        case 7:
            printf("Æâ");
            break;
        case 6:
            printf("Â½");
            break;
        case 5:
            printf("Îé");
            break;
        case 4:
            printf("ËÁ");
            break;
        case 3:
            printf("Èþ");
            break;
        case 2:
            printf("·¡");
            break;
        case 1:
            printf("Ò¼");
            break;
        case 0:
            break;
        }

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            printf("Íò");
            has_wan = true;
        }
    }

    // Ç§-Ô²
    if (has_billion || has_wan) {
        switch (num_7) {
        case 9:
            printf("¾ÁÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 0:
            break;
        }
        if (num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            printf("Áã");
        }
        if (num_7 == 0 && num_8 != 0) {
            printf("Áã");
        }
        switch (num_8) {
        case 9:
            printf("¾Á°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 0:
            break;
        }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            printf("Áã");
        }
        switch (num_9) {
        case 9:
            printf("¾ÁÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 0:
            break;
        }
        switch (num_10) {
        case 9:
            printf("¾Á");
            break;
        case 8:
            printf("°Æ");
            break;
        case 7:
            printf("Æâ");
            break;
        case 6:
            printf("Â½");
            break;
        case 5:
            printf("Îé");
            break;
        case 4:
            printf("ËÁ");
            break;
        case 3:
            printf("Èþ");
            break;
        case 2:
            printf("·¡");
            break;
        case 1:
            printf("Ò¼");
            break;
        case 0:
            break;
        }
        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
            printf("Ô²");
        }
        else if (has_billion || has_wan) {
            printf("Ô²");
        }
    }
    if (has_billion == false && has_wan == false) {
        switch (num_7) {
        case 9:
            printf("¾ÁÇª");
            break;
        case 8:
            printf("°ÆÇª");
            break;
        case 7:
            printf("ÆâÇª");
            break;
        case 6:
            printf("Â½Çª");
            break;
        case 5:
            printf("ÎéÇª");
            break;
        case 4:
            printf("ËÁÇª");
            break;
        case 3:
            printf("ÈþÇª");
            break;
        case 2:
            printf("·¡Çª");
            break;
        case 1:
            printf("Ò¼Çª");
            break;
        case 0:
            break;
        }
        switch (num_8) {
        case 9:
            printf("¾Á°Û");
            break;
        case 8:
            printf("°Æ°Û");
            break;
        case 7:
            printf("Æâ°Û");
            break;
        case 6:
            printf("Â½°Û");
            break;
        case 5:
            printf("Îé°Û");
            break;
        case 4:
            printf("ËÁ°Û");
            break;
        case 3:
            printf("Èþ°Û");
            break;
        case 2:
            printf("·¡°Û");
            break;
        case 1:
            printf("Ò¼°Û");
            break;
        case 0:
            break;
        }
        if (num_7 != 0 && num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            printf("Áã");
        }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            printf("Áã");
        }
        switch (num_9) {
        case 9:
            printf("¾ÁÊ°");
            break;
        case 8:
            printf("°ÆÊ°");
            break;
        case 7:
            printf("ÆâÊ°");
            break;
        case 6:
            printf("Â½Ê°");
            break;
        case 5:
            printf("ÎéÊ°");
            break;
        case 4:
            printf("ËÁÊ°");
            break;
        case 3:
            printf("ÈþÊ°");
            break;
        case 2:
            printf("·¡Ê°");
            break;
        case 1:
            printf("Ò¼Ê°");
            break;
        case 0:
            break;
        }
        switch (num_10) {
        case 9:
            printf("¾Á");
            break;
        case 8:
            printf("°Æ");
            break;
        case 7:
            printf("Æâ");
            break;
        case 6:
            printf("Â½");
            break;
        case 5:
            printf("Îé");
            break;
        case 4:
            printf("ËÁ");
            break;
        case 3:
            printf("Èþ");
            break;
        case 2:
            printf("·¡");
            break;
        case 1:
            printf("Ò¼");
            break;
        case 0:
            break;
        }
        if (num_7 == 0 && num_8 == 0 && num_9 == 0 && num_10 == 0 && num_11 == 0 && num_12 == 0) {
            printf("ÁãÔ²");
        }

        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
            printf("Ô²");
        }
        else if (has_billion || has_wan) {
            printf("Ô²");
        }
    }


    // Ð¡Êý²¿·Ö
    if (num_11 != 0 || num_12 != 0) {
        switch (num_11) {
        case 9:
            printf ("¾Á½Ç");
            break;
        case 8:
            printf("°Æ½Ç");
            break;
        case 7:
            printf("Æâ½Ç");
            break;
        case 6:
            printf("Â½½Ç"); 
            break;
        case 5:
            printf("Îé½Ç");
            break;
        case 4: 
            printf("ËÁ½Ç"); 
            break;
        case 3:
            printf("Èþ½Ç");
            break;
        case 2:
            printf ("·¡½Ç");
            break;
        case 1: 
            printf ("Ò¼½Ç");
            break;
        case 0:
            break;
        }
        if (num_12 == 0) {
            printf("Õû");
        }
        if (((has_billion || has_wan) || (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0)) && num_11 == 0 && num_12 != 0) {
            printf("Áã");
        }
        switch (num_12) {
        case 9:
            printf("¾Á·Ö");
            break;
        case 8:
            printf("°Æ·Ö"); 
            break;
        case 7:
            printf("Æâ·Ö");
            break;
        case 6: 
            printf("Â½·Ö"); 
            break;
        case 5:
            printf("Îé·Ö"); 
            break;
        case 4:
            printf("ËÁ·Ö");
            break;
        case 3:
            printf("Èþ·Ö");
            break;
        case 2:
            printf("·¡·Ö");
            break;
        case 1:
            printf("Ò¼·Ö");
            break;
        case 0:
            break;
        }
    }
    else {
        printf("Õû");
    }

    printf ("\n");
    return 0;

}
