#include <iostream>
#include "Warrior.h"
using namespace std;

class Warrior : public Character {
	Warrior() : Character("전사(Warrior)", 1, 100, 15) {}

	void attack() override {
		cout << name << "의 공격 ! " << endl;
		cout << attackPower << "의 데미지를 입혔다!" << endl;
		health -= attackPower;
	}

	void specialAttack() override {
		cout << name << "의 강력한 일격 (PowerStrike) !" << endl;
		cout << attackPower * 2 << "의 데미지를 입혔다!" << endl;
		health -= attackPower * 2;
		health -= 5;
	}
};