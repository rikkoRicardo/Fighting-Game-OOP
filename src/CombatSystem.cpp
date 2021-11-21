#include "stdafx.h"
#include "CombatSystem.h"
#include <map>

//Prototype variable to be replaced in the runtime
PlayerSystem game;

//Map to store all the fighters and index
std::map<uint16_t, Player>fighterList;

void CombatSystem::Start() {

	game.showPlayerData();

	//Creating a pair to attribute an id to a player
	fighterList.insert(std::make_pair(1, game.setPreferedFighter()));
	fighterList.insert(std::make_pair(2, game.setRandEnemy()));
	
	CombatSystem::StartCombat();
}

void CombatSystem::StartCombat() {
	bool turn = true;

	do {
		turn = !turn;

		if (turn)
		{ // player 1's turn
			CombatSystem::PlayerOneTurn();
		}
		else
		{ // player 2's turn
			CombatSystem::PlayerTwoTurn();
		}
		Sleep(500);

	} while (!CombatSystem::CheckWinner()); // if false - repeat , if true returns
	
}

void CombatSystem::PlayerOneTurn() {
	CheckHitTemplate(fighterList.at(1), fighterList.at(2));
}

void CombatSystem::PlayerTwoTurn() {
	CheckHitTemplate(fighterList.at(2), fighterList.at(1));
}

inline void CheckHitTemplate(Player& fighter, Player& victim) {
	const Attack& nextAttack = fighter.getNextAttack();
	const uint32_t& attackValue = nextAttack.getRandDamage();
	const uint32_t& defenseValue = victim.getRandDefense();

	// Make it display " Missed " instead of appearing the ugly zero
	if (!attackValue) { std::cout << fighter.getName() << " Missed!" << "\n\n"; return; }
	else 
	{
		if (attackValue > defenseValue) 
		{
			victim.getHit(attackValue);
			std::cout << fighter.getName() << " hits " << victim.getName() << " with " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n\n";
		}
		else 
		{
			std::cout << victim.getName() << " Defendeds " << fighter.getName() << "'s " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n\n";
		}
	}
}

bool CombatSystem::CheckWinner() 
{
	//check each player by reference
	for (auto& fighter: fighterList) {
		
		if(fighter.second.isDead()){
			std::cout << fighter.second.getName() << " is dead! " << "\n";
			return true;
		}
	}
	return false;

}
