//
// Created by Владислав on 28.08.2020.
//

#include "pch.h"
#include "application.h"

#include "imgui.h"
#include "imgui-SFML.h"

#include "event_handler.h"

namespace Engine
{
    Application::Application()
    {
        render_window_->setFramerateLimit(60);
        ImGui::SFML::Init(*render_window_);
        render_window_->setView(view_);
    }

    void Application::Run()
    {
        sf::Clock delta_clock;
        while (render_window_->isOpen())
        {
            sf::Event event;
            while (render_window_->pollEvent(event))
            {
                event_handler_.on_event(event);
            }

            ImGui::SFML::Update(*render_window_, delta_clock.restart());

            // draw stuff
            render_window_->clear(sf::Color(39, 39, 39));

            grid_.split();
            grid_.draw_cells();
            DrawTextureTools();
            custom_cursor.draw(*render_window_);

            ImGui::SFML::Render(*render_window_);
            render_window_->display();
        }
    }


    void Application::DrawTextureTools()
    {
        bool my_tool_active;
        ImGui::Begin("Editing tool", &my_tool_active);

        ImGui::TextColored(ImVec4(1,1,1, 1), "Mouse position:");
        ImGui::SameLine();
        const auto [mouse_pos_x, mouse_pos_y] = render_window_->mapPixelToCoords(sf::Mouse::getPosition(*render_window_));
        ImGui::TextColored(ImVec4(1,1,1, 1), "(%.0f ,%.0f)", mouse_pos_x, mouse_pos_y);


        for (const auto &tile_sprite : resource_manager_.get_sprites())
        {
            ImGui::BeginChild("Tiles");
            if (ImGui::ImageButton(tile_sprite))
            {
                custom_cursor.attach_sprite(tile_sprite);
            }

            // ImGui::SameLine();
            ImGui::EndChild();
        }

        ImGui::End();
    }


    Application::~Application()
    {
        ImGui::SFML::Shutdown();
    }
}
