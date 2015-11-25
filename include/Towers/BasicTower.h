#ifndef _BASIC_TOWER_H
#define _BASIC_TOWER_H

#include <include/Actor.hpp>
#include <include/Damage.hpp>
#include <include/Projectile.h>
#include <include/Pawn.hpp>

namespace tower
{
	class BasicTower : public Actor {
		
		float mRange;
		float mAttacksPerSecond;

		Damage::Type mDamageType;
		int mDamage;

		Projectile mProjectile;

	public:
		BasicTower(sf::Texture &texture, sf::Vector2f position, float range, float attacksPerSecond, int damage, Damage::Type damageType);
		virtual ~BasicTower();

		void update(sf::Time const &elapsedTime);

		virtual void draw(sf::RenderTarget &target);

		bool acquireTarget(std::vector<Pawn*> const &possibleTargets);	//yet another method to be replaced by chaiscript
	};
}
#endif