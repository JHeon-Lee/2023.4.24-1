// 2023.4.24,1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

/*
    클래스에서 상속이란?
    부모 클래스로부터 자식 클래스로 변수 또는 함수를 물려주는 시스템
*/

/*
    virtual function(가상 함수)
    c++은 다형성이라는 특성을 지원하기 위해 virtual 키워드를 제공 // 상속을 쓰는 이유
    부모 클래스 내에서 virtual로 선언된 함수는 자식 클래스에서 재정의 될 수 있다!
    만약에 재정의 하지 않고 호출을 한다면 부모의 함수가 호출된다
    재정의 했다면 재정의된 자식의 클래스가 호출된다
*/
class cWeapon // 부모 클래스
{
private:
    int m_nTest;

protected: // 외부에선 접근 불가능하지만, 상속받은 자식 클래스에서 접근 가능
    int m_nAttDamage; // 공격력
    int m_nDurability; // 내구도

public:
    virtual void Attack() // 공격하기 - 가상함수
    {
        cout << "맨손 공격!!" << endl;
    }
    virtual void Defence() // 방어하기 - 가상함수
    {
        cout << "방어 하기!!" << endl;
    }

    int GetTest() { return m_nTest; }
    void SetTest(int test) { m_nTest = test; }
};

class cSword : public cWeapon // 자식 클래스 : 부모 클래스
{ 
public:
    //int GetTest() { return m_nTest; } 불가능
    //void SetTest(int test) { m_nTest = test; } 불가능 ---> m_nTest는 부모 클래스의 private
    //int GetAttDamage() { return m_nAttDamage; } 가능
    //void SetAttDamage(int attDamage) { m_nAttDamage = attDamage; } 가능
    //int GetDurability() { return m_nDurability; } 가능
    //void SetDurability(int durability) { m_nDurability = durability; } 가능 ---> protected 인자들은 자식클래스에서 액세스 가능
    void Attack() override // 재정의 했다는 표시
    {
        cout << "칼로 공격!!" << endl;
    }
    void Defence() override // 재정의 했다는 표시
    {
        cout << "칼로 방어!!" << endl;
    }
};

class cGun : public cWeapon
{
public:
    void Attack() override
    {
        cout << "총으로 공격!!" << endl;
    }
    void Defence() override
    {
        cout << "총으로 방어!!" << endl;
    }
};

int main()
{
    //cSword sword;

    //sword.Attack();
    //sword.Defence();
    //sword.GetTest();
    //sword.SetTest(10);

    cSword sword;

    sword.Attack();

    cWeapon* pWeapon = new cWeapon;
    pWeapon->Attack();
    pWeapon->Defence();
    delete pWeapon;

    pWeapon = new cSword; // 상속을 활용하면 교체가 용이
    pWeapon->Attack();
    pWeapon->Defence();
    delete pWeapon;

    system("pause");

    return 0;
}
