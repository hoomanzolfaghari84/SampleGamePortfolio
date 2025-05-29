#pragma once

#include <cstdint>  // for uint64_t
#include "../Initializations/Core.h"


namespace HEngine {

	class HENGINE_API UUID
	{
	public:
		UUID();
		UUID(uint64_t uuid);
		//explicit UUID(uint64_t uuid);
		UUID(const UUID&) = default;

		operator uint64_t() const { return m_UUID; }

		bool operator==(const UUID& other) const { return m_UUID == other.m_UUID; }
		bool operator!=(const UUID& other) const { return !(*this == other); }

	private:
		uint64_t m_UUID;
	};

}

namespace std {
	template <typename T> struct hash;

	template<>
	struct hash<HEngine::UUID>
	{
		inline size_t operator()(const HEngine::UUID& uuid) const noexcept
		{
			return static_cast<uint64_t>(uuid);
		}
	};
}