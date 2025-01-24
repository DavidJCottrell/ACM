#include "ConfigurationManager.h"

#include <iostream>
#include <ostream>
#include "ConfigType.h"

#include "SentinelFileReader.h"

namespace ACM
{
    ConfigurationManager* ConfigurationManager::m_Instance = nullptr;

    ConfigurationManager* ConfigurationManager::Get()
    {
        if (!m_Instance)
        {
            std::cerr << "Error: ConfigurationManager not initialized" << std::endl;
        }
        return m_Instance;
    }

    void ConfigurationManager::Initialize(const std::string& filePath, const ConfigurationParameters& params)
    {
        if (m_Instance)
        {
            std::cerr << "Error: The ConfigurationManager has already been initialized" << std::endl;
            return;
        }

        const std::string fileExtension = filePath.substr(
            filePath.find('.') + 1,
            filePath.length() - filePath.find('.')
        );

        if (!fileTypeMap.contains(fileExtension))
        {
            std::cerr << "'" << fileExtension << "' file extension is not supported." << std::endl;
            return;
        }

        const FileReaderType type = fileTypeMap.at(fileExtension);

        m_Instance = new ConfigurationManager(filePath, type, params);
    }

    int ConfigurationManager::GetConfigValue()
    {
        if (!m_Instance)
            return -1;

        return m_Instance->m_Reader->Read(m_Instance->m_FilePath);
    }

    ConfigurationManager::ConfigurationManager(std::string filePath, const FileReaderType type,
                                               const ConfigurationParameters& params)
        : m_Reader(std::unique_ptr<FileReader>(FileReader::Create(type))),
          m_FilePath(std::move(filePath)),
          m_Parameters(params)
    {
    }
}
