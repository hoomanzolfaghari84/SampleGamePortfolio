#pragma once

#include <functional>
#include <string>

class Button {
public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size,
        const std::string& text, std::function<void()> onClick);

    void Render(sf::RenderWindow& window);
    void Update(const sf::Vector2f& mousePos, bool isClicked);

private:
    sf::RectangleShape m_Shape;
    sf::Text m_Text;
    sf::Font m_Font;
    std::function<void()> m_OnClick;
    bool m_Hovered = false;
};
