#include <iostream>
using namespace std;
class SkillDamage {
private:
    int* m_damageArray; // 存储伤害数值的动态数组
    int m_size;         // 伤害段数
public:
    // ⭐ 1. 构造函数：申请内存并初始化
    SkillDamage(int size) {
        m_size = size;
        m_damageArray = new int[m_size]; // 申请数组内存
        cout << "[构造] 技能伤害数组已生成，段数：" << m_size << endl;
    }
    // ⭐ 2. 深拷贝构造函数：防止浅拷贝导致的双重释放崩溃
    SkillDamage(const SkillDamage& other) {
        m_size = other.m_size;
        m_damageArray = new int[m_size]; // 重新申请独立内存
        for (int i = 0; i < m_size; i++) {
            m_damageArray[i] = other.m_damageArray[i]; // 复制数据
        }
        cout << "[拷贝构造] 执行深拷贝，防止内存冲突！" << endl;
    }
    // ⭐ 3. 析构函数：释放内存，防止泄漏
    ~SkillDamage() {
        delete[] m_damageArray; // 释放数组必须加 []
        cout << "[析构] 技能结束，伤害数组内存已释放！" << endl;
    }
    // 辅助功能：设置指定段数的伤害
    void setDamage(int index, int val) {
        if (index >= 0 && index < m_size) {
            m_damageArray[index] = val;
        } else {
            cout << "[警告] 伤害段数越界！" << endl;
        }
    }
    // 辅助功能：打印所有伤害
    void printDamage() const {
        cout << "伤害列表: ";
        for (int i = 0; i < m_size; i++) {
            cout << m_damageArray[i] << " ";
        }
        cout << endl;
    }
};
// 测试深拷贝的函数
void testDeepCopy() {
    cout << "\n--- 进入深拷贝测试函数 ---" << endl;
    SkillDamage skill1(3);
    skill1.setDamage(0, 100);
    skill1.setDamage(1, 200);
    skill1.setDamage(2, 300);
    // ⭐ 触发拷贝构造函数
    SkillDamage skill2 = skill1;
    cout << "--- 即将离开测试函数，触发析构 ---" << endl;
} // 在这里，skill2 和 skill1 会依次自动析构
int main() {
    system("chcp 65001");
    cout << "=== 游戏开始 ===" << endl;
    SkillDamage fireball(3);
    fireball.setDamage(0, 150);
    fireball.setDamage(1, 150);
    fireball.setDamage(2, 999); // 暴击
    fireball.printDamage();
    testDeepCopy(); // 演示深拷贝的威力
    cout << "\n=== 游戏结束（观察析构自动调用） ===" << endl;
    return 0;
}
