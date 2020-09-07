//
// Created by Vlad on 8/28/2020.
//

#ifndef MAPEDITOR_CELL_H
#define MAPEDITOR_CELL_H

#include <SFML/Graphics.hpp>

namespace Engine
{
    class Cell
    {
    private:
        sf::Sprite attached_sprite;
        int x_, y_;
        unsigned int size_;

    public:
        Cell(int x, int y, unsigned int size, const sf::Sprite &sprite = sf::Sprite{}) noexcept;

        void draw(std::shared_ptr<sf::RenderWindow> &renderWindow);

        void attach_sprite(const sf::Sprite &sprite);

        void detach_sprite();

        bool is_mouse_over(const std::shared_ptr<sf::RenderWindow> &render_window) const;
    };
}

#endif //MAPEDITOR_CELL_H
