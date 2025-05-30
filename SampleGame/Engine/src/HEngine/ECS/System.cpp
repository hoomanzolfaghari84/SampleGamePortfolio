#include "hepch.h"
#include "System.h"
#include "Component.h"
#include "Coordinator.h"

sf::Color HEngine::ToSFColor(HEngine::HColor color) {
    switch (color) {
    case HColor::Black:       return sf::Color::Black;
    case HColor::White:       return sf::Color::White;
    case HColor::Red:         return sf::Color::Red;
    case HColor::Green:       return sf::Color::Green;
    case HColor::Blue:        return sf::Color::Blue;
    case HColor::Yellow:      return sf::Color::Yellow;
    case HColor::Magenta:     return sf::Color::Magenta;
    case HColor::Cyan:        return sf::Color::Cyan;
    case HColor::Transparent: return sf::Color::Transparent;
    default:                  return sf::Color::Black; // fallback
    }
}

HEngine::HColor HEngine::FromSFColor(const sf::Color& color) {
    if (color == sf::Color::Black)       return HColor::Black;
    if (color == sf::Color::White)       return HColor::White;
    if (color == sf::Color::Red)         return HColor::Red;
    if (color == sf::Color::Green)       return HColor::Green;
    if (color == sf::Color::Blue)        return HColor::Blue;
    if (color == sf::Color::Yellow)      return HColor::Yellow;
    if (color == sf::Color::Magenta)     return HColor::Magenta;
    if (color == sf::Color::Cyan)        return HColor::Cyan;
    if (color == sf::Color::Transparent) return HColor::Transparent;

    // fallback if no exact match
    return HColor::Black;
}

void HEngine::SFSpriteRenderSystem::Render(sf::RenderWindow& window) {
    for (auto const& entity : m_Entities) {
        //auto& transform = g_Coordinator->GetComponent<TransformComponent>(entity);
        //auto& sprite = g_Coordinator->GetComponent<SpriteComponent>(entity);

        //sprite.sprite.setPosition(transform.position);
        //sprite.sprite.setRotation(transform.rotation);
        //sprite.sprite.setScale(transform.scale);

        //window.draw(sprite.sprite);
    }
}


void HEngine::RectangleRenderSystem::Render(sf::RenderWindow& window) {
    for (auto const& entity : m_Entities) {

        TransformComponent& transform = m_Coordinator.GetComponent<TransformComponent>(entity);
        RectangleComponent& rectangle = m_Coordinator.GetComponent<RectangleComponent>(entity);
        HVector2Df  position = transform.translation + rectangle.position;
        HVector2Df  size = rectangle.size * transform.scale;
        sf::RectangleShape rectangleShape = sf::RectangleShape({ size.x, size.y });
        rectangleShape.setPosition({ position.x, position.y });
        rectangleShape.setFillColor(ToSFColor(rectangle.color));

        window.draw(rectangleShape);
    }
}


void HEngine::TextRenderSystem::Render(sf::RenderWindow& window) {
    for (auto const& entity : m_Entities) {
        TransformComponent& transform = m_Coordinator.GetComponent<TransformComponent>(entity);
        TextComponent& textcomponent = m_Coordinator.GetComponent<TextComponent>(entity);
        HVector2Df  position = transform.translation + textcomponent.position;

        const sf::Font& font = *GetOrLoadFont("arial", textcomponent.fontPath);
        sf::Text text(font, textcomponent.text, textcomponent.character_size);
        text.setFillColor(ToSFColor(textcomponent.color));
        window.draw(text);
    }
}

bool HEngine::TextRenderSystem::LoadFont(const std::string& key, const std::string& filepath) {
    sf::Font font;
    if (!font.openFromFile(filepath)) {
        return false;
    }
    m_Fonts[key] = std::move(font);
    return true;
}

const sf::Font* HEngine::TextRenderSystem::GetFont(const std::string& key) const {
    auto it = m_Fonts.find(key);
    return it != m_Fonts.end() ? &it->second : nullptr;
}

const sf::Font* HEngine::TextRenderSystem::GetOrLoadFont(const std::string& key, const std::string& filepath) {
    if (auto* font = GetFont(key)) {
        return font;
    }
    return LoadFont(key, filepath) ? &m_Fonts[key] : nullptr;
}


