#include "Component.h"
#include <SFML/Graphics.hpp>


HEngine::UIComponent::UIComponent(std::string text, float x, float y, float width, float height) : text(std::move(text)), x(x), y(y), width(width), height(height)
{
}


HEngine::BoxCollisionComponent::BoxCollisionComponent(float x, float y, float width, float height) : x(x), y(y), width(width), height(height)
{
}
