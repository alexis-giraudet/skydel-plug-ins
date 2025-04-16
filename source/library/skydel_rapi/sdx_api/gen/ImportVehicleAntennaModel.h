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
    /// Import a vehicle antenna model from a XML file.
    ///
    /// Name     Type   Description
    /// -------- ------ ------------------------------
    /// FilePath string File path of the antenna model
    ///

    class ImportVehicleAntennaModel;
    typedef std::shared_ptr<ImportVehicleAntennaModel> ImportVehicleAntennaModelPtr;
    
    
    class ImportVehicleAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ImportVehicleAntennaModel";
      inline static const char* const Documentation = "Import a vehicle antenna model from a XML file.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ ------------------------------\n"      "FilePath string File path of the antenna model";
      inline static const char* const TargetId = "";



          ImportVehicleAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          ImportVehicleAntennaModel(const std::string& filePath)
            : CommandBase(CmdName, TargetId)
          {

            setFilePath(filePath);
          }


          static ImportVehicleAntennaModelPtr create(const std::string& filePath)
          {
            return std::make_shared<ImportVehicleAntennaModel>(filePath);
          }

      static ImportVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ImportVehicleAntennaModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["FilePath"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"FilePath"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(ImportVehicleAntennaModel);
  }
}

