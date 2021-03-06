//Attack.h - The Attack class to make the attacks easy to manage
//made by RikkoRicardo

#pragma once

#include "stdafx.h"

class Attack
{

private:
	std::string Name = "";
	std::string Description = "";
	uint32_t Dmg = 0;

public:
	enum PresetAttackNums : uint16_t 
	{
		Default = 1
	};

	Attack(std::string name, std::string description, uint32_t dmg) : Name(name), Description(description), Dmg(dmg) {}

	//Attack Presets - feel free to add
	Attack(uint16_t number) {
		switch (number)
		{
		case Default:
			Attack DefaultPreset = Attack(this->Name = "Default Attack",this->Description = "Default Attack",this->Dmg = 30);
		}
	}

	//Creating getters for the attributes so we can use them
	virtual std::string getName() const { return this->Name; }
	virtual std::string getDescription() const { return this->Description; }
	virtual std::uint32_t getDmgInfo() const { return this->Dmg; }

	uint16_t getRandDamage() const { return rand() % this->Dmg; }

};

//Operator overload so we can use it later
inline
std::ostream& operator<< (std::ostream& obj, Attack& attack) {
	return	obj <<'\n' << attack.getName() << " - " << attack.getDmgInfo() << " DMG\n"
			    <<"Description: " << attack.getDescription() << "\n";
}