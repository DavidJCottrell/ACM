#pragma once

#include <unordered_map>
#include <string>

namespace ACM
{
    enum FileReaderType
    {
        SENTINEL,
        JSON,
        YAML,
        TOML
    };

    const std::unordered_map<std::string, FileReaderType> fileTypeMap = {
        {"sen", SENTINEL},
        {"json", JSON},
        {"yaml", YAML},
        {"toml", TOML}
    };
}
