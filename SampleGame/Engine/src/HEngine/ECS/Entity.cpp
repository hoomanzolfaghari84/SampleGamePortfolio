#include "Entity.h"

void Entity::Update(float dt) {
    for (auto& comp : components)
        comp->Update(dt);
}

void Entity::Render(sf::RenderWindow& window) {
    for (auto& comp : components)
        comp->Render(window);
}
