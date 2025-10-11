//2453805 唐先泽 电信
#include<iostream>
using namespace std;
int main()
{
	int daxie = 0,xiaoxie=0,num=0,space=0,rest=0;
	char str[3][128] = { 0 };
	cout << "请输入第1行" << endl;
	cin.getline(str[0], 127);
	cout << "请输入第2行" << endl;
	cin.getline(str[1], 127);
	cout << "请输入第3行" << endl;
	cin.getline(str[2], 127);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 127; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
				daxie++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
				xiaoxie++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9') {
				num++;
			}
			else if (str[i][j] == ' ') {
				space++;
			}
			else if(str[i][j]!=0) {
				rest++;
			}
		}
	}
	cout << "大写 : " << daxie << endl;
	cout << "小写 : " << xiaoxie << endl;
	cout << "数字 : " << num << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << rest << endl;
	return 0;
}