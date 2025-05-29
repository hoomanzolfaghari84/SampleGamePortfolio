#pragma once

#include "EntityManager.h"
#include "ComponentRegistry.h"

namespace HEngine {
    class System {
    public:
        virtual void Update(EntityManager& entityManager, ComponentRegistry& componentRegistry, float dt) = 0;
        virtual ~System() = default;
    };


}


