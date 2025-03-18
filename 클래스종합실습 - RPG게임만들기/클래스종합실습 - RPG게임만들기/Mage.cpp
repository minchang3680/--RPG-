#include <iostream>
#include "Mage.h"
using namespace std;

class Mage : public Character {
	Mage() : Character("마법사(Mage)", 1, 80, 18) {}
	int mana;

	void attack() override {

		cout << name << "의 공격 ! " << endl;
		cout << attackPower << "의 데미지를 입혔다!" << endl;
		health -= attackPower;
	}

	void specialAttack() override {
		cout << name << "의 파이어볼(Fireball) !" << endl;
		cout << attackPower * 1.5 << "의 데미지를 입혔다!" << endl;
		health -= attackPower * 1.5;
		if (mana <= 0) {
			cout << "파이어 볼을 사용하려하였으나 마나가 없어 기본공격을 하였다 !" << endl;
			health -= attackPower;
		}
	
	}
};