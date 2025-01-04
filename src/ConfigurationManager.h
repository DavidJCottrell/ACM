#pragma once

#include <functional>
#include "FileReader.h"
#include "FileReaderTypes.h"

namespace Sentinel
{
    struct ConfigurationParameters
    {
        bool enableHotReload = true;
        bool validateOnLoad = true;
        FileReaderType fileReaderType = SENTINEL;
    };

    class ConfigurationManager
    {
    public:
        // Initialising and getting
        static ConfigurationManager *Get();
        static void Initialize(const char *filePath, const ConfigurationParameters &params = ConfigurationParameters());

        // Destruction
        ~ConfigurationManager();
        static void Destroy();

        int GetConfigValue() const { return m_ConfigValue; }

    private:
        // Methods
        ConfigurationManager(const char *filePath, const ConfigurationParameters &params);

        // Properties
        static ConfigurationManager *m_Instance;
        std::unique_ptr<FileReader> m_reader;

        const char *m_FilePath;
        ConfigurationParameters m_Parameters;

        int m_ConfigValue;
    };
}
