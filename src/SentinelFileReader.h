#pragma once

#include "FileReader.h"

namespace Sentinel
{
    class SentinelFileReader final : public FileReader
    {
    public:
        SentinelFileReader();
        ~SentinelFileReader() override;
        int Read(std::string filePath) override;
    };
}
