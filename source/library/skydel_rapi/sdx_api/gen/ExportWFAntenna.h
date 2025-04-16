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
    /// Export Wavefront Antenna settings to an XML file.
    ///
    /// Name          Type   Description
    /// ------------- ------ -------------------------------------------------
    /// FilePath      string Export file path for Wavefront Antenna settings.
    /// OverwriteFile bool   When selected, existing file will be overwritten.
    ///

    class ExportWFAntenna;
    typedef std::shared_ptr<ExportWFAntenna> ExportWFAntennaPtr;
    
    
    class ExportWFAntenna : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ExportWFAntenna";
      inline static const char* const Documentation = "Export Wavefront Antenna settings to an XML file.\n"      "\n"      "Name          Type   Description\n"      "------------- ------ -------------------------------------------------\n"      "FilePath      string Export file path for Wavefront Antenna settings.\n"      "OverwriteFile bool   When selected, existing file will be overwritten.";
      inline static const char* const TargetId = "";



          ExportWFAntenna()
            : CommandBase(CmdName, TargetId)
          {}

          ExportWFAntenna(const std::string& filePath, bool overwriteFile)
            : CommandBase(CmdName, TargetId)
          {

            setFilePath(filePath);
            setOverwriteFile(overwriteFile);
          }


          static ExportWFAntennaPtr create(const std::string& filePath, bool overwriteFile)
          {
            return std::make_shared<ExportWFAntenna>(filePath, overwriteFile);
          }

      static ExportWFAntennaPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ExportWFAntenna>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["FilePath"])
                  && parse_json<bool>::is_valid(m_values["OverwriteFile"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"FilePath", "OverwriteFile"}; 
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



          bool overwriteFile() const
          {
            return parse_json<bool>::parse(m_values["OverwriteFile"]);
          }

          void setOverwriteFile(bool overwriteFile)
          {
            m_values.AddMember("OverwriteFile", parse_json<bool>::format(overwriteFile, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ExportWFAntenna);
  }
}

