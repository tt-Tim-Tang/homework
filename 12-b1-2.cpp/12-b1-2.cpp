//2453805 唐先泽 大数据
#include <iostream>
#include <iomanip>
using namespace std;

#define STUDENT_NUM	4
#define SCORE_NUM	5

/* --- 不允许定义任何形式的全局变量 --- */

/***************************************************************************
  函数名称：
  功    能：求第一门课的平均分
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void average(int (*score)[STUDENT_NUM])
{
    /* 函数定义语句部分：
       1、本函数中仅允许定义 1个简单变量 + 1个指针变量 */

       /* 函数执行语句部分：
          1、不允许再定义任何类型的变量，包括 for (int i=0;...）等形式定义变量
          2、循环变量必须是指针变量，后续语句中不允许出现[]形式访问数组
             不允许：int a[10], i;
                     for(i=0; i<10; i++)
                         cout << a[i];
             允许  ：int a[10], p;
                     for(p=a; p<a+10; p++)
                         cout << *p;          */

    int* p = *score;
    double avg = 0;
    for (; p < *score + STUDENT_NUM; p++) {
        avg += *p;
    }
	avg = avg / STUDENT_NUM;
	cout << "第1门课平均分：" << avg << endl;

}

/***************************************************************************
  函数名称：
  功    能：找出有两门以上课程不及格的学生
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fail(int (*score)[STUDENT_NUM])
{
    /* 函数定义语句部分：
       1、本函数中仅允许定义 3个简单变量 + 1个行指针变量 + 1个简单指针变量 */

       /* 函数执行语句部分（要求同average）*/
    cout << "2门以上不及格的学生：" << endl;
    for (int i = 1; i < 5; i++) {
        int num_fail = 0;
        double avg = 0;
        int(*p)[STUDENT_NUM] = score;
        for (; p < score + SCORE_NUM; p++) {
            int* s = *p + i - 1;
            if (*s < 60) {
                num_fail += 1;
            }
            avg += *s;
        }
        if (num_fail >= 2) {
            avg = avg / SCORE_NUM;
            cout << "No：" << i << " ";
            p = score;
            for (; p < score + SCORE_NUM; p++) {
                cout << *(*p + i - 1) << " ";
            }
            cout << "平均：" << avg << endl;
        }
    }

}

/***************************************************************************
  函数名称：
  功    能：找出平均成绩在90分以上或全部成绩在85分以上的学生
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void good(int (*score)[STUDENT_NUM])
{
    /* 函数定义语句部分：
       1、本函数中仅允许定义 3个简单变量 + 1个行指针变量 + 1个简单指针变量 */

       /* 函数执行语句部分（要求同average）*/
    cout << "平均90以上或全部85以上的学生：" << endl;
    for (int i = 1; i < 5; i++) {
        int more_than_85 = 0;
        double avg = 0;
        int(*p)[STUDENT_NUM] = score;
        for (; p < score + SCORE_NUM; p++) {
            int* s = *p + i - 1;
            if (*s >= 85) {
                more_than_85 += 1;
            }
            avg += *s;
        }
        avg = avg / SCORE_NUM;
        if (more_than_85 == SCORE_NUM || avg >= 90) {
            cout << "No：" << i << " ";
            p = score;
            for (; p < score + SCORE_NUM; p++) {
                cout << *(*p + i - 1) << " ";
            }
            cout << "平均：" << avg << endl;
        }
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    int a[SCORE_NUM][STUDENT_NUM] = {
        {91,92,93,97},  //第1-4个学生的第1门课成绩
        {81,82,83,85},  //第1-4个学生的第2门课成绩
        {71,72,99,87},  //第1-4个学生的第3门课成绩
        {61,32,80,91},  //第1-4个学生的第4门课成绩
        {51,52,95,88} };//第1-4个学生的第5门课成绩
    /* 除上面的预置数组外，本函数中仅允许定义 1个行指针变量 + 1个简单指针变量 */

    /* 函数执行语句部分（要求同average）*/
	cout << "初始信息：" << endl;
    for(int(*p)[STUDENT_NUM] = a; p < a + SCORE_NUM; p++) {
        cout << "No.1-4学生的第" << p - a + 1 << "门课的成绩：";
        int* s = *p;
        for (; s < *p + STUDENT_NUM; s++) {
            cout << *s << " ";
        }
        cout << endl;
	}
    cout << endl;
	average(a);
    cout << endl;
	fail(a);
	cout << endl;
	good(a);

    return 0;
}