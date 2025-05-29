#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <memory>
#include <mutex>
#include <stdexcept>

namespace HEngine {

    class FontManager {
    public:
        static FontManager& GetInstance() {
            static FontManager instance;
            return instance;
        }

        // Delete copy/move constructors and assignment operators
        FontManager(const FontManager&) = delete;
        FontManager& operator=(const FontManager&) = delete;
        FontManager(FontManager&&) = delete;
        FontManager& operator=(FontManager&&) = delete;

        // Load font by name and path (if not already loaded)
        void LoadFont(const std::string& name, const std::string& filepath) {
            std::lock_guard<std::mutex> lock(m_mutex);

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

    private:
        FontManager() = default;
        ~FontManager() = default;

        mutable std::mutex m_mutex;
        std::unordered_map<std::string, sf::Font> m_fonts;
    };
}
