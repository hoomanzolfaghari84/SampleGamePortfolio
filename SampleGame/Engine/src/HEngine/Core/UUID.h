#pragma once
#include "UUID.h"

//#include <cstdint>  // for uint64_t
//#include <algorithm>

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
		std::size_t operator()(const HEngine::UUID& uuid) const noexcept
		{
			return static_cast<uint64_t>(uuid);
		}
	};
}


//#pragma once
//
//#include <cstdint>
//#include "../Initializations/Core.h"
//
//namespace HEngine {
//
//	class HENGINE_API UUID
//	{
//	public:
//		UUID(); // Generate random 128-bit UUID
//		UUID(uint64_t high, uint64_t low);
//		UUID(const UUID&) = default;
//
//		uint64_t High() const { return m_High; }
//		uint64_t Low() const { return m_Low; }
//
//		bool operator==(const UUID& other) const {
//			return m_High == other.m_High && m_Low == other.m_Low;
//		}
//		bool operator!=(const UUID& other) const {
//			return !(*this == other);
//		}
//
//		// Optional: Convert to string for debugging/logging
//		std::string ToString() const;
//
//	private:
//		uint64_t m_High;
//		uint64_t m_Low;
//	};
//
//}
//
//namespace std {
//	template<> struct hash<HEngine::UUID>
//	{
//		size_t operator()(const HEngine::UUID& uuid) const noexcept {
//			return hash<uint64_t>()(uuid.High()) ^ hash<uint64_t>()(uuid.Low());
//		}
//	};
//}
