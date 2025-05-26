#pragma once

namespace HEngine {

	class HVector2Di {
	public:
		const int x, y;

		HVector2Di(int x, int y);
		HVector2Di(const HVector2Di& v);

		HVector2Di& operator=(const HVector2Di& v) = delete;
		HVector2Di operator+(const HVector2Di& v) const;
		HVector2Di operator-(const HVector2Di& v) const;
		HVector2Di operator*(int scalar) const;
		HVector2Di operator/(int scalar) const;
		HVector2Di operator-() const;

		static const HVector2Di Zero;
		static const HVector2Di One;

		
	};

	class HVector2Df {
	public:
		const float x, y;

		HVector2Df(float x, float y);
		HVector2Df(const HVector2Df& v);

		HVector2Df& operator=(const HVector2Df& v) = delete;
		HVector2Df operator+(const HVector2Df& v) const;
		HVector2Df operator-(const HVector2Df& v) const;
		HVector2Df operator*(float scalar) const;
		HVector2Df operator/(float scalar) const;
		HVector2Df operator-() const;

		static const HVector2Df Zero;
		static const HVector2Df One;

		
	};

}
