#include "ConfigurationManager.h"
#include <stdexcept>

#include "SentinelFileReader.h"

namespace Sentinel
{
    ConfigurationManager *ConfigurationManager::m_Instance = nullptr;

    ConfigurationManager *ConfigurationManager::Get()
    {
        if (!m_Instance)
        {
            throw std::runtime_error("ConfigurationManager not initialized");
        }
        return m_Instance;
    }

    void ConfigurationManager::Initialize(const char *filePath, const ConfigurationParameters &params)
    {
        if (m_Instance)
        {
            throw std::runtime_error("ConfigurationManager already initialized");
        }
        m_Instance = new ConfigurationManager(filePath, params);

        m_Instance->m_reader = std::unique_ptr<FileReader>(FileReader::Create(params.fileReaderType));

        m_Instance->m_ConfigValue = m_Instance->m_reader->Read(m_Instance->m_FilePath);
    }

    void ConfigurationManager::Destroy()
    {
        delete m_Instance;
        m_Instance = nullptr;
    }

    ConfigurationManager::ConfigurationManager(const char *filePath, const ConfigurationParameters &params)
        : m_FilePath(filePath), m_Parameters(params)
    {
    }

    ConfigurationManager::~ConfigurationManager()
    {
        if (this == m_Instance)
        {
            m_Instance = nullptr;
        }
    }
}
