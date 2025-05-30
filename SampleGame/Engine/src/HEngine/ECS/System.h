#pragma once
#include <set>
#include "ECSTypes.hpp"
#include <SFML/Graphics.hpp>
#include "HEngine/Utils/Color.h"

namespace HEngine {

	// Forward declaration of Coordinator
    class Coordinator;

    sf::Color ToSFColor(HEngine::HColor color);

    HEngine::HColor FromSFColor(const sf::Color& color);

    class System {

    protected:
        Coordinator& m_Coordinator;

    public:
            
        System(Coordinator& coordinator) : m_Coordinator(coordinator) {}

        std::set<Entity> m_Entities;
        virtual ~System() = default;
    };

    class SFSpriteRenderSystem : public System {
    public:
        void Render(sf::RenderWindow& window);
    };

    class RectangleRenderSystem : public System {
    public:
        void Render(sf::RenderWindow& window);

    };

    class TextRenderSystem : public System {
    public:

        void Render(sf::RenderWindow& window);

    private:

        std::unordered_map<std::string, sf::Font> m_Fonts;

        // Loads a font from file and stores it with the given key
        // Returns true if loading succeeded, false otherwise
        bool LoadFont(const std::string& key, const std::string& filepath);

        // Returns a pointer to the loaded font for the given key,
        // or nullptr if not found
        const sf::Font* GetFont(const std::string& key) const;

        // Gets the font if loaded, otherwise tries to load it from the filepath and returns pointer
        // Returns nullptr if loading fails
        const sf::Font* GetOrLoadFont(const std::string& key, const std::string& filepath);

    };

    

}


