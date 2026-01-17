//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <iomanip>
//根据需要可加入其它头文件
#ifdef _WIN32
#include <conio.h>
#endif


using namespace std;

//此处为示例，允许修改结构体名称，允许修改结构体中的成员内容，要求sizeof必须是64
#pragma pack(push,1)
struct demo {
	char name[16];         // 1-16 角色名称 (16字节)
    short hp;              // 17-18 生命值 (2字节)(0-10000)
    short power;           // 19-20 力量 (2字节)(0-10000)
    short constitution;    // 21-22 体质 (2字节)(0-8192)
    short dexterity;       // 23-24 灵巧 (2字节)(0-1024)
    int money;             // 25-28 金钱 (4字节)(0-100000000)
    int fame;              // 29-32 名声 (4字节)(0-10000000)
    int charm;             // 33-36 魅力 (4字节)(0-10000000)
    long long play_time;   // 37-44 游戏累计时间 (8字节)(0-10000000000000000)
    char move_speed;       // 45 移动速度 (1字节)（0-100）
    char attack_speed;     // 46 攻击速度 (1字节)（0-100）
    char attack_range;     // 47 攻击范围 (1字节)（0-100）
    char reserved;         // 48 预留 (1字节) 暂时不用
    short attack;          // 49-50 攻击力 (2字节)(0-2000）
    short defense;         // 51-52 防御力 (2字节)(0-2000）
    char agility;          // 53 敏捷度 (1字节)(0-100）
    char intelligence;     // 54 智力 (1字节)(0-100）
    char exp;              // 55 经验 (1字节)(0-100）
    char level;            // 56 等级 (1字节)(0-100）
    short mp;              // 57-58 魔法值 (2字节)（0-10000）
    char mp_cost;          // 59 使用魔法时每次消耗的魔法值 (1字节)(0-100）
    char magic_attack;     // 60 魔法伤害力 (1字节)(0-100）
    char hit_rate;         // 61 命中率 (1字节)(0-100）
    char magic_defense;    // 62 魔法防御力 (1字节)(0-100）
    char crit_rate;        // 63 暴击率 (1字节)(0-100）
    char stamina;          // 64 耐力 (1字节)(0-100）
};
#pragma pack(pop)
/* 此处允许新增函数，数量不限
   1、所有新增的函数，均不允许定义新的 fstream / ifstream / ofstream 流对象，并进行打开/读/写/关闭等操作
   2、所有新增的函数，均不允许用C方式进行文件处理
   3、上述两个限制同样适用于main函数
*/
void usage(const char* const procname)
{
    cout << "usage : " << procname << " --modify | --read" << endl;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read（因为包含错误处理，允许多次close）
***************************************************************************/
int read()
{
    /* 本函数中只允许定义一个 ifstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    ifstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::binary);

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
    */
    if(!gfile) {
        cout << "文件打开失败" << endl;
        return -1;
	}
    demo buf;
	gfile.read(reinterpret_cast<char*>(&buf), sizeof(demo));
    if(!gfile) {
        cout << "文件读取失败" << endl;
        gfile.close();
        return -1;
	}
    cout << "          玩家昵称：" << buf.name << endl;
    cout << "            生命值：" << buf.hp << endl;
    cout << "            力量值：" << buf.power << endl;
    cout << "            体质值：" << buf.constitution << endl;
    cout << "            灵巧值：" << buf.dexterity << endl;
    cout << "            金钱值：" << buf.money << endl;
    cout << "            名声值：" << buf.fame << endl;
    cout << "            魅力值：" << buf.charm << endl;
    cout << "游戏累计时间(us)值：" << buf.play_time << endl;
    cout << "        移动速度值：" << int(buf.move_speed) << endl;
    cout << "        攻击速度值：" << int(buf.attack_speed) << endl;
    cout << "        攻击范围值：" << int(buf.attack_range) << endl;
    cout << "          攻击力值：" << buf.attack << endl;
    cout << "          防御力值：" << buf.defense << endl;
    cout << "          敏捷度值：" << int(buf.agility) << endl;
    cout << "            智力值：" << int(buf.intelligence) << endl;
    cout << "            经验值：" << int(buf.exp) << endl;
    cout << "            等级值：" << int(buf.level) << endl;
    cout << "            魔法值：" << buf.mp << endl;
    cout << "        消耗魔法值：" << int(buf.mp_cost) << endl;
    cout << "      魔法伤害力值：" << int(buf.magic_attack) << endl;
    cout << "          命中率值：" << int(buf.hit_rate) << endl;
    cout << "      魔法防御力值：" << int(buf.magic_defense) << endl;
    cout << "          暴击率值：" << int(buf.crit_rate) << endl;
    cout << "            耐力值：" << int(buf.stamina) << endl;
    gfile.close();
	return 0;

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次close）
***************************************************************************/
int modify()
{
    /* 本函数中只允许定义一个 fstream流对象，不再允许定义任何形式的fstream/ifstream/ofstream流对象，也不允许使用C方式的文件处理 */
    fstream gfile;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次open外，本函数其它地方不允许再出现open  */
    gfile.open("game.dat", ios::in | ios::out | ios::binary);

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 gfile.read(***, sizeof(demo));
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
                 gfile.write(***, sizeof(demo));
    */
    if (!gfile) {
        cout << "文件打开失败" << endl;
        return -1;
    }
	demo buf;
    gfile.read(reinterpret_cast<char*>(&buf), sizeof(demo));
    if (!gfile) {
        cout << "文件读取失败" << endl;
        gfile.close();
        return -1;
    }

    while (true) {
        cout << "--------------------------------------" << endl;
        cout << "  游戏存档文件修改工具" << endl;
        cout << "--------------------------------------" << endl;
        cout << "  a.玩家昵称    (" << buf.name << ")" << endl;
        cout << "  b.生命        (" << buf.hp << ")" << endl;
        cout << "  c.力量        (" << buf.power << ")" << endl;
        cout << "  d.体质        (" << buf.constitution << ")" << endl;
        cout << "  e.灵巧        (" << buf.dexterity << ")" << endl;
        cout << "  f.金钱        (" << buf.money << ")" << endl;
        cout << "  g.名声        (" << buf.fame << ")" << endl;
        cout << "  h.魅力        (" << buf.charm << ")" << endl;
        cout << "  i.游戏累计时间(" << buf.play_time << ")" << endl;
        cout << "  j.移动速度    (" << int(buf.move_speed) << ")" << endl;
        cout << "  k.攻击速度    (" << int(buf.attack_speed) << ")" << endl;
        cout << "  l.攻击范围    (" << int(buf.attack_range) << ")" << endl;
        cout << "  m.攻击力      (" << buf.attack << ")" << endl;
        cout << "  n.防御力      (" << buf.defense << ")" << endl;
        cout << "  o.敏捷度      (" << int(buf.agility) << ")" << endl;
        cout << "  p.智力        (" << int(buf.intelligence) << ")" << endl;
        cout << "  q.经验        (" << int(buf.exp) << ")" << endl;
        cout << "  r.等级        (" << int(buf.level) << ")" << endl;
        cout << "  s.魔法值      (" << buf.mp << ")" << endl;
        cout << "  t.消耗魔法值  (" << int(buf.mp_cost) << ")" << endl;
        cout << "  u.魔法伤害力  (" << int(buf.magic_attack) << ")" << endl;
        cout << "  v.魔法命中率  (" << int(buf.hit_rate) << ")" << endl;
        cout << "  w.魔法防御力  (" << int(buf.magic_defense) << ")" << endl;
        cout << "  x.暴击率      (" << int(buf.crit_rate) << ")" << endl;
        cout << "  y.耐力        (" << int(buf.stamina) << ")" << endl;
        cout << "--------------------------------------" << endl;
        cout << "  0.放弃修改" << endl;
        cout << "  1.存盘退出" << endl;
        cout << "--------------------------------------" << endl;
        cout << "请选择[a..y, 0..1]: ";
        #ifdef _WIN32
        char choice = _getche();
        #elif defined(__linux__)
        char choice = getchar();
        #endif
		cout << endl;
        if(choice == '0') {
            gfile.close();
            return 0;
        }
        if(choice == '1') {
            gfile.clear();
            gfile.seekp(0, ios::beg);
            gfile.write(reinterpret_cast<char*>(&buf), sizeof(demo));
            if (!gfile) {
                cout << endl << "文件写入失败" << endl;
                gfile.close();
                return -1;
            }
            gfile.close();
            return 0;
		}

        if (choice == 'a') {
			cout << "玩家昵称，当前值=" << buf.name << ", 请输入：";
			char temp[16];
			cin >> setw(16)>>temp;
			strcpy(buf.name, temp);
			buf.name[15] = '\0';
			cin.ignore(INT_MAX, '\n');
        }
        else if (choice == 'b') {
            while (1) {
                cout << "生命，当前值=" << buf.hp << "，范围[0..10000]，请输入 :";
                short val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    continue;
                }
                else if (val < 0 || val>10000) {
					cout << "非法的生命值：" << val << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
                }
                else {
                    buf.hp = val;
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
        }
        else if(choice == 'c') {
            while (1) {
                cout << "力量，当前值=" << buf.power << "，范围[0..10000]，请输入 :";
                short val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    continue;
                }
                else if (val < 0 || val>10000) {
					cout << "非法的力量值：" << val << endl;
					cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
                }
                else {
                    buf.power = val;
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
		}
        else if (choice == 'd') {
            while (1) {
                cout << "体质，当前值=" << buf.constitution << "，范围[0..8192]，请输入 :";
                short val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                else if (val < 0 || val>8192) {
					cout << "非法的体质值：" << val << endl;
                    cin.clear();
					cin.ignore(INT_MAX, '\n');
					continue;
                }
                else {
                    buf.constitution = val;
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
        }
        else if (choice == 'e') {
            while (1) {
                cout << "灵巧，当前值=" << buf.dexterity << "，范围[0..1024]，请输入 :";
                short val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                else if (val < 0 || val>1024) {
					cout << "非法的灵巧值：" << val << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
					continue;
                }
                else {
                    buf.dexterity = val;
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
        }
        else if (choice == 'f') {
            while (1) {
                cout << "金钱，当前值=" << buf.money << "，范围[0..100000000]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                else if (val < 0 || val>100000000) {
                    cout << "非法的金钱值：" << val << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                else {
                    buf.money = val;
                    cin.ignore(INT_MAX, '\n');
                    break;
                }
            }
        }
        else if (choice == 'g') {
            while (1) {
                cout << "名声，当前值=" << buf.fame << "，范围[0..10000000]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 10000000) {
                    cout << "非法的名声值：" << val  << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.fame = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'h') {
            while (1) {
                cout << "魅力，当前值=" << buf.charm << "，范围[0..10000000]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 10000000) {
                    cout << "非法的魅力值：" << val  << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.charm = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'i') {
            while (1) {
                cout << "游戏累计时间，当前值=" << buf.play_time << "，范围[0..10000000000000000]，请输入 :";
                long long val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 10000000000000000LL) {
                    cout << "非法的游戏累计时间：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.play_time = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'j') {
            while (1) {
                cout << "移动速度，当前值=" << int(buf.move_speed) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的移动速度：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.move_speed = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'k') {
            while (1) {
                cout << "攻击速度，当前值=" << int(buf.attack_speed) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的攻击速度：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.attack_speed = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'l') {
            while (1) {
                cout << "攻击范围，当前值=" << int(buf.attack_range) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的攻击范围：" << val  << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.attack_range = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'm') {
            while (1) {
                cout << "攻击力，当前值=" << buf.attack << "，范围[0..2000]，请输入 :";
                short val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 2000) {
                    cout << "非法的攻击力：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.attack = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'n') {
            while (1) {
                cout << "防御力，当前值=" << buf.defense << "，范围[0..2000]，请输入 :";
                short val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 2000) {
                    cout << "非法的防御力：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.defense = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'o') {
            while (1) {
                cout << "敏捷度，当前值=" << int(buf.agility) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的敏捷度：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.agility = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'p') {
            while (1) {
                cout << "智力，当前值=" << int(buf.intelligence) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的智力：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.intelligence = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'q') {
            while (1) {
                cout << "经验，当前值=" << int(buf.exp) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的经验：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.exp = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'r') {
            while (1) {
                cout << "等级，当前值=" << int(buf.level) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的等级：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.level = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 's') {
            while (1) {
                cout << "魔法值，当前值=" << buf.mp << "，范围[0..10000]，请输入 :";
                short val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 10000) {
                    cout << "非法的魔法值：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.mp = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 't') {
            while (1) {
                cout << "消耗魔法值，当前值=" << int(buf.mp_cost) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的消耗魔法值：" << val << "，请重新输入！" << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.mp_cost = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'u') {
            while (1) {
                cout << "魔法伤害力，当前值=" << int(buf.magic_attack) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的魔法伤害力：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.magic_attack = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'v') {
            while (1) {
                cout << "魔法命中率，当前值=" << int(buf.hit_rate) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的魔法命中率：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.hit_rate = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'w') {
            while (1) {
                cout << "魔法防御力，当前值=" << int(buf.magic_defense) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的魔法防御力：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.magic_defense = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'x') {
            while (1) {
                cout << "暴击率，当前值=" << int(buf.crit_rate) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的暴击率：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.crit_rate = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        }
        else if (choice == 'y') {
            while (1) {
                cout << "耐力，当前值=" << int(buf.stamina) << "，范围[0..100]，请输入 :";
                int val;
                cin >> val;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    cout << "非法的耐力：" << val << endl;
                    cin.ignore(INT_MAX, '\n');
                    continue;
                }
                buf.stamina = val;
                cin.ignore(INT_MAX, '\n');
                break;
            }
        } 
    }
    
	
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数允许带参数，不允许进行文件读写
*****************************************************************...

        if (参数为--read)
            read(所需参数自行定义);
        else (参数为--modify)
            modify(所需参数自行定义);

    ...

        return 0;**********/
int main(int argc, char** argv)
{
    if (argc == 1) {
        usage(argv[0]);
        return 0;
    }
    else {
        if (strcmp(argv[1], "--read") == 0) {
            read();
        }
        else if (strcmp(argv[1], "--modify") == 0) {
            modify();
        }
		return 0;
    }
}