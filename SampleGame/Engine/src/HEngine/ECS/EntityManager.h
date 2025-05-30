#pragma once
#include "ECSTypes.hpp"
#include <queue>
#include <array>
#include <cassert>


namespace HEngine {

    class EntityManager {
    public:
        EntityManager();

        Entity CreateEntity();
        void DestroyEntity(Entity entity);
        void SetSignature(Entity entity, Signature signature);
        Signature GetSignature(Entity entity) const;

    private:
        std::queue<Entity> availableEntities;
        std::array<Signature, MAX_ENTITIES> signatures;
        uint32_t livingEntityCount = 0;
    };

}

