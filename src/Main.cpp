// Main.cpp : Program execution begins and ends there. the game variable can be found at "Fight.h"
//By rikkoRicardo

//Essential includes
#include "stdafx.h"
#include "FightingGame.h"

int main()
{
	// pseudo-random number generator is initialized using the argument passed as seed.
	srand(static_cast<uint32_t>(time(nullptr)));

	//You can add up to two players, in this case, John God is the player 1 ( index 1 )
	game.setPlayer("John God", 100, 20);
	game.setPlayerAttack(1,"Powerful Punch", "This punch has been blessed by god!", 50);

	//presetList can be found in the Player header
	game.setPresetPlayer(1);

	CombatSystem::Start();
	
	//Temp
	std::cin.get();
}