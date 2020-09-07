//
// Created by Vlad on 8/28/2020.
//

#ifndef MAPEDITOR_CUSTOM_CURSOR_H
#define MAPEDITOR_CUSTOM_CURSOR_H

#include <SFML/Graphics.hpp>

namespace Engine
{
    class CustomCursor
    {
    private:
        sf::Sprite attached_sprite_;

    public:
        void draw(sf::RenderWindow &render_window);

        void attach_sprite(const sf::Sprite &sprite);
        void detach_sprite();
        const sf::Sprite &get_attached_sprite() const;
        inline bool is_sprite_attached() const;
    };

    inline bool CustomCursor::is_sprite_attached() const
    {
        return attached_sprite_.getTexture() != nullptr;
    }
}
#endif //MAPEDITOR_CUSTOM_CURSOR_H
