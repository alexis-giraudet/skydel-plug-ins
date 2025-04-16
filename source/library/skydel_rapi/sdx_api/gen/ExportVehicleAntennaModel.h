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
    /// Export a vehicle antenna model in a XML file.
    ///
    /// Name        Type   Description
    /// ----------- ------ -----------------------------------------------------
    /// AntennaName string Vehicle antenna model name
    /// FilePath    string The antenna model will be exported in this file path.
    /// Overwriting bool   Overwrite the old file if true.
    ///

    class ExportVehicleAntennaModel;
    typedef std::shared_ptr<ExportVehicleAntennaModel> ExportVehicleAntennaModelPtr;
    
    
    class ExportVehicleAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ExportVehicleAntennaModel";
      inline static const char* const Documentation = "Export a vehicle antenna model in a XML file.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -----------------------------------------------------\n"      "AntennaName string Vehicle antenna model name\n"      "FilePath    string The antenna model will be exported in this file path.\n"      "Overwriting bool   Overwrite the old file if true.";
      inline static const char* const TargetId = "";



          ExportVehicleAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          ExportVehicleAntennaModel(const std::string& antennaName, const std::string& filePath, bool overwriting)
            : CommandBase(CmdName, TargetId)
          {

            setAntennaName(antennaName);
            setFilePath(filePath);
            setOverwriting(overwriting);
          }


          static ExportVehicleAntennaModelPtr create(const std::string& antennaName, const std::string& filePath, bool overwriting)
          {
            return std::make_shared<ExportVehicleAntennaModel>(antennaName, filePath, overwriting);
          }

      static ExportVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ExportVehicleAntennaModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["AntennaName"])
                  && parse_json<std::string>::is_valid(m_values["FilePath"])
                  && parse_json<bool>::is_valid(m_values["Overwriting"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"AntennaName", "FilePath", "Overwriting"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string antennaName() const
          {
            return parse_json<std::string>::parse(m_values["AntennaName"]);
          }

          void setAntennaName(const std::string& antennaName)
          {
            m_values.AddMember("AntennaName", parse_json<std::string>::format(antennaName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string filePath() const
          {
            return parse_json<std::string>::parse(m_values["FilePath"]);
          }

          void setFilePath(const std::string& filePath)
          {
            m_values.AddMember("FilePath", parse_json<std::string>::format(filePath, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool overwriting() const
          {
            return parse_json<bool>::parse(m_values["Overwriting"]);
          }

          void setOverwriting(bool overwriting)
          {
            m_values.AddMember("Overwriting", parse_json<bool>::format(overwriting, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(ExportVehicleAntennaModel);
  }
}

