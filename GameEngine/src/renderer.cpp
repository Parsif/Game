#include "renderer.h"

#include "imgui-SFML.h"
#include "imgui.h"

#include "SFML/Window/Mouse.hpp"

namespace Engine
{
    Renderer::Renderer(const std::shared_ptr<sf::RenderWindow>& render_window,
        const std::shared_ptr<CustomCursor>& custom_cursor, const std::shared_ptr<Grid>& grid, std::shared_ptr<ResourceManager> resource_manager) :
        render_window_(render_window), custom_cursor_(custom_cursor), grid_(grid), resource_manager_(resource_manager)
    {
    }

	void Renderer::render_imgui() const
	{
        bool my_tool_active;
        ImGui::Begin("Editing tool", &my_tool_active);

        ImGui::TextColored(ImVec4(1, 1, 1, 1), "Mouse position:");
        ImGui::SameLine();
        const auto [mouse_pos_x, mouse_pos_y] = render_window_->mapPixelToCoords(sf::Mouse::getPosition(*render_window_));
        ImGui::TextColored(ImVec4(1, 1, 1, 1), "(%.0f ,%.0f)", mouse_pos_x, mouse_pos_y);


        for (const auto& tile_sprite : resource_manager_->get_sprite_wrappers())
        {
            ImGui::BeginChild("Tiles");
            if (ImGui::ImageButton(tile_sprite.get_sprite()))
            {
                custom_cursor_->attach_sprite(tile_sprite);
            }

            // ImGui::SameLine();
            ImGui::EndChild();
        }

        ImGui::End();

        ImGui::SFML::Render(*render_window_);
	}

	void Renderer::render_other() const
	{
        grid_->split();
        grid_->draw_cells();
        custom_cursor_->draw(*render_window_);
	}

	
	void Renderer::render() const
	{
        render_window_->clear(sf::Color(39, 39, 39));
        render_other();
        render_imgui();
        render_window_->display();
	}
}
