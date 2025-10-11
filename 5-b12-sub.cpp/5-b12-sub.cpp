//2453805 唐先泽 电信


/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：tj_strlen
  功    能：求字符串长度
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
    return len; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：将字符串s2连接到字符串s1的末尾,含'\0'
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(s1);
    int i = 0;
    while (s2[i] != '\0') {
        s1[len + i] = s2[i];
        i++;
    }
    s1[len + i] = s2[i];
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strncat
  功    能：将字符串s2的前len个字符追加到s1后面，并添加\0
  输入参数：
  返 回 值：
  说    明：若eln比s2的长度大，则追加整个s2即可，含\0
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (len > tj_strlen(s2)) {
        tj_strcat(s1, s2);
    }
    else {
        int len_s1 = tj_strlen(s1);
        for (int i = 0; i < len; i++) {
            s1[len_s1 + i] = s2[i];
        }
        s1[len_s1 + len] = '\0';
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcpy
  功    能：将字符串s2复制到s1中，覆盖s1中原内容，复制时包含\0
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(s2);
    for (int i = 0; i <= len; i++) {
        s1[i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{

    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

    int i = 0;
    while (s2[i] != '\0'&&i<len) {
        s1[i] = s2[i];  
        i++;
    }
    
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcmp
  功    能：
  输入参数：
  返 回 值：
  说    明：比较字符串s1和s2的大小，英文字母要区分大小写
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s2) : tj_strlen(s1);
    for (int i = 0; i <= len;i++) {
        if (s1[i] == s2[i]) {
            continue;
        }
        else {
            return s1[i] - s2[i];
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcasecmp
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s2) : tj_strlen(s1);
    


    for (int i = 0; i <= len; i++) {
        if (65 <= s1[i]&& s1[i] <= 90) {//s1大写
            if (65 <= s2[i]&& s2[i] <= 90) {//s2大写
                if (s1[i] == s2[i]) {
                    continue;
                }
                else {
                    return s1[i] - s2[i];
                }
            }
            else if(97 <= s2[i]&& s2[i] <= 122) {//s2小写
                if ((s1[i] + 32) == s2[i]) {
                    continue;
                }
                else {
                    return s1[i] + 32 - s2[i];
                }
            }
            else {//s2不是英文
                return s1[i] + 32 - s2[i];
            }
        }
        else if (97 <= s1[i] && s1[i] <= 122) {//s1小写
            if (65 <= s2[i]&& s2[i] <= 90) {//s2大写
                if (s1[i] == (s2[i]+32)) {
                    continue;
                }
                else {
                    return s1[i] - s2[i]-32;
                }
            }
            else if (97 <= s2[i]&& s2[i] <= 122) {//s2小写
                if (s1[i] == s2[i]) {
                    continue;
                }
                else {
                    return s1[i] - s2[i];
                }
            }
            else {//s2不是英文
                return s1[i] - s2[i];
            }

        }
        else {//s1不是英文
            if (65 <= s2[i]&&s2[i] <= 90) {//s2大写
                return s1[i] - s2[i] - 32;
            }
            else {
                if (s1[i] == s2[i]) {
                    continue;
                }
                else {
                    return s1[i] - s2[i];
                }

            }

        }

        
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strncmp
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min_len = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s2) : tj_strlen(s1);
    if (len > min_len) {
        for (int i = 0; i <= min_len; i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            else {
                return s1[i] - s2[i];
            }
        }
    }
    else {
        for (int i = 0; i < len; i++) {
            if (s1[i] == s2[i]) {
                continue;
            }
            else {
                return s1[i] - s2[i];
            }
        }
    }



    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcasencmp
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int min_len = tj_strlen(s1) > tj_strlen(s2) ? tj_strlen(s2) : tj_strlen(s1);
    if (len > min_len) {
		 return tj_strcasecmp(s1, s2);
    }
    else {
        for (int i = 0; i < len; i++) {
            if (65 <= s1[i] && s1[i] <= 90) {//s1大写
                if (65 <= s2[i] && s2[i] <= 90) {//s2大写
                    if (s1[i] == s2[i]) {
                        continue;
                    }
                    else {
                        return s1[i] - s2[i];
                    }
                }
                else if (97 <= s2[i] && s2[i] <= 122) {//s2小写
                    if ((s1[i] + 32) == s2[i]) {
                        continue;
                    }
                    else {
                        return s1[i] + 32 - s2[i];
                    }
                }
                else {//s2不是英文
                    return s1[i] + 32 - s2[i];
                }
            }
            else if (97 <= s1[i] && s1[i] <= 122) {//s1小写
                if (65 <= s2[i] && s2[i] <= 90) {//s2大写
                    if (s1[i] == (s2[i] + 32)) {
                        continue;
                    }
                    else {
                        return s1[i] - s2[i] - 32;
                    }
                }
                else if (97 <= s2[i] && s2[i] <= 122) {//s2小写
                    if (s1[i] == s2[i]) {
                        continue;
                    }
                    else {
                        return s1[i] - s2[i];
                    }
                }
                else {//s2不是英文
                    return s1[i] - s2[i];
                }

            }
            else {//s1不是英文
                if (65 <= s2[i] && s2[i] <= 90) {//s2大写
                    return s1[i] - s2[i] - 32;
                }
                else {
                    if (s1[i] == s2[i]) {
                        continue;
                    }
                    else {
                        return s1[i] - s2[i];
                    }

                }

            }


        }
    }

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strupr
  功    能：将字符串中所有小写字母转换为大写字母
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	for (int i = 0; i < tj_strlen(str); i++) {
		if (97 <= str[i] && str[i] <= 122) {//小写字母
			str[i] = str[i] - 32;
		}
	}
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strlwr
  功    能：将字符串中所有大写字母转换为小写字母
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	for (int i = 0; i < tj_strlen(str); i++) {
		if (65 <= str[i] && str[i] <= 90) {//大写字母
			str[i] = str[i] + 32;
		}
	}

    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strchr
  功    能：找出字符串中第一个出现的字符ch的位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	for (int i = 0; i < tj_strlen(str); i++) {
		if (str[i] == ch) {
			return i+1;
		}
	}
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strstr
  功    能：在字符串中查找子串substr第一次出现的位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = 0; i <= (tj_strlen(str) - tj_strlen(substr)); i++) {
        int sum = 0;
        for (int j = 0; j < tj_strlen(substr); j++) {
            if (str[j+i] == substr[j]) {
                sum++;
            }
            else {
                break;
            }
        }
        if (sum == tj_strlen(substr)) {
            return i+1;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strrchr
  功    能：在字符串str中寻找字符ch第一次出现的位置，顺序是从右到左
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = tj_strlen(str) - 1; i >= 0; i--) {
        if (ch == str[i]) {
            return i + 1;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strrstr
  功    能：在字符串str中寻找字符串substr第一次出现的位置
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    for (int i = (tj_strlen(str) - tj_strlen(substr)); i >= 0; i--) {
        int sum = 0;
        for (int j = 0; j < tj_strlen(substr); j++) {
            if (str[j + i] == substr[j]) {
                sum++;
            }
            else {
                break;
            }
        }
        if (sum == tj_strlen(substr)) {
            return i + 1;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strrev
  功    能：字符串反转，放入原串中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

    for (int i = 0; i < (tj_strlen(str) / 2); i++) {
        char temp = str[i];
        str[i] = str[tj_strlen(str) - 1 - i];
        str[tj_strlen(str) - 1 - i] = temp;
    }
    return 0; //return值可根据需要修改
}