//2453805 唐先泽 大数据
#include<iostream>
#include <cstring>
#include <cstdlib>
#define MAX_VALUE_NUM 10
using namespace std;

struct para {
	char name;
	int added_para_num;
	int min_value[MAX_VALUE_NUM];
	int max_value[MAX_VALUE_NUM];
	int default_value[MAX_VALUE_NUM];
	int value[MAX_VALUE_NUM];
};


int usage(const char* const procname)
{
	cout << "Usage: " << procname << " [-l 大小] [-n 数量] [-t] IP地址" << endl;
	cout << "       ==================================" << endl;
	cout << "        参数 附加参数 范围        默认值" << endl;
	cout << "       ==================================" << endl;
	cout << "        -l   1        [32..64000] 64" << endl;
	cout << "        -n   1        [1..1024]   4" << endl;
	cout << "        -t   0        [0..1]      0" << endl;
	cout << "       ==================================" << endl;
	return 0;
}

int check_IP(const char* ipstr)
{
	int len = strlen(ipstr);
	int dot_record[4] = {0};
	int dot_count = 0;
	for (int i = 0; i < len; i++) {
		if (ipstr[i] == '.') {
			dot_record[dot_count++] = i;
			if(dot_count > 3) {
				return 0;
			}
		}
		if(ipstr[i] < '0' || ipstr[i] > '9') {
			if (ipstr[i] != '.') {
				return 0;
			}
		}
	}

	if (dot_count != 3) {
		return 0;
	}
	else {
		if((dot_record[1]-dot_record[0])==1 || (dot_record[2]-dot_record[1])==1 || (len - dot_record[2])==1||dot_record[0]==0) {
			return 0;
		}
		else {
			int num_1 = 0;
			for (int i = 0; i < dot_record[0]; i++) {
				num_1 = num_1 * 10 + ipstr[i] - '0';
			}
			if (num_1 < 0 || num_1 > 255) {
				return 0;
			}

			int num_2 = 0;
			for (int i = dot_record[0] + 1; i < dot_record[1]; i++) {
				num_2 = num_2 * 10 + ipstr[i] - '0';
			}
			if (num_2 < 0 || num_2 > 255) {
				return 0;
			}
			
			int num_3 = 0;
			for (int i = dot_record[1] + 1; i < dot_record[2]; i++) {
				num_3 = num_3 * 10 + ipstr[i] - '0';
			}
			if (num_3 < 0 || num_3 > 255) {
				return 0;
			}

			int num_4 = 0;
			for (int i = dot_record[2] + 1; i < len; i++) {
				num_4 = num_4 * 10 + ipstr[i] - '0';
			}
			if (num_4 < 0 || num_4 > 255) {
				return 0;
			}

		}
	}
	return 1;
}

int main(int argc,char* argv[])
{
	if (argc == 1) {
		usage(argv[0]);
		return 0;
	}
	
	// 参数列表 name :参数名 added_para_num:附加参数个数 min_value:最小值 max_value:最大值 
	//default_value:默认值 value:实际值
	struct para param_list[3] = {
		{'l', 1, {32}, {64000}, {64}, {64}},
		{'n', 1, {1}, {1024}, {4}, {4}},
		{'t', 0, {0}, {1}, {1}, {0}}
	};

	//参数个数
	int count = sizeof(param_list) / sizeof(param_list[0]);

	//先检查ip
	if (!check_IP(argv[argc - 1])) {
		cout << "IP地址错误" << endl;
		return 0;
	}



	for (int i = 1; i < argc - 1; i++) {
		if (argv[i][0] != '-') {
			cout <<"参数" << argv[i] << "不是以-开头的合法参数" << endl;
			return 0;
		}
		else {
			int flag = 0;//标记是否有匹配上的
			for(int j=0;j<count;j++){
				//先处理必须要带一个参数的情况
				if (argv[i][1] == param_list[j].name && argv[i][2] == '\0' && param_list[j].added_para_num) {
					flag = 1;
					//命令后没有参数
					if (i + param_list[j].added_para_num >= argc - 1) {
						cout << "参数-"<<param_list[j].name<<"没有后续参数" << endl;
						return 0;
					}

					else {
						for (int m = 1; m <= param_list[j].added_para_num; m++) {
							//下一个参数以“-”开头被识别为错误
							if (argv[i + m][0] == '-') {
								cout << "参数-" << param_list[j].name << "没有后续参数" << endl;
								return 0;
							}
							//参数转成数字在合理范围内
							else if (atoi(argv[i + m]) >= param_list[j].min_value[m - 1] && atoi(argv[i + m]) <= param_list[j].max_value[m - 1]) {
						        // 标记该字符串的第一个字符是否为数字（因为abc这种直接atoi会变成0，但12abc会被转成12，要考虑0的问题）
								int is_head_num = 1;
								if (argv[i + m][0] < '0' || argv[i + m][0] > '9') {
									is_head_num = 0;//字符串第一个字符非数字
								}
								if (is_head_num) {// 如果都是数字或者字符串第一个字符是数字
									param_list[j].value[m - 1] = atoi(argv[i + m]);
								}
								else {//字符串第一位非数字，说明转换时实际上出现异常，应保持default
									param_list[j].value[m - 1] = param_list[j].default_value[m - 1];
								}
							}
							// 参数不在合理范围内，不动原来的value，保持default
							else {
								param_list[j].value[m - 1] = param_list[j].default_value[m - 1];
							}
						}
	
						i += param_list[j].added_para_num;
					}
				}
				// 处理不带参数的命令 added_para_num=0
				else if (argv[i][1] == param_list[j].name && argv[i][2] == '\0' && !param_list[j].added_para_num) {
					flag = 1;
					param_list[j].value[0] = param_list[j].default_value[0];
				}

				
			}
			// 如果flag=0没有匹配上
			if (!flag) {
				cout << "参数" << argv[i] << "不存在" << endl;
				return 0;
			}
		}
	}


	cout << "参数检查通过" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "-" << param_list[i].name << " 参数：";
		for (int j = 0; j < (param_list[i].added_para_num > 1 ? param_list[i].added_para_num : 1); j++) {
			cout << param_list[i].value[j] << " ";
		}
		cout << endl;
	}
	cout << "IP地址：" << argv[argc - 1] << endl;
	return 0;
}