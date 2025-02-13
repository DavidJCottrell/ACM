#pragma once

#include <string>
#include <vector>

#include "ConfigType.h"

namespace ACM
{
  class FileReader
  {
  public:
    FileReader();
    virtual ~FileReader();

    static FileReader* Create(FileReaderType type);

    static std::string GetCurrentDirectory();

    virtual int Read(std::string filePath) = 0;

    // Maybe this needs to be templated?
    virtual void ParseConfiguration(std::vector<std::string>& lines) = 0;
  };
}
