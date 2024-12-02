#include "TextureManager.h"

#include <iostream>
#include <ranges>

namespace OpenGameCore
{
    TextureManager::TextureManager()
    {
        m_Textures = {};
    }

    TextureManager::~TextureManager()
    {
        for (const auto& texture : m_Textures | std::views::values) {
            UnloadTexture(texture);
        }

        m_Textures.clear();
    }

    void TextureManager::AddNewTexture(const std::string& id, const std::string& path)
    {
        if (!std::filesystem::exists(path))
        {
            std::cerr << "Texture doesn't exist: " << path << std::endl;
            return;
        }
        if (m_Textures.contains(id)) {
            return;
        }

        if (const Texture2D texture = LoadTexture(path.c_str()); texture.id != 0) {
            m_Textures[id] = texture;
        } else {
            std::cerr << "Failed to load texture: " << path << std::endl;
        }
    }

    Texture2D& TextureManager::GetTexture(const std::string& id)
    {
        if (m_Textures.contains(id)) {
            return m_Textures[id];
        }

        std::cerr << "Texture with id '" << id << "' not found." << std::endl;

        static Texture2D emptyTexture = { 0 }; // TODO Add empty texture later.

        return emptyTexture;
    }
} // OpenGameCore
