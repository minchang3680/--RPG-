#include "character.h"

Character::Character(string n, int l, int h, int a) 
	: name(n), level(l), health(h), attackPower(a) {}

// name(전사), level(1), health(100), attackPower(15)라고 설정.을 한다면???

void Character::takeDamage(int damage) {
	health -= attack or specialAttack;

}

void Character::isAlive() {
	if (health <= 0) {
		cout << "false" << endl;
	}
}

void Character::showStatus() {
	cout << "직업 명 : " << name << endl;
	cout << "레벨 : " << level << endl;
	cout << "체력 : " << health << endl;
	cout << "공격력 : " << attackPower << endl;
}

void Character:: resetHealth() {
	if (name == "전사(Warrior)") {
		health == 100;
	}

	else if (name == "마법사(Mage)") {
		health == 80;
	}
	else if (name == "도적(Rogue)") {
		health == 90;
	}
}


