//2453805 唐先泽 电信
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	char temp_0[3] = { chnstr[0],chnstr[1], '\0' };
	char temp_1[3] = { chnstr[2],chnstr[3],'\0' };
	char temp_2[3] = { chnstr[4],chnstr[5],'\0' };
	char temp_3[3] = { chnstr[6],chnstr[7],'\0' };
	char temp_4[3] = { chnstr[8],chnstr[9],'\0' };
	char temp_5[3] = { chnstr[10],chnstr[11],'\0' };
	char temp_6[3] = { chnstr[12],chnstr[13],'\0' };
	char temp_7[3] = { chnstr[14],chnstr[15],'\0' };
	char temp_8[3] = { chnstr[16],chnstr[17],'\0' };
	char temp_9[3] = { chnstr[18],chnstr[19],'\0' };


	switch (num) {
	case 0:
		if (flag_of_zero) {
			result += temp_0;
		}
		break;
	case 1:
		result += temp_1;
		break;
	case 2:
		result += temp_2;
		break;
	case 3:
		result += temp_3;
		break;
	case 4:
		result += temp_4;
		break;
	case 5:
		result += temp_5;
		break;
	case 6:
		result += temp_6;
		break;
	case 7:
		result += temp_7;
		break;
	case 8:
		result += temp_8;
		break;
	case 9:
		result += temp_9;
		break;
	default:
		break;
	}
}



int main()
{
    /* --允许添加需要的内容 --*/
	double num;
	int num_1, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_10, decimal_part, num_11, num_12;
	int num_2;
	while (1) {
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> num;
		if (cin.fail()) {
			cin.clear(); 
			cin.ignore(INT_MAX, '\n'); 
			continue; 
		}
		else {
			break;
		}
	}
	cout << "大写结果是:" << endl;
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

    // 十亿-亿
    bool has_billion = false;
    daxie(num_1, 0);
    if (num_1 != 0) {
        result+="拾";
    }
    daxie(num_2, 0);
    if (num_1 != 0 || num_2 != 0) {
        result+="亿";
        has_billion = true;
    }

    // 千万-万
    bool has_wan = false;
    if (has_billion) {
        daxie(num_3, 0);
        if (num_3 != 0) {
            result+="仟";
        }
        if (num_4 == 0 && (num_5 != 0 || num_6 != 0)) {
            daxie(0, 1);
        }
        if (num_3 == 0 && num_4 != 0) {
            daxie(0, 1);
        }

        daxie(num_4, 0);
        if (num_4 != 0) {
            result+="佰";
        }
        if (num_4 != 0 && num_5 == 0 && num_6 != 0) {
            daxie(0, 1);
        }
        daxie(num_5, 0);
        if (num_5 != 0) {
            result+="拾";
        }

        daxie(num_6, 0);

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            result+="万";
            has_wan = true;
        }
    }
    if (has_billion == false) {
        daxie(num_3, 0);
        if (num_3 != 0) {
            result+="仟";
        }

        daxie(num_4, 0);
        if (num_4 != 0) {
            result+="佰";
        }

        if (num_3 != 0 && num_4 == 0 && (num_5 != 0 || num_6 != 0)) {
            daxie(0, 1);
        }
        if (num_4 != 0 && num_5 == 0 && num_6 != 0) {
            daxie(0, 1);
        }
        daxie(num_5, 0);
        if (num_5 != 0) {
            result+="拾";
        }
        daxie(num_6, 0);

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            result+="万";
            has_wan = true;
        }
    }

    // 千-圆
    if (has_billion || has_wan) {
        daxie(num_7, 0);
        if (num_7 != 0) {
            result+="仟";
        }
        if (num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            daxie(0, 1);
        }
        if (num_7 == 0 && num_8 != 0) {
            daxie(0, 1);
        }
        daxie(num_8, 0);
        if (num_8 != 0) {
            result+="佰";
        }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            daxie(0, 1);
        }
        daxie(num_9, 0);
        if (num_9 != 0) {
            result+="拾";
        }
        daxie(num_10, 0);

        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
            result+="圆";
        }
        else if (has_billion || has_wan) {
            result+="圆";
        }
    }
    if (has_billion == false && has_wan == false) {
        daxie(num_7, 0);
        if (num_7 != 0) {
            result+="仟";
        }
        daxie(num_8, 0);
        if (num_8 != 0) {
            result+="佰";
        }
        if (num_7 != 0 && num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            daxie(0, 1);
        }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            daxie(0, 1);
        }
        daxie(num_9, 0);
        if (num_9 != 0) {
            result+="拾";
        }
        daxie(num_10, 0);
        if (num_7 == 0 && num_8 == 0 && num_9 == 0 && num_10 == 0 && num_11 == 0 && num_12 == 0) {
            daxie(0, 1);
            result+="圆";
        }

        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
            result+="圆";
        }
        else if (has_billion || has_wan) {
            result+="圆";
        }
    }


    // 小数部分
    if (num_11 != 0 || num_12 != 0) {
        daxie(num_11, 0);
        if (num_11 != 0) {
            result+="角";
        }
        if (num_12 == 0) {
            result+="整";
        }
        if (((has_billion || has_wan) || (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0)) && num_11 == 0 && num_12 != 0) {
            daxie(0, 1);
        }
        daxie(num_12, 0);
        if (num_12 != 0) {
            result+="分";
        }
    }
    else {
        result+="整";
    }

    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}