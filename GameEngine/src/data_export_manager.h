#pragma once
#include "cell.h"

namespace Engine
{
	class DataExportManager
	{
	public:
		static void export_grid_data(const std::vector<Cell> &cells);
	};
}


