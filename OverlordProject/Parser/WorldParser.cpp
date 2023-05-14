#include "stdafx.h"
#include "WorldParser.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<WorldParser::ModelData> WorldParser::RoadLoader(const std::wstring& path) const
{
    std::vector<ModelData> models{};
    std::wifstream input{ path };
    if (input.is_open())
    {
        std::wstring line;
        while (std::getline(input, line))
        {
            ModelData model;
            std::wstringstream ss(line);

            // Extract name
            std::wstring name;
            std::getline(ss, name, L':');
            model.name = name;

            // Extract position
            std::wstring cache;
            std::wstring x_str, y_str, z_str;

            std::getline(ss, cache, L':');
            std::getline(ss, x_str, L' ');
            std::getline(ss, cache, L':');
            std::getline(ss, y_str, L' ');
            std::getline(ss, cache, L':');
            std::getline(ss, z_str, L' ');
            model.x = std::stof(x_str);
            model.y = std::stof(y_str);
            model.z = std::stof(z_str);

            // Extract rotation
            std::wstring rotation;
            std::getline(ss, rotation, L':');
            std::getline(ss, rotation, L' ');
            model.rotation = std::stof(rotation);

            models.push_back(model);
        }
    }
    else
    {
        Logger::LogWarning(L"No file found for roads.", path);
    }
    return models;
}

std::vector<WorldParser::ModelData> WorldParser::HouseLoader(const std::wstring& path) const
{
    std::vector<ModelData> models{};
    std::wifstream input{ path };
    if (input.is_open())
    {
        std::wstring line;
        while (std::getline(input, line))
        {
            ModelData model;
            std::wstringstream ss(line);

            // Extract name
            std::wstring name;
            std::getline(ss, name, L':');
            model.name = name;

            // Extract position
            std::wstring cache;
            std::wstring x_str, y_str, z_str;

            std::getline(ss, cache, L':');
            std::getline(ss, x_str, L' ');
            std::getline(ss, cache, L':');
            std::getline(ss, y_str, L' ');
            std::getline(ss, cache, L':');
            std::getline(ss, z_str, L' ');
            model.x = std::stof(x_str);
            model.y = std::stof(y_str);
            model.z = std::stof(z_str);

            // Extract rotation
            std::wstring rotation;
            std::getline(ss, rotation, L':');
            std::getline(ss, rotation, L' ');
            model.rotation = std::stof(rotation);

            models.push_back(model);
        }
    }
    else
    {
        Logger::LogWarning(L"No file found for houses.", path);
    }
    return models;
}

std::vector<WorldParser::ModelData> WorldParser::ItemSpawnLoader(const std::wstring& path) const
{
    std::vector<ModelData> models{};
    std::wifstream input{ path };
    if (input.is_open())
    {
        std::wstring line;
        while (std::getline(input, line))
        {
            ModelData model;
            std::wstringstream ss(line);

            // Extract name
            std::wstring name;
            std::getline(ss, name, L':');
            model.name = name;

            // Extract position
            std::wstring cache;
            std::wstring x_str, y_str, z_str;

            std::getline(ss, cache, L':');
            std::getline(ss, x_str, L' ');
            std::getline(ss, cache, L':');
            std::getline(ss, y_str, L' ');
            std::getline(ss, cache, L':');
            std::getline(ss, z_str, L' ');
            model.x = std::stof(x_str);
            model.y = std::stof(y_str);
            model.z = std::stof(z_str);

            models.push_back(model);
        }
    }
    else
    {
        Logger::LogWarning(L"No file found for houses.", path);
    }
    return models;
}
