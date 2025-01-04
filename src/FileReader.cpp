#include "FileReader.h"

#include <cstdio>
#include "SentinelFileReader.h"
#include <filesystem>

namespace Sentinel
{
    FileReader::FileReader() = default;
    FileReader::~FileReader() = default;

    FileReader* FileReader::Create(const FileReaderType type)
    {
        switch (type)
        {
        case SENTINEL:
            printf("Sentinel file");
            return new SentinelFileReader();
        case JSON:
            printf("JSON file");
            break;
        case YAML:
            printf("YAML file");
            break;
        case TOML:
            printf("TOML file");
            break;
        }

        return nullptr;
    }

    std::string FileReader::GetCurrentDirectory()
    {
        std::filesystem::path cwd = std::filesystem::current_path();
        return cwd.string();
    }
}


