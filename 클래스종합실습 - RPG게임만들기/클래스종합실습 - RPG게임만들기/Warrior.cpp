#include <iostream>
#include "Warrior.h"
using namespace std;

class Warrior : public Character {
	Warrior() : Character("����(Warrior)", 1, 100, 15) {}

	void attack() override {
		cout << name << "�� ���� ! " << endl;
		cout << attackPower << "�� �������� ������!" << endl;
		health -= attackPower;
	}

	void specialAttack() override {
		cout << name << "�� ������ �ϰ� (PowerStrike) !" << endl;
		cout << attackPower * 2 << "�� �������� ������!" << endl;
		health -= attackPower * 2;
		health -= 5;
	}
};