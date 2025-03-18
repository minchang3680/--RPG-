#pragma once
#include <iostream>
#include "Character.h"
using namespace std;

class Warrior : public Character {
public:
	Warrior();

	void attack() override {}

	void specialAttack() override {}
};
