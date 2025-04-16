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
    /// Set the default vehicle antenna model.
    ///
    /// Name Type   Description
    /// ---- ------ ---------------------------
    /// Name string Default antenna model name.
    ///

    class SetDefaultVehicleAntennaModel;
    typedef std::shared_ptr<SetDefaultVehicleAntennaModel> SetDefaultVehicleAntennaModelPtr;
    
    
    class SetDefaultVehicleAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetDefaultVehicleAntennaModel";
      inline static const char* const Documentation = "Set the default vehicle antenna model.\n"      "\n"      "Name Type   Description\n"      "---- ------ ---------------------------\n"      "Name string Default antenna model name.";
      inline static const char* const TargetId = "";



          SetDefaultVehicleAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          SetDefaultVehicleAntennaModel(const std::string& name)
            : CommandBase(CmdName, TargetId)
          {

            setName(name);
          }


          static SetDefaultVehicleAntennaModelPtr create(const std::string& name)
          {
            return std::make_shared<SetDefaultVehicleAntennaModel>(name);
          }

      static SetDefaultVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetDefaultVehicleAntennaModel>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Name"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Name"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(SetDefaultVehicleAntennaModel);
  }
}

