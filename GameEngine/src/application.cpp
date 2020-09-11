#include "pch.h"

#include "application.h"

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
            renderer_.render();
        }
    }


    Application::~Application()
    {
        ImGui::SFML::Shutdown();
    }
}
