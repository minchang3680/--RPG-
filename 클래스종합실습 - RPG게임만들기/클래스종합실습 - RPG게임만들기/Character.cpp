#include "character.h"

Character::Character(string n, int l, int h, int a) 
	: name(n), level(l), health(h), attackPower(a) {}

// name(����), level(1), health(100), attackPower(15)��� ����.�� �Ѵٸ�???

void Character::takeDamage(int damage) {
	health -= attack or specialAttack;

}

void Character::isAlive() {
	if (health <= 0) {
		cout << "false" << endl;
	}
}

void Character::showStatus() {
	cout << "���� �� : " << name << endl;
	cout << "���� : " << level << endl;
	cout << "ü�� : " << health << endl;
	cout << "���ݷ� : " << attackPower << endl;
}

void Character:: resetHealth() {
	if (name == "����(Warrior)") {
		health == 100;
	}

	else if (name == "������(Mage)") {
		health == 80;
	}
	else if (name == "����(Rogue)") {
		health == 90;
	}
}


