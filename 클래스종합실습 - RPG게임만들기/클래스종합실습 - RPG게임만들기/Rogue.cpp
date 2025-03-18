#include <iostream>
#include "Rogue.h"
using namespace std;

class Rogue : public Character {
	Rogue() : Character("도적(Rogue)", 1, 90, 12) {}

	void attack() override {
		cout << name << "의 공격 ! " << endl;
		cout << attackPower << "의 데미지를 입혔다!" << endl;
		health -= attackPower;
	}

	void specialAttack() override {
		cout << name << "의 급습(ambush) !" << endl;
		cout << attackPower * 2 << "의 데미지를 입혔다!" << endl;
		health -= attackPower * 2;
	}
};