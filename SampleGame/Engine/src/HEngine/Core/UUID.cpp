#include "hepch.h"
#include "UUID.h"

#include <random>

namespace HEngine {

	static std::random_device s_RandomDevice;
	static std::mt19937_64 s_Engine(s_RandomDevice());
	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;

	UUID::UUID()
		: m_UUID(s_UniformDistribution(s_Engine))
	{
	}

	UUID::UUID(uint64_t uuid)
		: m_UUID(uuid)
	{
	}

}

//#include "UUID.h"
//#include <random>
//#include <sstream>
//#include <iomanip>
//
//namespace HEngine {
//
//	static std::random_device s_RandomDevice;
//	static std::mt19937_64 s_Engine(s_RandomDevice());
//	static std::uniform_int_distribution<uint64_t> s_UniformDistribution;
//
//	UUID::UUID()
//		: m_High(s_UniformDistribution(s_Engine)), m_Low(s_UniformDistribution(s_Engine)) {
//	}
//
//	UUID::UUID(uint64_t high, uint64_t low)
//		: m_High(high), m_Low(low) {
//	}
//
//	std::string UUID::ToString() const {
//		std::ostringstream oss;
//		oss << std::hex << std::setfill('0')
//			<< std::setw(16) << m_High
//			<< std::setw(16) << m_Low;
//		return oss.str();
//	}
//
//}
