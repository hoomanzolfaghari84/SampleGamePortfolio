#pragma once
#include "ECSTypes.hpp"
#include <typeindex>
#include "System.h"

namespace HEngine {

	class System;

    class SystemManager {
    public:
        template<typename T>
        inline std::shared_ptr<T> RegisterSystem();

        template<typename T>
        inline void SetSignature(Signature signature);

        void EntityDestroyed(Entity entity);
        void EntitySignatureChanged(Entity entity, Signature signature);

    private:
        std::unordered_map<std::type_index, Signature> signatures;
        std::unordered_map<std::type_index, std::shared_ptr<System>> systems;
    };


    template<typename T>
    inline std::shared_ptr<T> SystemManager::RegisterSystem() {
        const std::type_index typeName = typeid(T);
        assert(systems.find(typeName) == systems.end() && "System already registered.");
        auto system = std::make_shared<T>();
        systems[typeName] = system;
        return system;
    }

    template<typename T>
    inline void SystemManager::SetSignature(Signature signature) {
        const std::type_index typeName = typeid(T);
        assert(systems.find(typeName) != systems.end() && "System not registered.");
        signatures[typeName] = signature;
    }



}

