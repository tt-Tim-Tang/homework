//2453805 唐先泽 电信
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：num，flag_of_size
  返 回 值：无返回值
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	double num;
	int num_1, num_3, num_4, num_5, num_6, num_7, num_8, num_9, num_10, decimal_part, num_11, num_12;
	int num_2;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> num;
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
		cout << "拾";
	}
	daxie(num_2, 0);
    if (num_1 != 0 || num_2 != 0) {
        cout << "亿";
        has_billion = true;
    }

    // 千万-万
    bool has_wan = false;
    if (has_billion) {
        daxie(num_3, 0);
        if (num_3 != 0) {
            cout << "仟";
        }
        if (num_4 == 0 && (num_5 != 0 || num_6 != 0)) {
            daxie(0, 1);
        }
        if (num_3 == 0 && num_4 != 0) {
            daxie(0, 1);
        }

        daxie(num_4, 0);
        if (num_4 != 0) {
            cout << "佰";
        }
        if (num_4 != 0 && num_5 == 0 && num_6 != 0) {
            daxie(0, 1);
        }
        daxie(num_5, 0); 
        if (num_5 != 0) {
            cout << "拾";
        }
        
        daxie(num_6, 0);

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            cout << "万";
            has_wan = true;
        }
    }
    if (has_billion == false) {
        daxie(num_3, 0);
        if (num_3 != 0) {
            cout << "仟";
        }

        daxie(num_4, 0);
        if (num_4 != 0) {
            cout << "佰";
        }

        if (num_3 != 0 && num_4 == 0 && (num_5 != 0 || num_6 != 0)) {
            daxie(0, 1);
        }
        if (num_4 != 0 && num_5 == 0 && num_6 != 0) {
            daxie(0, 1);
        }
        daxie(num_5, 0);
        if (num_5 != 0) {
            cout << "拾";
        }
		daxie(num_6, 0);

        if (num_3 != 0 || num_4 != 0 || num_5 != 0 || num_6 != 0) {
            cout << "万";
            has_wan = true;
        }
    }

    // 千-圆
    if (has_billion || has_wan) {
        daxie(num_7, 0);
        if (num_7 != 0) {
            cout << "仟";
        }
        if (num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            daxie(0, 1);
        }
        if (num_7 == 0 && num_8 != 0) {
            daxie(0, 1);
        }
        daxie(num_8, 0);
        if (num_8 != 0) {
            cout << "佰";
        }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            daxie(0, 1);
        }
        daxie(num_9, 0);
        if (num_9 != 0) {
            cout << "拾";
        }
        daxie(num_10, 0);

        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
            cout << "圆";
        }
        else if (has_billion || has_wan) {
            cout << "圆";
        }
    }
    if (has_billion == false && has_wan == false) {
        daxie(num_7, 0);
        if (num_7 != 0) {
            cout << "仟";
        }
        daxie(num_8, 0);
        if (num_8 != 0) {
            cout << "佰";
        }
        if (num_7 != 0 && num_8 == 0 && (num_9 != 0 || num_10 != 0)) {
            daxie(0, 1);
        }
        if (num_8 != 0 && num_9 == 0 && num_10 != 0) {
            daxie(0, 1);
        }
        daxie(num_9, 0);
        if (num_9 != 0) {
            cout << "拾";
        }
        daxie(num_10, 0);
        if (num_7 == 0 && num_8 == 0 && num_9 == 0 && num_10 == 0 && num_11 == 0 && num_12 == 0) {
            daxie(0, 1);
            cout << "圆";
        }

        if (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0) {
            cout << "圆";
        }
        else if (has_billion || has_wan) {
            cout << "圆";
        }
    }


    // 小数部分
    if (num_11 != 0 || num_12 != 0) {
        daxie(num_11, 0);
        if (num_11 != 0) {
            cout << "角";
        }
        if (num_12 == 0) {
            cout << "整";
        }
        if (((has_billion || has_wan) || (num_7 != 0 || num_8 != 0 || num_9 != 0 || num_10 != 0)) && num_11 == 0 && num_12 != 0) {
            daxie(0, 1);
        }
        daxie(num_12, 0);
        if (num_12 != 0) {
            cout << "分";
        }
    }
    else {
        cout << "整";
    }

    cout << endl;

	return 0;
}