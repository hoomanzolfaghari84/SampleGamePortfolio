#pragma once
#include <cstdint>
#include <bitset>


namespace HEngine {

	using Entity = std::uint32_t;
	constexpr Entity MAX_ENTITIES = 5000;

	using ComponentType = std::uint8_t;
	constexpr ComponentType MAX_COMPONENTS = 32;

	using Signature = std::bitset<MAX_COMPONENTS>;

}