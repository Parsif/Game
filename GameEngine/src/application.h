//
// Created by Владислав on 28.08.2020.
//

#ifndef MAPEDITOR_APPLICATION_H
#define MAPEDITOR_APPLICATION_H

#include "pch.h"

#include "resource_manager.h"
#include "custom_cursor.h"
#include "event_handler.h"
#include "grid.h"

namespace Engine
{
    class Application
    {
    private:
        std::shared_ptr<sf::RenderWindow> render_window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(768, 512), "MapEditor");
        sf::View view_{sf::Vector2f(render_window_->getSize().x / 2.f, render_window_->getSize().y / 2.f),
                       sf::Vector2f(render_window_->getSize().x, render_window_->getSize().y)};
        ResourceManager resource_manager_;
        CustomCursor custom_cursor;
        Grid grid_{render_window_, resource_manager_.get_tile_size()};
        Camera camera_{render_window_};
        EventHandler event_handler_{ render_window_ , custom_cursor, grid_, camera_};

    private:
        void DrawTextureTools();

    public:
        Application();
        ~Application();
        Application(const Application &other) = delete;
        Application& operator=(Application &other) = delete;

        void Run();
        void OnEvent();

    };
}


#endif //MAPEDITOR_APPLICATION_H
