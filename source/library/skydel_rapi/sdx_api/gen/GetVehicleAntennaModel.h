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
    /// Get  all infos about this antenna model.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Name string Vehicle antenna model name
    ///

    class GetVehicleAntennaModel;
    typedef std::shared_ptr<GetVehicleAntennaModel> GetVehicleAntennaModelPtr;
    
    
    class GetVehicleAntennaModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetVehicleAntennaModel";
      inline static const char* const Documentation = "Get  all infos about this antenna model.\n"      "\n"      "Name Type   Description\n"      "---- ------ --------------------------\n"      "Name string Vehicle antenna model name";
      inline static const char* const TargetId = "";



          GetVehicleAntennaModel()
            : CommandBase(CmdName, TargetId)
          {}

          GetVehicleAntennaModel(const std::string& name)
            : CommandBase(CmdName, TargetId)
          {

            setName(name);
          }


          static GetVehicleAntennaModelPtr create(const std::string& name)
          {
            return std::make_shared<GetVehicleAntennaModel>(name);
          }

      static GetVehicleAntennaModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetVehicleAntennaModel>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetVehicleAntennaModel);
  }
}

