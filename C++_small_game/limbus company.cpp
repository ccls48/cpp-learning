#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<random>
using namespace std;
struct Player
{
    char name[10];
    int HP;
    int attack;
    int cure;
};
struct Monster
{
    char name[10];
    int HP;
    int attack;
};
Player Create_player(const int n);
Monster Create_monster(const int n);
void Battle_Player(Player &A,Monster &B);
void cure_player(Player &A);
void Attack_Monster(Player &A,Monster &B);
int main()
{
    int n=0,num=0,skill=0,Monster_play=0,Player_play=0,power=0,cure=0,enemy=0,i=0;
    Player player;
    Monster monster;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double>dis(0.0,1.0);
    cout<<"Welcome Limbus Campany"<<endl;
    for(int i=0;i<30;i++)
    {
        printf("=");
    }
    cout<<endl;
    cout<<"请选择你的角色(输入对应角色序号后按下回车键)"<<endl;
    cout<<"1.浮士德"<<endl;
    cin>>n;
    system("cls");
    player=Create_player(n);
    cout<<"选择的角色为:"<<player.name<<endl<<"生命值:"<<player.HP<<endl<<"攻击力:"<<player.attack<<endl<<"治疗量:"<<player.cure<<endl;
    for(int i=0;i<30;i++)
    {
        cout<<"=";
    }
    cout<<endl;
    cout<<"你的敌人(随机生成)"<<endl;
    srand(time(0));
    int m=1;
    monster=Create_monster(m);
    cout<<"敌人信息:"<<monster.name<<endl<<"生命值:"<<monster.HP<<endl<<"攻击力:"<<monster.attack<<endl;
    cout<<"请输入114514开始游戏"<<endl;
    if(cin>>num&&num==114514)
    {
        _getch();
    }
    else
    {
        system("cls");
        cout<<"呵呵呵,额~~~~";system("cls");
        exit(1);
    }
    system("cls");
    cout<<"开始游戏"<<endl;
    while(player.HP>0&&monster.HP>0)
    {
        i++;
        cout<<"第"<<i<<"回合"<<endl<<"玩家回合"<<endl;
        cout<<"请选择技能:1.攻击"<<" "<<"2.治疗(请输入编号)";
        cin>>skill;
        if(skill==1)
        {
            Battle_Player(player,monster);
            cout<<player.name<<endl<<"生命值:"<<player.HP<<endl<<"攻击力:"<<player.attack<<endl<<"治疗量:"<<player.cure<<endl;
            cout<<endl;
            cout<<monster.name<<endl<<"生命值:"<<monster.HP<<endl<<"攻击力:"<<monster.attack<<endl;
        }
        else if(skill==2)
        {
            cure_player(player);
            cout<<player.name<<endl<<"生命值:"<<player.HP<<endl<<"攻击力:"<<player.attack<<endl<<"治疗量:"<<player.cure<<endl;
            cout<<endl;
            cout<<monster.name<<endl<<"生命值:"<<monster.HP<<endl<<"攻击力:"<<monster.attack<<endl;
        }
        cout<<endl;
        cout<<"敌人回合"<<endl;
        Attack_Monster(player,monster);
        cout<<player.name<<endl<<"生命值:"<<player.HP<<endl<<"攻击力:"<<player.attack<<endl<<"治疗量:"<<player.cure<<endl;
        cout<<endl;
        cout<<monster.name<<endl<<"生命值:"<<monster.HP<<endl<<"攻击力:"<<monster.attack<<endl;
        cout<<endl;
    }
    if(player.HP>0)
    {
        cout<<"胜利";
    }
    else
    {
        cout<<"失败";
    }
    return 0;
}
Player Create_player(const int n)//初始化并选择角色
{
    if(n<1||n>5)
    {
        cout<<"超出范围";
        exit(1);
    }
    Player A={"浮士德",220,40,30};
    switch(n)
    {
    case 1:
        return A;
        exit(1);
    }
}
Monster Create_monster(const int n)
{
    Monster A={"李恩",400,30};
    switch(n)
    {
    case 1:
        return A;
    }
}
void Battle_Player(Player &A,Monster &B)
{
    A.attack=rand()%50+30;
    B.HP=B.HP-A.attack;
}
void cure_player(Player &A)
{

    int cure=rand()%60+30;
    A.HP=cure+A.HP;
}
void Attack_Monster(Player &A,Monster &B)
{
    B.attack=rand()%40+30;
    A.HP=A.HP-B.attack;
}
