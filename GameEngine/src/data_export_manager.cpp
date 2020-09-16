#include "pch.h"

#include "data_export_manager.h"


namespace Engine
{
	/* Json look like: 
	 * [
	 * {txt_path: "some_path" x: 23, y: 32},
	 * {txt_path: "some_path" x: 23, y: 32},
	 * {txt_path: "some_path" x: 23, y: 32},
	 * {txt_path: "some_path" x: 23, y: 32},
	 * ]
	 */
	void DataExportManager::export_grid_data(const std::vector<Cell>& cells)
	{
		auto json = nlohmann::json::array();
		for (const auto& cell : cells)
		{
			json.push_back({{ "txt_path", cell.get_texture_filepath() }, { "x", cell.get_coord().x }, { "y", cell.get_coord().y }});
		}

		std::ofstream o_stream("grid.json");
		o_stream << json << std::endl;
		std::cout << json << '\n';
	}

	
}

