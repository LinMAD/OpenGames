#include "Entity.h"

namespace OpenGameCore
{
    Entity::Entity(const std::string& tagName, const std::string& uuid)
    {
        SetTag(tagName);
        m_UUID = uuid;
    }

    void Entity::SetTag(const std::string& tagName)
    {
        m_Tag = tagName.empty() ? "NOT_GIVEN_TAG" : tagName;
    }
}
