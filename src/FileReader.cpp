#include "FileReader.h"

#include "SentinelFileReader.h"
#include <filesystem>
#include <iostream>

namespace ACM
{
    FileReader::FileReader() = default;
    FileReader::~FileReader() = default;

    FileReader *FileReader::Create(const FileReaderType type)
    {
        switch (type)
        {
        case SENTINEL:
            return new SentinelFileReader();
        case JSON:
        case YAML:
        case TOML:
            break;
        }

        std::cerr << "FileReader::Create: Unknown FileReaderType" << std::endl;

        return nullptr;
    }

    std::string FileReader::GetCurrentDirectory()
    {
        const std::filesystem::path cwd = std::filesystem::current_path();
        return cwd.string();
    }
}
