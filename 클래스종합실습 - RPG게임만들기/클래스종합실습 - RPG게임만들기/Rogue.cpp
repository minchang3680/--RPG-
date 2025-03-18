#include <iostream>
#include "Rogue.h"
using namespace std;

class Rogue : public Character {
	Rogue() : Character("����(Rogue)", 1, 90, 12) {}

	void attack() override {
		cout << name << "�� ���� ! " << endl;
		cout << attackPower << "�� �������� ������!" << endl;
		health -= attackPower;
	}

	void specialAttack() override {
		cout << name << "�� �޽�(ambush) !" << endl;
		cout << attackPower * 2 << "�� �������� ������!" << endl;
		health -= attackPower * 2;
	}
};