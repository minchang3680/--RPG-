#include <iostream>
#include "Mage.h"
using namespace std;

class Mage : public Character {
	Mage() : Character("������(Mage)", 1, 80, 18) {}
	int mana;

	void attack() override {

		cout << name << "�� ���� ! " << endl;
		cout << attackPower << "�� �������� ������!" << endl;
		health -= attackPower;
	}

	void specialAttack() override {
		cout << name << "�� ���̾(Fireball) !" << endl;
		cout << attackPower * 1.5 << "�� �������� ������!" << endl;
		health -= attackPower * 1.5;
		if (mana <= 0) {
			cout << "���̾� ���� ����Ϸ��Ͽ����� ������ ���� �⺻������ �Ͽ��� !" << endl;
			health -= attackPower;
		}
	
	}
};