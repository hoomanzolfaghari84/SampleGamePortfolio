#pragma once
#include "RenderAPI.h"
#include <SFML/Graphics.hpp>

namespace HEngine {

    class SFMLRenderAPI : public HRenderAPI {
    public:
        SFMLRenderAPI(sf::RenderWindow& win) : m_Window(win) {}

        void BeginFrame() override {}
        void EndFrame() override {}
        void Present() override { m_Window.display(); }

        void Clear(HColor color) override {
            m_Window.clear(ConvertColor(color));
        }

        void DrawHRect(const RectangleComponent& rect) override {
            sf::RectangleShape shape;
            shape.setPosition({ rect.position.x, rect.position.y });
            shape.setSize({rect.size.x, rect.size.y});
            shape.setFillColor(ConvertColor(rect.color));
            m_Window.draw(shape);
        }

        void DrawHText(const TextComponent& txt) override {
            sf::Text text(m_Font);
            text.setPosition({ txt.position.x, txt.position.y });
            text.setCharacterSize(txt.character_size);
            text.setFillColor(ConvertColor(txt.color));
            m_Window.draw(text);
        }

    private:
        sf::RenderWindow& m_Window;
        sf::Font m_Font = sf::Font("arial.ttf");

        sf::Color ConvertColor(HColor color) {
            switch (color) {
            case HColor::Red:    return sf::Color::Red;
            case HColor::Green:  return sf::Color::Green;
            case HColor::Blue:   return sf::Color::Blue;
            case HColor::White:  return sf::Color::White;
            case HColor::Black:  return sf::Color::Black;
            default:             return sf::Color::Magenta;
            }
        }
    };

}
