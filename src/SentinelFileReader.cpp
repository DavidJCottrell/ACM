#include "SentinelFileReader.h"
#include "FileReader.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace ACM
{
    SentinelFileReader::SentinelFileReader() = default;

    SentinelFileReader::~SentinelFileReader() = default;

    int SentinelFileReader::Read(const std::string filePath)
    {
        const std::string fullFilePath = GetCurrentDirectory() + "/" + filePath;

        std::ifstream t(fullFilePath);
        if (!t.good())
        {
            std::cerr << "SentinelFileReader::Read: Failed to open configuration file: " << fullFilePath << std::endl;
        }

        std::stringstream buffer;
        buffer << t.rdbuf();

        std::string line;
        std::vector<std::string> lines;

        while (std::getline(buffer, line))
            lines.push_back(line);

        ParseConfiguration(lines);

        return 1;
    }

    void SentinelFileReader::ParseConfiguration(std::vector<std::string>& lines)
    {
        for (const auto& line : lines)
        {
            const std::string configProperty = line.substr(
                0,
                line.find('=')
            );
            const std::string configValue = line.substr(
                line.find('=') + 1,
                line.length() - line.find('=')
            );
            std::cout << configProperty << "-----" << configValue << std::endl;
        }
    }
}
