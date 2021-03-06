#include <include/Damage.hpp>

Damage::Reduction::Reduction(const float _value) {
	value = _value;
}

float Damage::operator*=(float num, Reduction& red) {
	return red * num;
}

float Damage::Reduction::operator*(float x) const {
	return value * x;
}

Damage::Reduction& Damage::Reduction::operator=(float newValue) {
	value = newValue;
	return *this;
}

bool Damage::Reduction::operator<(Reduction const& other) const {
	return value < other.value;
}

bool Damage::Reduction::operator<=(Reduction const& other) const {
	return value <= other.value;
}

const float Damage::Reduction::NONE = 1.00f;
const float Damage::Reduction::LIGHT = 0.75f;
const float Damage::Reduction::MEDIUM = 0.50f;
const float Damage::Reduction::HEAVY = 0.25f;
const float Damage::Reduction::IMMUNE = 0.00f;