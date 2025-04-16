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
    /// Copy a vehicle antenna model.
    ///
    /// Name     Type   Description
    /// -------- ------ ------------------------------------
    /// Name     string Reference vehicle antenna model name
    /// CopyName string Copy vehicle antenna model name
    ///

    class CopyVehicleAntennaModel;
    typedef std::shared_ptr<CopyVehicleAntennaModel> CopyVehicleAntennaModelPtr;
    
    
    class CopyVehicleAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "CopyVehicleAntennaModel";
      inline static const char* const Documentation = "Copy a vehicle antenna model.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ ------------------------------------\n"      "Name     string Reference vehicle antenna model name\n"      "CopyName string Copy vehicle antenna model name";
      inline static const char* const TargetId = "";



          CopyVehicleAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          CopyVehicleAntennaModel(const std::string& name, const std::string& copyName)
            : CommandBase(CmdName, TargetId)
          {

            setName(name);
            setCopyName(copyName);
          }


          static CopyVehicleAntennaModelPtr create(const std::string& name, const std::string& copyName)
          {
            return std::make_shared<CopyVehicleAntennaModel>(name, copyName);
          }

      static CopyVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<CopyVehicleAntennaModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Name"])
                  && parse_json<std::string>::is_valid(m_values["CopyName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Name", "CopyName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string name() const
          {
            return parse_json<std::string>::parse(m_values["Name"]);
          }

          void setName(const std::string& name)
          {
            m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string copyName() const
          {
            return parse_json<std::string>::parse(m_values["CopyName"]);
          }

          void setCopyName(const std::string& copyName)
          {
            m_values.AddMember("CopyName", parse_json<std::string>::format(copyName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(CopyVehicleAntennaModel);
  }
}

