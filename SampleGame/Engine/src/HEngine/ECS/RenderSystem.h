#pragma once
#include "System.h"

#include "EntityManager.h"
#include <SFML/Graphics.hpp>
#include "ComponentRegistry.h"
#include "../Utils/Color.h"

namespace HEngine {

    class RenderSystem : public System {
    public:
        RenderSystem(sf::RenderWindow& window) : m_Window(window) {}

        void Update(EntityManager& entityManager, ComponentRegistry& componentRegistry, float dt) override {
            m_Window.clear();

            RenderUIComponents(entityManager, componentRegistry, dt);

            

                /*for (auto& [id, entity] : entityManager.GetAllEntities()) {
                    if (entity->HasComponent<TransformComponent>() && entity->HasComponent<UIComponent>()) {
                        const auto& transform = entity->GetComponent<TransformComponent>();
                        auto& ui = entity->GetComponent<UIComponent>();

                        ui.shape.setPosition(transform.position);
                        ui.text.setPosition(transform.position);

                        m_Window.draw(ui.shape);
                        m_Window.draw(ui.text);
                    }
                }*/

                m_Window.display();
        }

    private:
        sf::RenderWindow& m_Window;
        std::unordered_map<std::string, sf::Font> m_fonts;



        inline sf::Color ToSFColor(HColor color) {
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
            default:                 return sf::Color::White; // Fallback
            }
        }

        inline HColor FromSFColor(const sf::Color& sfColor) {
            if (sfColor == sf::Color::Black)       return HColor::Black;
            if (sfColor == sf::Color::White)       return HColor::White;
            if (sfColor == sf::Color::Red)         return HColor::Red;
            if (sfColor == sf::Color::Green)       return HColor::Green;
            if (sfColor == sf::Color::Blue)        return HColor::Blue;
            if (sfColor == sf::Color::Yellow)      return HColor::Yellow;
            if (sfColor == sf::Color::Magenta)     return HColor::Magenta;
            if (sfColor == sf::Color::Cyan)        return HColor::Cyan;
            if (sfColor == sf::Color::Transparent) return HColor::Transparent;
            return HColor::White; // Fallback
        }

        // Load font by name and path (if not already loaded)
        void LoadFont(const std::string& name, const std::string& filepath) {

            if (m_fonts.find(name) == m_fonts.end()) {
                sf::Font font;
                if (!font.openFromFile(filepath)) {
                    throw std::runtime_error("Failed to load font from: " + filepath);
                }
                m_fonts[name] = std::move(font);
            }
        }

        // Get a font by name; throws if not found
        const sf::Font& GetFont(const std::string& name) const {
            auto it = m_fonts.find(name);
            if (it == m_fonts.end()) {
                throw std::runtime_error("Font not found: " + name);
            }
            return it->second;
        }

        const sf::Font& GetFont(const std::string& name, const std::string& filepath) {
            LoadFont(name, filepath);
            return GetFont(name);
        }

        void RenderUIComponents(EntityManager& entityManager, ComponentRegistry& componentRegistry, float dt) {
            entityManager.ForEach([&](const UUID& id, Entity& entity) {
                //if (componentRegistry.Has<TransformComponent>(id) && componentRegistry.Has<UIComponent>(id))
                if (componentRegistry.Has<UIComponent>(id))
                {


                    //auto& transform = *componentRegistry.Get<TransformComponent>(id);
                    auto& ui = *componentRegistry.Get<UIComponent>(id);

                    sf::RectangleShape shape = sf::RectangleShape({ ui.width, ui.height });
                    shape.setPosition({ ui.x,ui.y });
                    shape.setFillColor(ToSFColor(ui.color));

                    const sf::Font& font = GetFont("UICompFont", ui.font_path);
                    const sf::Text& text = sf::Text(font, ui.text);

                    m_Window.draw(shape);
                    m_Window.draw(text);
                }

                });
        }

    };

}

