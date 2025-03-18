#pragma once
#include <iostream>
#include "Character.h"
using namespace std;

class Rogue : public Character {
public:
	Rogue();

	void attack() override {}

	void specialAttack() override {}
};
