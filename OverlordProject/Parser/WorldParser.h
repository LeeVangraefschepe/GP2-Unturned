#pragma once
#include <string>
#include <vector>

class WorldParser
{
public:
    struct ModelData
    {
        std::wstring name;
        float x{};
        float y{};
        float z{};
        float rotation{};
    };

	std::vector<ModelData> RoadLoader(const std::wstring& path) const;
	std::vector<ModelData> HouseLoader(const std::wstring& path) const;
	std::vector<ModelData> ItemSpawnLoader(const std::wstring& path) const;
private:
};
