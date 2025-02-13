#pragma once

#include <memory>

#include "ConfigType.h"
#include "FileReader.h"

namespace ACM
{
    struct ConfigurationParameters
    {
        bool enableHotReload = true;
        bool validateOnLoad = true;
    };

    class ConfigurationManager
    {
    public:
        static ConfigurationManager* Get();
        static void Initialize(const std::string&, const ConfigurationParameters& params = ConfigurationParameters());

        ~ConfigurationManager();
        static void Destroy();

        [[nodiscard]] int GetConfigValue();

    private:
        ConfigurationManager(std::string, FileReaderType type, const ConfigurationParameters& params);

        static ConfigurationManager* m_Instance;
        std::unique_ptr<FileReader> m_Reader;

        std::string m_FilePath{};
        ConfigurationParameters m_Parameters;

        int m_ConfigValue{};
    };
}
