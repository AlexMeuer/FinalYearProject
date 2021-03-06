#ifndef GAME_CONSTANTS_HPP
#define GAME_CONSTANTS_HPP

#include <string>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

namespace Constants
{
	class Strings {
	public:
		//! This class cannot be instanciated.
		Strings();

		static std::string const& getGameName();	//!< The name of the game.
		static std::string const& getMainFontPath();	//!< Path to main font used for the game

		static std::string const& getPauseDialogueTitle();	//!< Title text for the in-game pause dialogue box.
		static std::string const& getPauseDialogueBody();	//!< Body text for the in-game pause dialogue box.
		static std::string const& getPauseDialogueYES();	//!< Confirmation text for in-game pause dialogue box.
		static std::string const& getPauseDialogueNO();		//!< Declination text for in-game pause dialogue box.

		static std::string const& getSettingsFilePath();	//!< Path to settings file
		static std::string const& getSettingsDialogueTitle();	//!< Title displayed at top of save-settings dialogue box
		static std::string const& getSettingsDialogueBody();	//!< Body text for save-settings dialogue box
		static std::string const& getSettingsDialogueYES();	//!< Confirmation text for settings dialogue
		static std::string const& getSettingsDialogueNO();	//!< Declination text for settings dialogue

		static std::string const& getCompletionDialogueTitle();
		static std::string const& getCompletionDialogueBody();
		static std::string const& getCompletionDialogueYES();
		static std::string const& getCompletionDialogueNO();

		static std::string const& getFailDialogueTitle();
		static std::string const& getFailDialogueBody();
		static std::string const& getFailDialogueYES();
		static std::string const& getFailDialogueNO();

		static std::string const& getLivesTexture();
		static std::string const& getMoneyTexture();
		static std::string const& getPortraitTexture();
	};

	class Numbers {
	public:
		Numbers() = delete;

		static float getCameraMoveSpeed();
		static float getCameraEdgeMoveThreshold();

		static unsigned int getMageTowerMaxTargets();

		static unsigned int getHeroMoveSoundChance();	//!< Chance, out of 100, that hero will play a sound when his destination is set.
	};

	class Vectors {
	public:
		//! This class cannot be instanciated.
		Vectors() = delete;

		static sf::Vector2f const& getCameraBounds();	//!< Camera edges cannot go beyond this volume (starts at 0,0)
		static sf::Vector2u const& getMinimumResolution();	//!< Gets the resolution of the monitor
		static sf::Vector2u const& getScreenSize();

		static sf::Vector2f const& getLivesPosition();
		static sf::Vector2f const& getLivesScale();
		static sf::Vector2f const& getLivesSpacing();

		static sf::Vector2f const& getMoneyIconPosition();
		static sf::Vector2f const& getMoneyPosition();
	};

	class Misc {
	public:
		Misc() = delete;
		static sf::Color const& getPrimaryTextColor();	//!< Color used for most text
		static sf::Color const& getSecondaryTextColor();
	};
};
#endif