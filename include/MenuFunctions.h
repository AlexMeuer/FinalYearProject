#ifndef _MENU_FUNCS_H
#define _MENU_FUNCS_H
#include <stdlib.h>
#include <iostream>
#include <SFML/System/String.hpp>
#include <include/SceneManager.hpp>

namespace MenuFunctions
{
	//Output to console the name of the item followed by "activated!"
	inline void output(sf::String string) {
		std::cout << string.toAnsiString() << " activated!" << std::endl;
	}

	//Navigate to a scene (if one has been set up for the item)
	inline void changeScene(sf::String string) {
		output(string);

		if (string == "Start")
			SceneManager::instance()->navigateToScene("Level");

		/*else if (string == "Options")
			SceneManager::instance()->navigateToScene("OPTIONS_MENU");

		else if (string == "Back")
			SceneManager::instance()->navigateToScene("MAIN_MENU");*/

		else
			std::cout << "No suitable scene to change to!\nDid you set one up in MenuFunctions.h?" << std::endl;
	}

	inline void exitProgram(sf::String string) {
		output(string);
		std::cout << "Program terminated with string: " << string.toAnsiString() << std::endl;
		exit(EXIT_SUCCESS);	//not ideal but alternative will have to wait
		// (ideally we want to return from main, not call exit(0))
	}
}
#endif