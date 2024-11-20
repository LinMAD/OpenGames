#pragma once
#include <filesystem>
#include <string>
#include <unordered_map>

#include "raylib.h"

namespace OpenGameCore
{
    /***
     * @class TextureManager
     * @brief Handles loading and usage of existing textures.
     */
    class TextureManager
    {
    public:
        TextureManager();
        ~TextureManager();
        /**
         * Load texture to
         * @param id key for texture aka tag. Example: Player
         * @param path to texture
         */
        void AddNewTexture(const std::string& id, const std::string& path);
        /**
         * Get a reference to a texture by its identifier.
         * @param id key of texture aka tag
         * @return Texture2D
         */
        Texture2D& GetTexture(const std::string& id);

    private:
        std::unordered_map<std::string, Texture2D> m_Textures;
    };
} // OpenGameCore
