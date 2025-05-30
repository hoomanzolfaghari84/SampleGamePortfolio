#include "HVector2D.h"

namespace HEngine {

	// --- HVector2Di ---
	HVector2Di::HVector2Di(int x, int y) : x(x), y(y) {}
	HVector2Di::HVector2Di(const HVector2Di& v) : x(v.x), y(v.y) {}
	//HVector2Di& HVector2Di::operator=(const HVector2Di& v) { return *this; } // No-op (not recommended, but valid)
	HVector2Di HVector2Di::operator+(const HVector2Di& v) const { return HVector2Di(x + v.x, y + v.y); }
	HVector2Di HVector2Di::operator-(const HVector2Di& v) const { return HVector2Di(x - v.x, y - v.y); }
	HVector2Di HVector2Di::operator*(int scalar) const { return HVector2Di(x * scalar, y * scalar); }
	HVector2Di HVector2Di::operator/(int scalar) const { return HVector2Di(x / scalar, y / scalar); }
	HVector2Di HVector2Di::operator-() const { return HVector2Di(-x, -y); }

	const HVector2Di HVector2Di::Zero(0, 0);
	const HVector2Di HVector2Di::One(1, 1);

	// --- HVector2Df ---
	HVector2Df::HVector2Df(float x, float y) : x(x), y(y) {}
	HVector2Df::HVector2Df(const HVector2Df& v) : x(v.x), y(v.y) {}
	//HVector2Df& HVector2Df::operator=(const HVector2Df& v) { return *this; } // No-op (not recommended, but valid)
	HVector2Df HVector2Df::operator+(const HVector2Df& v) const { return HVector2Df(x + v.x, y + v.y); }
	HVector2Df HVector2Df::operator-(const HVector2Df& v) const { return HVector2Df(x - v.x, y - v.y); }
	HVector2Df HVector2Df::operator*(float scalar) const { return HVector2Df(x * scalar, y * scalar); }
	HVector2Df HVector2Df::operator/(float scalar) const { return HVector2Df(x / scalar, y / scalar); }
	HVector2Df HVector2Df::operator-() const { return HVector2Df(-x, -y); }

	const HVector2Df HVector2Df::Zero(0.0f, 0.0f);
	const HVector2Df HVector2Df::One(1.0f, 1.0f);

}
