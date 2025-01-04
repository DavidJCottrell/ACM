#include "SentinelFileReader.h"
#include <filesystem>
#include "FileReader.h"

#include <fstream>

namespace Sentinel
{
    SentinelFileReader::SentinelFileReader() = default;

    SentinelFileReader::~SentinelFileReader() = default;

    int SentinelFileReader::Read(std::string filePath)
    {
        std::ifstream f(GetCurrentDirectory() + "/" + filePath);
        if (!f.is_open())
        {
            printf("--------> Failed to open file\n");
            return 1;
        }

        printf("--------> Opened file!!!\n");
        return 1;
    }
}
