#include "pch.h"

#include "sprite_wrapper.h"

namespace Engine
{
	SpriteWrapper::SpriteWrapper(const sf::Sprite& sprite, const std::string& texture_filepath) noexcept : sprite_(sprite), texture_filepath_(texture_filepath)
	{
	}
}
