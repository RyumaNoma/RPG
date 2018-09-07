#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Person{
protected:
  string name;
  int HP;
  int power; //攻撃力
  int def; //防御力

public:
  bool is_dead(){
    return (HP==0)?true:false;
  }
  void damage(int point) {
    HP -= point;
    cout << name << "はダメージ" << point << "を食らった" << endl;
    if (HP<0) {
      HP = 0;
      cout << name << "は死んでしまった！" << endl;
    }
  }
};

class Knight : public Person {
private:
  int EXP;
  int maxHP;
  int level;
  string say;

public:
  //コンストラクタ（初期化
  Knight() {
    name = "";
    HP = 10;
    maxHP = 10;
    level = 0;
    EXP = 0;
    power = 10;
    def = 5;
    say = "";
  }

  Knight(string name) {
    this -> name = name;
    HP = 10;
    maxHP = 10;
    level = 0;
    EXP = 0;
    power = 10;
    def = 5;
    say = "";
  }

  //デストラクタ
  ~Knight() {
  }

  void info() {
    cout
    << "〇名前：" << name
    << "〇体力：" << HP << "/" << maxHP
    << "〇レベル：" << level
    << "〇経験値：" << EXP
    << "〇攻撃力：" << power
    << "〇防御力：" << def
    << endl;
  };
  // 経験値をゲットする
    void add_EXP(int EXP) {
        if (EXP < 0) return;
        this->EXP += EXP;
        calc_level();
    }

    // レベルの計算
    void calc_level(void) {
        level = sqrt(2.0*(EXP+1.0)/3.0+289.0/36.0)-17.0/6.0 + 1.0;
        maxHP = 5 + 5 * level;
        power = 10 + level;
        def = 5 + level;
    }

    // 次のレベルに上がるための計算
    void calc_next_level(void) {
        int needEXP = (3.0*level*level/2.0 + 17.0*level/2.0) - EXP;
        cout << "次のレベルに上がるまであと" << needEXP << "の経験値が必要です。" << endl;
    }
    void set_say(string say){
        this -> say = say;
    }
    void get_say(){
        cout << say << endl;
    }
};
//敵クラス
class Enemy : public Person {
private:

public:
};

int main() {
  //初期化、名前
  Knight player("noma");
  player.set_say("yeah!!");

  //状態表示
  player.info();
  player.get_say();

  //ダメージ５
  player.damage(5);

  //状態表示
  player.info();
  player.get_say();

  //次のレベルに上がるための計算
  player.calc_next_level();

}
