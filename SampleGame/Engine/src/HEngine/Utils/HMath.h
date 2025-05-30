#pragma once

#include <cmath>
#include "HEngine/Core/Core.h"

namespace HEngine {

	// Degrees ? Radians conversion
	constexpr float DegToRad(float degrees) { return degrees * 0.01745329252f; } // PI / 180
	constexpr float RadToDeg(float radians) { return radians * 57.295779513f; } // 180 / PI

	// Clamp a value between min and max
	template<typename T>
	constexpr T Clamp(T value, T min, T max) {
		return (value < min) ? min : (value > max) ? max : value;
	}

	// Linear interpolation
	template<typename T>
	constexpr T Lerp(T a, T b, float t) {
		return a + (b - a) * t;
	}

	// Inverse linear interpolation
	template<typename T>
	constexpr float InverseLerp(T a, T b, T value) {
		if (a == b) return 0.0f;
		return static_cast<float>(value - a) / static_cast<float>(b - a);
	}

	// Normalize angle to [0, 360)
	inline float NormalizeAngle360(float angle) {
		while (angle < 0.0f) angle += 360.0f;
		while (angle >= 360.0f) angle -= 360.0f;
		return angle;
	}

	// Normalize angle to (-180, 180]
	inline float NormalizeAngle180(float angle) {
		angle = NormalizeAngle360(angle);
		if (angle > 180.0f) angle -= 360.0f;
		return angle;
	}
}