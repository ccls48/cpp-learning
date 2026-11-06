#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<random>
#include<string>
using namespace std;
class Player
{
public:
    string name;
    int HP;
    int Number_of_coins;
    int Change_value;
    int Base_value;
    int Max_value;
};
class Monster
{
public:
    string name;
    int HP;
    int Number_of_coins;
    int Change_value;
    int Base_value;
    int Max_value;
};
Player Create_player(const int n);
Monster Create_monster(const int n);
string P_Compare_points(Player &A);
string M_Compare_points(Monster &B);
string Compare(int P_Max_value,int M_Max_value);
int Damage(string m,Player &A,Monster &B);
int main()
{
    srand((unsigned)time(NULL));
    int n=0,num=0,q=0,k=0;
    string str1,str2,str3;
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
    cout<<"1.浮士德,2.默尔索,3.罗佳,4.鸿路,5.希斯克利夫"<<endl;
    cin>>n;
    system("cls");
    player=Create_player(n);
    cout<<"选择的角色为:"<<player.name<<endl<<"生命值:"<<player.HP<<endl<<"硬币数:"<<player.Number_of_coins<<endl<<"基础值:"<<player.Base_value<<endl<<"变动值:"<<player.Change_value<<endl;
    for(int i=0;i<30;i++)
    {
        cout<<"=";
    }
    cout<<endl;
    cout<<"你的敌人(随机生成)"<<endl;
    int m=0;
    m=rand()%5+1;
    monster=Create_monster(m);
    cout<<"敌人信息:"<<monster.name<<endl<<"生命值:"<<monster.HP<<endl<<"硬币数:"<<monster.Number_of_coins<<endl<<"基础值:"<<monster.Base_value<<endl<<"变动值:"<<monster.Change_value<<endl;
    cout<<"请输入114514开始游戏"<<endl;
    if(cin>>num&&num==114514)
    {
        _getch();
    }
    else
    {
        system("cls");
        cout<<"呵呵呵,额~~~~";
        exit(1);
    }
    system("cls");
    cout<<"开始游戏"<<endl;
    while(player.HP>0&&monster.HP>0)
    {
        cout<<"选择技能:1.攻击(输入对应技能序号)";
        if(cin>>m&&m==1)
        {
            str1=P_Compare_points(player);
            str2=M_Compare_points(monster);
            str3=Compare(player.Max_value,monster.Max_value);
            cout<<str1<<endl<<str2<<endl<<str3<<endl;
            k=Damage(str3,player,monster);
            cout<<player.name<<" "<<"生命值:"<<player.HP<<endl;
            cout<<monster.name<<" "<<"生命值:"<<monster.HP<<endl;
            system("pause");
            system("cls");
        }
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
        cout<<"超出范围,请重新输入:";
        int m=0;
        cin>>m;
        Create_player(m);
    }
    Player A={"浮士德",220,4,5,5};
    Player B={"默尔索",330,2,5,2};
    Player C={"罗佳",300,3,3,3};
    Player D={"鸿路",300,1,10,4};
    Player E={"希斯克利夫",300,4,3,3};
    switch(n)
    {
    case 1:
        return A;
    case 2:
        return B;
    case 3:
        return C;
    case 4:
        return D;
    case 5:
        return E;
    }
}
Monster Create_monster(const int n)
{
    int m=0;
    Monster A={"李恩",400,9,1,2};
    Monster B={"雷横",500,5,2,1};
    Monster C={"克罗默",300,3};
    Monster D={"绽放E.G.O::山茶花",700,2,4,4};
    switch(n)
    {
    case 1:
        return A;
    case 2:
        return B;
    case 3:
        return C;
    case 4:
        return D;
    }
}
string P_Compare_points(Player &A)
{
    int num=0;
    string result=A.name;
    int P_max=A.Base_value;
    for(int i=0;i<A.Number_of_coins;i++)
    {
        num=rand()%2;
        if(num==1)
        {
            A.Max_value=P_max+A.Change_value;
            result+="正";
        }
        else
        {
            result+="反";
        }
    }
    return result;
}
string M_Compare_points(Monster &B)
{
    int num=0;
    string result=B.name;
    int M_max=B.Base_value;
    for(int i=0;i<B.Number_of_coins;i++)
    {
        num=rand()%2;
        if(num==1)
        {
            B.Max_value=M_max+B.Change_value;
            result+="正";
        }
        else
        {
            result+="反";
        }
    }
    return result;
}
string Compare(int P_Max_value,int M_Max_value)
{
    string n="拼点胜利！";
    string n1="拼点失败！";
    string n2="平局！";
    if(P_Max_value>M_Max_value)
    {
        return n;
    }
    else if(P_Max_value<M_Max_value)
    {
        return n1;
    }
    else
    {
        return n2;
    }
}
int Damage(string m,Player &A,Monster &B)
{
    if(m=="拼点胜利！")
    {
        if(B.HP>A.Max_value)
        {
            B.HP=B.HP-A.Max_value;
            return B.HP;
        }
        else
        {
            B.HP=0;
            return B.HP;
        }
    }
    else if(m=="拼点失败！")
    {
        if(A.HP>B.Max_value)
        {
            A.HP=A.HP-B.Max_value;
            return A.HP;
        }
        else
        {
            A.HP=0;
            return A.HP;
        }
    }
    else
    {
        return 0;
    }
}
