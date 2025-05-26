#include "Entity.h"



template<typename T, typename ...Args>
T& HEngine::Entity::AddComponent(Args && ...args)
{
    std::type_index type = typeid(T);
    assert(!HasComponent<T>() && "Entity already has component!");

    auto comp = std::make_unique<T>(std::forward<Args>(args)...);
    comp->entity = this;
    m_Components[type] = std::move(comp);

    return *static_cast<T*>(m_Components[type].get());
}

template<typename T>
T& HEngine::Entity::GetComponent()
{
    std::type_index type = typeid(T);
    assert(HasComponent<T>() && "Entity does not have component!");
    return *static_cast<T*>(m_Components[type].get());
}

template<typename T>
bool HEngine::Entity::HasComponent() const
{
    return m_Components.find(typeid(T)) != m_Components.end();
}

template<typename T>
inline void HEngine::Entity::RemoveComponent()
{
    std::type_index type = typeid(T);
    assert(HasComponent<T>() && "Entity does not have component!");
    m_Components.erase(type);
}
