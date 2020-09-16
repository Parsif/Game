#pragma once
#include "pch.h"

#include "SFML/Graphics/Sprite.hpp"

namespace Engine
{
	class SpriteWrapper
	{
	private:
		sf::Sprite sprite_;
		std::string texture_filepath_;
		
	public:
		SpriteWrapper() = default;
		SpriteWrapper(const sf::Sprite &sprite, const std::string &texture_filepath) noexcept;
		[[nodiscard]] inline std::string get_texture_filepath() const noexcept { return texture_filepath_; }
		[[nodiscard]] inline sf::Sprite get_sprite() const noexcept { return sprite_; }
	};
}

