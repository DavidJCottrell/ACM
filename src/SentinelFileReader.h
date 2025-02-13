#pragma once

#include <vector>

#include "FileReader.h"

namespace ACM
{
    class SentinelFileReader final : public FileReader
    {
    public:
        SentinelFileReader();
        ~SentinelFileReader() override;
        int Read(std::string filePath) override;
        void ParseConfiguration(std::vector<std::string>& lines) override;
    };
}
