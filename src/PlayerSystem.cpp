#include "stdafx.h"
#include "PlayerSystem.h"
#include "Player.h"

Player PlayerSystem::setPreferedFighter() {
	uint16_t chosenFighter;	

	for (auto& player : playerMap) {
		//Player.first being the ID, Player.second being the actual player
		 std::cout << player.first << " - " << player.second.getName() << '\n';
	}
	std::cout << "0 - Quit\n";

	std::cout << "\nChoose your main char: \n";

	do{
		std::cin >> chosenFighter;

		if (chosenFighter == 0) exit(NULL);

	} while (playerMap.find(chosenFighter) == playerMap.end());

	preferedPlayerId = chosenFighter;
	return playerMap.at(chosenFighter);
}

Player PlayerSystem::setRandEnemy()
{
	if (playerMap.size() < 2)
		return NULL;

	if (playerMap.size() == 2)
	{
		uint16_t chosenPlayer = preferedPlayerId == 1 ? 2 : 1;
		return playerMap.at(chosenPlayer);
	}
	auto it = playerMap.begin();
	
	// creates a random value in map and stores in the iterator it
	while(it->first == preferedPlayerId)
		std::advance(it, rand() % playerMap.size());	
	return playerMap.at(it->first);
}

void PlayerSystem::setPlayer(const std::string name,const int16_t hp,const uint16_t defense)
{
	setPlayerTemplate(NULL, name, hp, defense);
}

void PlayerSystem::setPresetPlayer(const uint16_t DefaultPresetNumber) {

	setPlayerTemplate(DefaultPresetNumber);
}

inline void PlayerSystem::setPlayerTemplate(const uint16_t DefaultPresetNumber,const std::string name,const int16_t hp,const uint16_t defense)
{
	Player createdPlayer = Player(DefaultPresetNumber);

	if (playercounter < 4)
	{
		if (hp != 0 && defense != 0) {
			createdPlayer = Player(name, hp, defense);
		}

		playerMap.insert(std::make_pair(playercounter, createdPlayer));
	}
	else
	{
		std::cout << "Player Limit reached! \n";
		return;
	}
	playercounter++;
}

void PlayerSystem::showPlayerData()
{
	//print the player data with the overrided operator "<<" for each player
	for (auto& eachPlayer : playerMap) {
		std::cout << eachPlayer.second << "\n";
		eachPlayer.second.showPlayerAttacks();
	}
}

void PlayerSystem::setPlayerAttack(const uint16_t index,const std::string name,const std::string description,const uint32_t dmg) 
{
		if (playerMap.find(index) != playerMap.end())
			playerMap.at(index).AddAttack(name, description, dmg);
		else std::cout << "Player Attack index used " << index <<" results in a error!\n";
}
