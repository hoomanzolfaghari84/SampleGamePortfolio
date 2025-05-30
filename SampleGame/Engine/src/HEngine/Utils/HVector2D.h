#pragma once

#include "HEngine/Core/Core.h"
#include <cmath>


namespace HEngine {

	struct HENGINE_API HVector2Di {
		int x = 0.0f;
		int y = 0.0f;

		constexpr HVector2Di operator+(const HVector2Di& v) const { return { x + v.x, y + v.y }; }
		constexpr HVector2Di operator-(const HVector2Di& v) const { return { x - v.x, y - v.y }; }
		constexpr HVector2Di operator*(int scalar) const { return { x * scalar, y * scalar }; }
		constexpr HVector2Di operator/(int scalar) const { return { x / scalar, y / scalar }; }
		constexpr HVector2Di operator-() const { return { -x, -y }; }

		// Compound assignment
		HVector2Di& operator+=(const HVector2Di& v) { x += v.x; y += v.y; return *this; }
		HVector2Di& operator-=(const HVector2Di& v) { x -= v.x; y -= v.y; return *this; }
		HVector2Di& operator*=(float scalar) { x *= scalar; y *= scalar; return *this; }
		HVector2Di& operator/=(float scalar) { x /= scalar; y /= scalar; return *this; }

		// Static constants
		static constexpr HVector2Di Zero() { return { 0, 0 }; }
		static constexpr HVector2Di One() { return { 1, 1 }; }
		static constexpr HVector2Di Up() { return { 0, -1 }; }
		static constexpr HVector2Di Down() { return { 0, 1 }; }
		static constexpr HVector2Di Left() { return { -1, 0 }; }
		static constexpr HVector2Di Right() { return { 1, 0 }; }

	};

	struct HENGINE_API HVector2Df {
		float x = 0.0f;
		float y = 0.0f;

		constexpr HVector2Df operator+(const HVector2Df& v) const { return { x + v.x, y + v.y }; }
		constexpr HVector2Df operator-(const HVector2Df& v) const { return { x - v.x, y - v.y }; }
		constexpr HVector2Df operator*(float scalar) const { return { x * scalar, y * scalar }; }
		constexpr HVector2Df operator*(const HVector2Df& v) const { return { x * v.x, y * v.y }; }
		constexpr HVector2Df operator/(float scalar) const { return { x / scalar, y / scalar }; }
		constexpr HVector2Df operator-() const { return { -x, -y }; }

		// Compound assignment
		HVector2Df& operator+=(const HVector2Df& v) { x += v.x; y += v.y; return *this; }
		HVector2Df& operator-=(const HVector2Df& v) { x -= v.x; y -= v.y; return *this; }
		HVector2Df& operator*=(float scalar) { x *= scalar; y *= scalar; return *this; }
		HVector2Df& operator/=(float scalar) { x /= scalar; y /= scalar; return *this; }

		// Static constants
		static constexpr HVector2Df Zero() { return { 0.f, 0.f }; }
		static constexpr HVector2Df One() { return { 1.f, 1.f }; }
		static constexpr HVector2Df Up() { return { 0.f, -1.f }; }
		static constexpr HVector2Df Down() { return { 0.f, 1.f }; }
		static constexpr HVector2Df Left() { return { -1.f, 0.f }; }
		static constexpr HVector2Df Right() { return { 1.f, 0.f }; }


		// Math utilities
		float Length() const { return std::sqrt(x * x + y * y); }
		constexpr float LengthSquared() const { return x * x + y * y; }

		HVector2Df Normalized() const {
			float len = Length();
			if (len == 0.0f) return { 0.f, 0.f };
			return { x / len, y / len };
		}

		static constexpr float Dot(const HVector2Df& a, const HVector2Df& b) {
			return a.x * b.x + a.y * b.y;
		}

		static float Distance(const HVector2Df& a, const HVector2Df& b) {
			return (a - b).Length();
		}

		static constexpr float DistanceSquared(const HVector2Df& a, const HVector2Df& b) {
			return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
		}

		static HVector2Df Lerp(const HVector2Df& a, const HVector2Df& b, float t) {
			return a + (b - a) * t;
		}

	};


}
