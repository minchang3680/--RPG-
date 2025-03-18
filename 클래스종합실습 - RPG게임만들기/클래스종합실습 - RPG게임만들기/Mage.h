#pragma once
#include <iostream>
#include "Character.h"
using namespace std;

class Mage : public Character {
public:
	Mage();

	void attack() override {}

	void specialAttack() override {}
};
