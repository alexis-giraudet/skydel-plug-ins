#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Import a space vehicle antenna model from a XML file.
    ///
    /// Name     Type   Description
    /// -------- ------ --------------------------------------------------------------------------
    /// FilePath string File path of the antenna model
    /// System   string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class ImportSVAntennaModel;
    typedef std::shared_ptr<ImportSVAntennaModel> ImportSVAntennaModelPtr;
    
    
    class ImportSVAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ImportSVAntennaModel";
      inline static const char* const Documentation = "Import a space vehicle antenna model from a XML file.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ --------------------------------------------------------------------------\n"      "FilePath string File path of the antenna model\n"      "System   string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
      inline static const char* const TargetId = "";



          ImportSVAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          ImportSVAntennaModel(const std::string& filePath, const std::string& system)
            : CommandBase(CmdName, TargetId)
          {

            setFilePath(filePath);
            setSystem(system);
          }


          static ImportSVAntennaModelPtr create(const std::string& filePath, const std::string& system)
          {
            return std::make_shared<ImportSVAntennaModel>(filePath, system);
          }

      static ImportSVAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ImportSVAntennaModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["FilePath"])
                  && parse_json<std::string>::is_valid(m_values["System"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"FilePath", "System"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string filePath() const
          {
            return parse_json<std::string>::parse(m_values["FilePath"]);
          }

          void setFilePath(const std::string& filePath)
          {
            m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ImportSVAntennaModel);
  }
}

