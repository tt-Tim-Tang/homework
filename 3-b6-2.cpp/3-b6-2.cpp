//2453805 ÌÆÏÈÔó µçĞÅ
#include<iostream>
using namespace std;
int main()
{
    double num;
    int num_1, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_10, decimal_part, num_11, num_12;
    int num_2;
    cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
    cin >> num;
    cout << "´óĞ´½á¹ûÊÇ:" << endl;
    num_1 = int(num / 1000000000);
    num_2 = int((num - num_1 * 1000000000.0) / 100000000);
    num_3 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0) / 10000000);
    num_4 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0) / 1000000);
    num_5 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0) / 100000);
    num_6 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0) / 10000);
    num_7 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0) / 1000);
    num_8 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0) / 100);
    num_9 = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0) / 10);
    num_10 = int(num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0);
    decimal_part = int((num - num_1 * 1000000000.0 - num_2 * 100000000.0 - num_3 * 10000000.0 - num_4 * 1000000.0 - num_5 * 100000.0 - num_6 * 10000.0 - num_7 * 1000.0 - num_8 * 100.0 - num_9 * 10.0 - num_10 * 1.0) * 100 + 0.5);
    num_11 = decimal_part / 10;
    num_12 = decimal_part - 10 * num_11;
    // Ê®ÒÚ-ÒÚ
    bool has_billion = false;
    switch (num_1) {
    case 9:
        cout << "¾ÁÊ°";
        break;
    case 8: 
        cout << "°ÆÊ°";
        break;
    case 7: 
        cout << "ÆâÊ°"; 
        break;
    case 6:
        cout << "Â½Ê°";
        break;
    case 5:
        cout << "ÎéÊ°";
        break;
    case 4:
        cout << "ËÁÊ°";
        break;
    case 3:
        cout << "ÈşÊ°";
        break;
    case 2:
        cout << "·¡Ê°";
        break;
    case 1:
        cout << "Ò¼Ê°";
        break;
    case 0:
        break;
    }
    switch (num_2) {
    case 9:
        cout << "¾Á"; 
        break;
    case 8:
        cout << "°Æ";
        break;
    case 7:
        cout << "Æâ";
        break;
    case 6:
        cout << "Â½"; 
        break;
    case 5:
        cout << "Îé"; 
        break;
    case 4:
        cout << "ËÁ";
        break;
    case 3:
        cout << "Èş";
        break;
    case 2:
        cout << "·¡";
        break;
    case 1:
        cout << "Ò¼"; 
        break;
    case 0:
        break;
    }
    if (num_1 != 0 || num_2 != 0) {
        cout << "ÒÚ";
        has_billion = true;
    }

    // Ç§Íò-Íò
    bool has_wan = false;
    if (has_billion) {
        switch (num_3) {
        case 9:
            cout << "¾ÁÇª";
            break;
        case 8:
            cout << "°ÆÇª";
            break;
        case 7:
            cout << "ÆâÇª"; 
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 4:
            cout << "ËÁÇª"; 
            break;
        case 3:
            cout << "ÈşÇª"; 
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 0:
            break;
        }
        if(num_4==0&&(num_5!=0||num_6!=0)){
            cout << "Áã";
        }
        if (num_3 == 0 && num_4 != 0) {
            cout << "Áã";
        }

        switch (num_4) {
        case 9:
            cout << "¾Á°Û";
            break;
        case 8:
            cout << "°Æ°Û";
            break;
        case 7:
            cout << "Æâ°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 3:
            cout << "Èş°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 0:
            break;
        }
        if (num_4!=0&&num_5==0&&num_6!=0){
            cout << "Áã";
        }
        switch (num_5) {
        case 9:
            cout << "¾ÁÊ°";
            break;
        case 8:
            cout << "°ÆÊ°";
            break;
        case 7:
            cout << "ÆâÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 3:
            cout << "ÈşÊ°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 0:
            break;
        }
        switch (num_6) {
        case 9:
            cout << "¾Á";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 6:
            cout << "Â½";
            break;
        case 5:
            cout << "Îé";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 3:
            cout << "Èş";
            break;
        case 2:
            cout << "·¡";
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 0:
            break;
        }

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            cout << "Íò";
            has_wan = true;
        }
    }
    if (has_billion == false) {
        switch (num_3) {
        case 9:
            cout << "¾ÁÇª";
            break;
        case 8:
            cout << "°ÆÇª";
            break;
        case 7:
            cout << "ÆâÇª";
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 4:
            cout << "ËÁÇª";
            break;
        case 3:
            cout << "ÈşÇª";
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 0:
            break;
        }

        switch (num_4) {
        case 9:
            cout << "¾Á°Û";
            break;
        case 8:
            cout << "°Æ°Û";
            break;
        case 7:
            cout << "Æâ°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 3:
            cout << "Èş°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 0:
            break;
        }
        if (num_3 != 0 && num_4 == 0 && (num_5 != 0 || num_6 != 0)) {
            cout << "Áã";
        }
        if (num_4 != 0 && num_5 == 0 && num_6 != 0) {
            cout << "Áã";
        }
        switch (num_5) {
        case 9:
            cout << "¾ÁÊ°";
            break;
        case 8:
            cout << "°ÆÊ°";
            break;
        case 7:
            cout << "ÆâÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 3:
            cout << "ÈşÊ°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 0:
            break;
        }
        switch (num_6) {
        case 9:
            cout << "¾Á";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 6:
            cout << "Â½";
            break;
        case 5:
            cout << "Îé";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 3:
            cout << "Èş";
            break;
        case 2:
            cout << "·¡";
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 0:
            break;
        }

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            cout << "Íò";
            has_wan = true;
        }
    }

    // Ç§-Ô²
    if (has_billion || has_wan) {
        switch (num_7) {
        case 9:
            cout << "¾ÁÇª";
            break;
        case 8:
            cout << "°ÆÇª";
            break;
        case 7:
            cout << "ÆâÇª";
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 4:
            cout << "ËÁÇª";
            break;
        case 3:
            cout << "ÈşÇª";
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 0:
            break;
        }
        if (num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            cout << "Áã";
        }
        if (num_7 == 0 && num_8 != 0) {
            cout << "Áã";
        }
        switch (num_8) {
        case 9:
            cout << "¾Á°Û";
            break;
        case 8:
            cout << "°Æ°Û";
            break;
        case 7:
            cout << "Æâ°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 3:
            cout << "Èş°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 0:
            break;
        }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            cout << "Áã";
        }
        switch (num_9) {
        case 9:
            cout << "¾ÁÊ°";
            break;
        case 8:
            cout << "°ÆÊ°";
            break;
        case 7:
            cout << "ÆâÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 3:
            cout << "ÈşÊ°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 0:
            break;
        }
        switch (num_10) {
        case 9:
            cout << "¾Á";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 6:
            cout << "Â½";
            break;
        case 5:
            cout << "Îé";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 3:
            cout << "Èş";
            break;
        case 2:
            cout << "·¡";
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 0:
            break;
        }
        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
            cout << "Ô²";
        }
        else if (has_billion || has_wan) {
            cout << "Ô²";
        }
    }
    if (has_billion==false && has_wan==false) {
        switch (num_7) {
        case 9:
            cout << "¾ÁÇª";
            break;
        case 8:
            cout << "°ÆÇª";
            break;
        case 7:
            cout << "ÆâÇª";
            break;
        case 6:
            cout << "Â½Çª";
            break;
        case 5:
            cout << "ÎéÇª";
            break;
        case 4:
            cout << "ËÁÇª";
            break;
        case 3:
            cout << "ÈşÇª";
            break;
        case 2:
            cout << "·¡Çª";
            break;
        case 1:
            cout << "Ò¼Çª";
            break;
        case 0:
            break;
        }
        switch (num_8) {
        case 9:
            cout << "¾Á°Û";
            break;
        case 8:
            cout << "°Æ°Û";
            break;
        case 7:
            cout << "Æâ°Û";
            break;
        case 6:
            cout << "Â½°Û";
            break;
        case 5:
            cout << "Îé°Û";
            break;
        case 4:
            cout << "ËÁ°Û";
            break;
        case 3:
            cout << "Èş°Û";
            break;
        case 2:
            cout << "·¡°Û";
            break;
        case 1:
            cout << "Ò¼°Û";
            break;
        case 0:
            break;
        }
        if (num_7 != 0 && num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            cout << "Áã";
    }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            cout << "Áã";
        }
        switch (num_9) {
        case 9:
            cout << "¾ÁÊ°";
            break;
        case 8:
            cout << "°ÆÊ°";
            break;
        case 7:
            cout << "ÆâÊ°";
            break;
        case 6:
            cout << "Â½Ê°";
            break;
        case 5:
            cout << "ÎéÊ°";
            break;
        case 4:
            cout << "ËÁÊ°";
            break;
        case 3:
            cout << "ÈşÊ°";
            break;
        case 2:
            cout << "·¡Ê°";
            break;
        case 1:
            cout << "Ò¼Ê°";
            break;
        case 0:
            break;
        }
        switch (num_10) {
        case 9:
            cout << "¾Á";
            break;
        case 8:
            cout << "°Æ";
            break;
        case 7:
            cout << "Æâ";
            break;
        case 6:
            cout << "Â½";
            break;
        case 5:
            cout << "Îé";
            break;
        case 4:
            cout << "ËÁ";
            break;
        case 3:
            cout << "Èş";
            break;
        case 2:
            cout << "·¡";
            break;
        case 1:
            cout << "Ò¼";
            break;
        case 0:
            break;
        }
        if (num_7 == 0 && num_8 == 0 && num_9 == 0 && num_10 == 0 && num_11 == 0 && num_12 == 0) {
            cout << "ÁãÔ²";
        }
        
        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
           cout << "Ô²";
        }
        else if (has_billion || has_wan) {
           cout << "Ô²";
        }
   }


    // Ğ¡Êı²¿·Ö
    if (num_11 != 0 || num_12 != 0) {
        switch (num_11) {
        case 9:
            cout << "¾Á½Ç";
            break;
        case 8: 
            cout << "°Æ½Ç";
            break;
        case 7: 
            cout << "Æâ½Ç"; 
            break;
        case 6:
            cout << "Â½½Ç"; 
            break;
        case 5:
            cout << "Îé½Ç"; 
            break;
        case 4:
            cout << "ËÁ½Ç";
            break;
        case 3: 
            cout << "Èş½Ç"; 
            break;
        case 2:
            cout << "·¡½Ç";
            break;
        case 1:
            cout << "Ò¼½Ç";
            break;
        case 0:
            break;
        }
        if (num_12 == 0) {
            cout << "Õû" ;
        }
        if (((has_billion || has_wan)|| (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0)) && num_11 == 0 && num_12 != 0) {
            cout << "Áã";
        }
        switch (num_12) {
        case 9: 
            cout << "¾Á·Ö";
            break;
        case 8: 
            cout << "°Æ·Ö"; 
            break;
        case 7:
            cout << "Æâ·Ö";
            break;
        case 6: 
            cout << "Â½·Ö";
            break;
        case 5:
            cout << "Îé·Ö"; 
            break;
        case 4: 
            cout << "ËÁ·Ö";
            break;
        case 3: 
            cout << "Èş·Ö";
            break;
        case 2: 
            cout << "·¡·Ö";
            break;
        case 1:
            cout << "Ò¼·Ö";
            break;
        case 0: 
            break;
        }
    }
    else {
        cout << "Õû";
    }

    cout << endl;
    return 0;

}
