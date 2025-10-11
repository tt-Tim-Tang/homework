//2453805 唐先泽 电信

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p=str;
    int len = 0;
    if (str == NULL) {
        return 0;
    }
    while (*p) {
        len++;
        p++;
    }
    return len;
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2追加到s1后面,含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p1 = s1;
    const char* p2 = s2;
    int len_1 = tj_strlen(s1);
    if (s1 == NULL) {
        return NULL;
    }
    if (s2 == NULL) {
        return s1;
    }
    p1=p1 + len_1;
    while (*p2) {
        *p1 = *p2;
        p1++;
        p2++;
    }
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：将字符串s2的前len个字符追加到s1后面，并添加\0,若len比s2长度大，则追加整个s2（含\0)
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL) {
        return NULL;
    }
    else if (s2 == NULL) {
        return s1;
    }
    else if (len >= tj_strlen(s2)) {
        tj_strcat(s1, s2);
    }
    else {
        p1 += tj_strlen(s1);
        for (; p2 - s2 + 1 <= len;p1++, p2++) {
            *p1 = *p2;
        }
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：将字符串 s2 复制到s1 中，覆盖 s1 中原内容，复制时包含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL) {
        return NULL;
    }
    else if (s2 == NULL) {
        *p1 = '\0';
        return s1;
    }
    else {
        for (; *p2 != '\0'; p1++, p2++) {
            *p1 = *p2;
        }
        *p1 = '\0';
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    char* p1 = s1;
    const char* p2 = s2;
    
    if (s1 == NULL) {
        return NULL;
    }
    if (s2 == NULL) {
        return s1;
    }
    for (; p2 - s2 < (len>tj_strlen(s2)?tj_strlen(s2):len); p1++, p2++) {
        *p1 = *p2;
    }


    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL) {
        return -1;
    }
    if (s1 != NULL && s2 == NULL) {
        return 1;
    }
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
    }
    if (*p1 != *p2) {
        return *p1 - *p2;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL) {
        return -1;
    }
    if (s1 != NULL && s2 == NULL) {
        return 1;
    }
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    while (*p1 != '\0' && *p2 != '\0') {
        char temp1 = *p1, temp2 = *p2;
        if (*p1 >= 'A' && *p1 <= 'Z') {
            temp1 = *p1 + 32;
        }
        if (*p2 >= 'A' && *p2 <= 'Z') {
            temp2 = *p2 + 32;
        }
        if (temp1 != temp2) {
            return temp1 - temp2;
        }
        p1++;
        p2++;
    }
    if (*p1 != *p2) {
        char temp1 = *p1, temp2 = *p2;
        if (*p1 >= 'A' && *p1 <= 'Z') {
            temp1 = *p1 + 32;
        }
        if (*p2 >= 'A' && *p2 <= 'Z') {
            temp2 = *p2 + 32;
        }
        return temp1 - temp2;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL) {
        return -1;
    }
    if (s1 != NULL && s2 == NULL) {
        return 1;
    }
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    int min_len = tj_strlen(s1) < tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2);
    for (; p1 - s1 < (len > min_len ?( min_len + 1): len); p1++, p2++) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 != NULL) {
        return -1;
    }
    if (s1 != NULL && s2 == NULL) {
        return 1;
    }
    if (s1 == NULL && s2 == NULL) {
        return 0;
    }
    int min_len = tj_strlen(s1) < tj_strlen(s2) ? tj_strlen(s1) : tj_strlen(s2);
    for (; p1 - s1 < (len > min_len ? (min_len + 1) : len); p1++, p2++) {
        char temp1 = *p1, temp2 = *p2;
        if (*p1 >= 'A' && *p1 <= 'Z') {
            temp1 = *p1 + 32;
        }
        if (*p2 >= 'A' && *p2 <= 'Z') {
            temp2 = *p2 + 32;
        }
        if (temp1 != temp2) {
            return temp1 - temp2;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return NULL;
    }
    char* p = str;
    for (; *p != '\0'; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p -= 32;
        }
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return NULL;
    }
    char* p = str;
    for (; *p != '\0'; p++) {
        if (*p >= 'A' && *p <= 'Z') {
            *p += 32;
        }
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return 0;
    }
    const char* p = str;
    for (; *p != '\0'; p++) {
        if (*p == ch) {
            return p - str + 1;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    const char* p1 = str;
    int len =tj_strlen(substr);
    if (str == NULL || substr == NULL) {
        return 0;
    }
    for (; p1<=str+tj_strlen(str)-len+1; p1++) {
        const char* temp = p1;
        const char* p2 = substr;
        int sum = 0;
        for (; p2 - substr < len; p2++,temp++) {
            if (*temp == *p2) {
                sum++;
            }
            else {
                break;
            }
        }
        if (sum == len) {
            return p1 - str + 1;
        }
    }


    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return 0;
    }
    const char* p = str+tj_strlen(str)-1;
    for (; p>=str; p--) {
        if (*p == ch) {
            return p - str + 1;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(substr);
    const char* p1 = str + tj_strlen(str) - len + 1;
    if (str == NULL || substr == NULL) {
        return 0;
    }
    for (; p1>=str; p1--) {
        const char* temp = p1;
        const char* p2 = substr;
        int sum = 0;
        for (; p2 - substr < len; p2++, temp++) {
            if (*temp == *p2) {
                sum++;
            }
            else {
                break;
            }
        }
        if (sum == len) {
            return p1 - str + 1;
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL) {
        return NULL;
    }
    char* start = str;
    char* end = str + tj_strlen(str) - 1;
    while (start < end) {
        char* temp = start;
        *start = *end;
        *end = *temp;
        start++;
        end--;
    }
    return str;
}
