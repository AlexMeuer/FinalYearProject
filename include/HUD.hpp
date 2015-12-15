#ifndef _HUD_H
#define _HUD_H

#include <SFML/Graphics.hpp>

#include <include/Pawn.hpp>

#include <SFGUI/SFGUI.hpp>
#include <SFGUI/Widgets.hpp>

namespace HUD_Detail
{
	struct HealthBarStatic {
		Pawn* mPawnToTrack;
		sfg::ProgressBar::Ptr mBar;
		const float M_MAX_HEALTH;

		HealthBarStatic(Pawn* pwn, sf::Vector2f const &location, sf::Vector2f const &size, sfg::Desktop &desktop);

		void update();
	};
}

class HUD {
public:
	HUD(std::shared_ptr<sfg::SFGUI> sfgui);	//Construct from xml when tinyXML implemented [hardcoded for now]
	~HUD();

	//! Updates the HUD. Elapsed time is required to update sfg::Desktop.
	void update(sf::Time const &elapsedTime);

	//! Draws all HUD elements to the specified window.
	void draw(sf::RenderWindow &window) const;

	//! Adds a health bar that follows a pawn.
	void addHealthBar(Pawn* pawn);

	//! Adds a bar that tracks a pawns health.
	void addHealthBarStatic(Pawn* pawn, sf::Vector2f const &location, sf::Vector2f const &size);

	/// Adds an image at the specified window location.
	/// \param filePath The location of the image in the filesystem.
	/// \param location Position of the image on the screen.
	void addImage(std::string const &filePath, sf::Vector2u location);

	/// Adds a repeating texture at the specified window location with width and height.
	/// \param filePath The location of the image in the filesystem.
	/// \param location The position of the image on the screen.
	/// \param widthAndHeight The width and height of the image to be displayed on the screen.
	void addImageArray(std::string const &filePath, sf::Vector2u location, sf::Vector2u widthAndHeight);

	//! Adds an image with label that tracks a value (e.g. coin image and amount of money)
	template<typename ValueType>
	void addImageWithLabel(std::string const &filePath, sf::Vector2u location, ValueType* labelValue);

private:
	//! HUD cannot be copy constructed
	HUD(HUD const &other) = delete;

	std::shared_ptr<sfg::SFGUI> mSFGUI;
	std::list<sfg::Widget::Ptr> mWidgets;

	std::list<HUD_Detail::HealthBarStatic*> mHealthBars;

	sfg::Desktop mDesktop;
};
#endif
