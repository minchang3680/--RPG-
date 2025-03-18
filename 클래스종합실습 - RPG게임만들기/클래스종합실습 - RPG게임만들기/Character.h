#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character {
protected:
	string name;
	int level;
	int health;
	int attackPower;

public:
	Character(string n, int l, int h, int a);

	virtual void attack() = 0;
	virtual void specialAttack() = 0;
	void takeDamage(int damage);
	void isAlive();
	void showStatus();
	void resetHealth();

};
