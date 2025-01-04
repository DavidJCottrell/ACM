#pragma once

#include <string>

#include "FileReaderTypes.h"

namespace Sentinel
{
  class FileReader
  {
  public:
    FileReader();
    virtual ~FileReader();

    static FileReader* Create(FileReaderType type);

    static std::string GetCurrentDirectory();

    virtual int Read(std::string filePath) = 0;
  };
}
