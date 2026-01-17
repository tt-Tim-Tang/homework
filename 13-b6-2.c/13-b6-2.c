//2453805 唐先泽 大数据
# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
//根据需要可加入其它头文件
#ifdef _WIN32
#include <conio.h>
#endif

//此处为示例，允许修改结构体名称，允许修改结构体中的成员内容，要求sizeof必须是64

#pragma pack(push,1)
struct demo {
    char name[16];
    short hp;
    short power;
    short constitution;
    short dexterity;
    int money;
    int fame;
    int charm;
    long long play_time;
    char move_speed;
    char attack_speed;
    char attack_range;
    char reserved;
    short attack;
    short defense;
    char agility;
    char intelligence;
    char exp;
    char level;
    short mp;
    char mp_cost;
    char magic_attack;
    char hit_rate;
    char magic_defense;
    char crit_rate;
    char stamina;
};
#pragma pack(pop)

/* 此处允许新增函数，数量不限
   1、所有新增的函数，均不允许定义新的 FILE* 并进行打开/读/写/关闭等操作
   2、上述限制同样适用于main函数
*/
void usage(const char* procname)
{
    printf("usage : %s --modify | --read\n", procname);
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次fopen、一次fread（因为包含错误处理，允许多次fclose）
***************************************************************************/
int read()
{
    /* 本函数中只允许定义一个 FILE* */
    FILE* fp;

    /* 文件打开，具体要求为：
       1、要求以读方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "rb");

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(demo), fp);
    */
    if (!fp) {
        printf("文件打开失败\n");
        return -1;
    }
    struct demo buf;
    int n = (int)fread(&buf, 1, sizeof(struct demo), fp);
    if (n != sizeof(struct demo)) {
        printf("文件读取失败\n");
        fclose(fp);
        return -1;
    }
    printf("          玩家昵称：%s\n", buf.name);
    printf("            生命值：%d\n", buf.hp);
    printf("            力量值：%d\n", buf.power);
    printf("            体质值：%d\n", buf.constitution);
    printf("            灵巧值：%d\n", buf.dexterity);
    printf("            金钱值：%d\n", buf.money);
    printf("            名声值：%d\n", buf.fame);
    printf("            魅力值：%d\n", buf.charm);
    printf("游戏累计时间(us)值：%lld\n", buf.play_time);
    printf("        移动速度值：%d\n", (int)buf.move_speed);
    printf("        攻击速度值：%d\n", (int)buf.attack_speed);
    printf("        攻击范围值：%d\n", (int)buf.attack_range);
    printf("          攻击力值：%d\n", buf.attack);
    printf("          防御力值：%d\n", buf.defense);
    printf("          敏捷度值：%d\n", (int)buf.agility);
    printf("            智力值：%d\n", (int)buf.intelligence);
    printf("            经验值：%d\n", (int)buf.exp);
    printf("            等级值：%d\n", (int)buf.level);
    printf("            魔法值：%d\n", buf.mp);
    printf("        消耗魔法值：%d\n", (int)buf.mp_cost);
    printf("      魔法伤害力值：%d\n", (int)buf.magic_attack);
    printf("          命中率值：%d\n", (int)buf.hit_rate);
    printf("      魔法防御力值：%d\n", (int)buf.magic_defense);
    printf("          暴击率值：%d\n", (int)buf.crit_rate);
    printf("            耐力值：%d\n", (int)buf.stamina);
    fclose(fp);
    return 0;

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：整个函数，只允许出现一次open、一次read、一次write（因为包含错误处理，允许多次fclose）
***************************************************************************/
int modify()
{
    /* 本函数中只允许定义一个 FILE* */
    FILE* fp;

    /* 文件打开，具体要求为：
       1、要求以读写方式打开，打开方式***自行指定
       2、除本次fopen外，本函数其它地方不允许再出现fopen/freopen  */
    fp = fopen("game.dat", "rb+");

    /* 进行后续操作，包括错误处理、读文件、显示各游戏项的值、关闭文件等，允许调用函数
       其中：只允许用一次性读取64字节的方法将game.dat的内容读入***（缓冲区名称、结构体名称自行指定）
                 fread(***, 1, sizeof(demo), fp);
             只允许用一次性写入64字节的方法将***的内容写入game.dat中（缓冲区名称、结构体名称自行指定）
                 fwrite(***, 1, sizeof(demo), fp);
    */
    if (!fp) {
        printf("文件打开失败\n");
		return -1;
    }
    struct demo buf;
    int n = (int)fread(&buf, 1, sizeof(struct demo), fp);
    if (n != sizeof(struct demo)) {
        printf("文件读取失败\n");
        fclose(fp);
        return -1;
    }

    while (1) {
        printf("--------------------------------------\n");
        printf("  游戏存档文件修改工具\n");
        printf("--------------------------------------\n");
        printf("  a.玩家昵称    (%s)\n", buf.name);
        printf("  b.生命        (%d)\n", buf.hp);
        printf("  c.力量        (%d)\n", buf.power);
        printf("  d.体质        (%d)\n", buf.constitution);
        printf("  e.灵巧        (%d)\n", buf.dexterity);
        printf("  f.金钱        (%d)\n", buf.money);
        printf("  g.名声        (%d)\n", buf.fame);
        printf("  h.魅力        (%d)\n", buf.charm);
        printf("  i.游戏累计时间(%lld)\n", buf.play_time);
        printf("  j.移动速度    (%d)\n", (int)buf.move_speed);
        printf("  k.攻击速度    (%d)\n", (int)buf.attack_speed);
        printf("  l.攻击范围    (%d)\n", (int)buf.attack_range);
        printf("  m.攻击力      (%d)\n", buf.attack);
        printf("  n.防御力      (%d)\n", buf.defense);
        printf("  o.敏捷度      (%d)\n", (int)buf.agility);
        printf("  p.智力        (%d)\n", (int)buf.intelligence);
        printf("  q.经验        (%d)\n", (int)buf.exp);
        printf("  r.等级        (%d)\n", (int)buf.level);
        printf("  s.魔法值      (%d)\n", buf.mp);
        printf("  t.消耗魔法值  (%d)\n", (int)buf.mp_cost);
        printf("  u.魔法伤害力  (%d)\n", (int)buf.magic_attack);
        printf("  v.魔法命中率  (%d)\n", (int)buf.hit_rate);
        printf("  w.魔法防御力  (%d)\n", (int)buf.magic_defense);
        printf("  x.暴击率      (%d)\n", (int)buf.crit_rate);
        printf("  y.耐力        (%d)\n", (int)buf.stamina);
        printf("--------------------------------------\n");
        printf("  0.放弃修改\n");
        printf("  1.存盘退出\n");
        printf("--------------------------------------\n");
        printf("请选择[a..y, 0..1]: ");

        #ifdef _WIN32
        char c = getche();
        #elif defined(__linux__)
        char c = getchar();
        #endif
        printf("\n");

        if (c == '0') {
            fclose(fp);
            return 0;
        }
        if (c == '1') {
            fseek(fp, 0, SEEK_SET);
            fwrite(&buf, 1, sizeof(struct demo), fp);
            fclose(fp);
            return 0;
        }

        if (c == 'a') {
            printf("玩家昵称，当前值=%s, 请输入：", buf.name);
            char temp[16] = { 0 };
            scanf("%15s", temp);
            while (getchar() != '\n');
            strcpy(buf.name, temp);
            buf.name[15] = '\0';
        }
        else if (c == 'b') {
            while (1) {
                printf("生命，当前值=%d，范围[0..10000]，请输入 :", buf.hp);
                short val;
                if (scanf("%hd", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 10000) {
                    printf("非法的生命值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.hp = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'c') {
            while (1) {
                printf("力量，当前值=%d，范围[0..10000]，请输入 :", buf.power);
                short val;
                if (scanf("%hd", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 10000) {
                    printf("非法的力量值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.power = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'd') {
            while (1) {
                printf("体质，当前值=%d，范围[0..8192]，请输入 :", buf.constitution);
                short val;
                if (scanf("%hd", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 8192) {
                    printf("非法的体质值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.constitution = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'e') {
            while (1) {
                printf("灵巧，当前值=%d，范围[0..1024]，请输入 :", buf.dexterity);
                short val;
                if (scanf("%hd", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 1024) {
                    printf("非法的灵巧值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.dexterity = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'f') {
            while (1) {
                printf("金钱，当前值=%d，范围[0..100000000]，请输入 :", buf.money);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100000000) {
                    printf("非法的金钱值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.money = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'g') {
            while (1) {
                printf("名声，当前值=%d，范围[0..10000000]，请输入 :", buf.fame);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 10000000) {
                    printf("非法的名声值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.fame = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'h') {
            while (1) {
                printf("魅力，当前值=%d，范围[0..10000000]，请输入 :", buf.charm);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 10000000) {
                    printf("非法的魅力值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.charm = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'i') {
            while (1) {
                printf("游戏累计时间，当前值=%lld，范围[0..10000000000000000]，请输入 :", buf.play_time);
                long long val;
                if (scanf("%lld", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 10000000000000000LL) {
                    printf("非法的游戏累计时间：%lld\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.play_time = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'j') {
            while (1) {
                printf("移动速度，当前值=%d，范围[0..100]，请输入 :", (int)buf.move_speed);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的移动速度：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.move_speed = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'k') {
            while (1) {
                printf("攻击速度，当前值=%d，范围[0..100]，请输入 :", (int)buf.attack_speed);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的攻击速度：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.attack_speed = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'l') {
            while (1) {
                printf("攻击范围，当前值=%d，范围[0..100]，请输入 :", (int)buf.attack_range);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的攻击范围：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.attack_range = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'm') {
            while (1) {
                printf("攻击力，当前值=%d，范围[0..2000]，请输入 :", buf.attack);
                short val;
                if (scanf("%hd", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 2000) {
                    printf("非法的攻击力：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.attack = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'n') {
            while (1) {
                printf("防御力，当前值=%d，范围[0..2000]，请输入 :", buf.defense);
                short val;
                if (scanf("%hd", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 2000) {
                    printf("非法的防御力：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.defense = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'o') {
            while (1) {
                printf("敏捷度，当前值=%d，范围[0..100]，请输入 :", (int)buf.agility);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的敏捷度：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.agility = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'p') {
            while (1) {
                printf("智力，当前值=%d，范围[0..100]，请输入 :", (int)buf.intelligence);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的智力：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.intelligence = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'q') {
            while (1) {
                printf("经验，当前值=%d，范围[0..100]，请输入 :", (int)buf.exp);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的经验：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.exp = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'r') {
            while (1) {
                printf("等级，当前值=%d，范围[0..100]，请输入 :", (int)buf.level);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的等级：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.level = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 's') {
            while (1) {
                printf("魔法值，当前值=%d，范围[0..10000]，请输入 :", buf.mp);
                short val;
                if (scanf("%hd", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 10000) {
                    printf("非法的魔法值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.mp = val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 't') {
            while (1) {
                printf("消耗魔法值，当前值=%d，范围[0..100]，请输入 :", (int)buf.mp_cost);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的消耗魔法值：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.mp_cost = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'u') {
            while (1) {
                printf("魔法伤害力，当前值=%d，范围[0..100]，请输入 :", (int)buf.magic_attack);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的魔法伤害力：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.magic_attack = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'v') {
            while (1) {
                printf("魔法命中率，当前值=%d，范围[0..100]，请输入 :", (int)buf.hit_rate);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的魔法命中率：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.hit_rate = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'w') {
            while (1) {
                printf("魔法防御力，当前值=%d，范围[0..100]，请输入 :", (int)buf.magic_defense);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的魔法防御力：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.magic_defense = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'x') {
            while (1) {
                printf("暴击率，当前值=%d，范围[0..100]，请输入 :", (int)buf.crit_rate);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的暴击率：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.crit_rate = (char)val;
                while (getchar() != '\n');
                break;
            }
        }
        else if (c == 'y') {
            while (1) {
                printf("耐力，当前值=%d，范围[0..100]，请输入 :", (int)buf.stamina);
                int val;
                if (scanf("%d", &val) != 1) {
                    while (getchar() != '\n');
                    continue;
                }
                if (val < 0 || val > 100) {
                    printf("非法的耐力：%d\n", val);
                    while (getchar() != '\n');
                    continue;
                }
                buf.stamina = (char)val;
                while (getchar() != '\n');
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
***************************************************************************/
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