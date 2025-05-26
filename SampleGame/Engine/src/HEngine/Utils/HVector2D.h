#pragma once

namespace HEngine {
	class HVector2Di
	{
	public:
		const int x, y;
		HVector2Di(int x, int y) : x(x), y(y) {}
		HVector2Di(const HVector2Di& v) : x(v.x), y(v.y) {}

		HVector2Di& operator=(const HVector2Di& v) { return *this; } // No-op assignment, as x and y are const
		HVector2Di operator+(const HVector2Di& v) const { return HVector2Di(x + v.x, y + v.y); }
		HVector2Di operator-(const HVector2Di& v) const { return HVector2Di(x - v.x, y - v.y); }
		HVector2Di operator*(int scalar) const { return HVector2Di(x * scalar, y * scalar); }
		HVector2Di operator/(int scalar) const { return HVector2Di(x / scalar, y / scalar); }
		HVector2Di operator-() const { return HVector2Di(-x, -y); }
		
		static const HVector2Di Zero; // Declaration of Zero constant  
		static const HVector2Di One; // Declaration of Zero constant  
					
	};


	// Definition of Zero constant  
	const HVector2Di HVector2Di::Zero(0, 0);
	const HVector2Di HVector2Di::One(1, 1);


	class HVector2Df
	{
	public:
		const float x, y;
		HVector2Df(float x, float y) : x(x), y(y) {}
		HVector2Df(const HVector2Df& v) : x(v.x), y(v.y) {}
				 
		HVector2Df& operator=(const HVector2Df& v) { return *this; } // No-op assignment, as x and y are const
		HVector2Df operator+(const HVector2Df& v) const { return HVector2Df(x + v.x, y + v.y); }
		HVector2Df operator-(const HVector2Df& v) const { return HVector2Df(x - v.x, y - v.y); }
		HVector2Df operator*(float scalar) const { return HVector2Df(x * scalar, y * scalar); }
		HVector2Df operator/(float scalar) const { return HVector2Df(x / scalar, y / scalar); }
		HVector2Df operator-() const { return HVector2Df(-x, -y); }

		static const HVector2Df Zero; // Declaration of Zero constant  
		static const HVector2Df One; // Declaration of Zero constant  

	};

	const HVector2Df HVector2Df::Zero(0.0f, 0.0f);
	const HVector2Df HVector2Df::One(1.0f, 1.0f);

}

