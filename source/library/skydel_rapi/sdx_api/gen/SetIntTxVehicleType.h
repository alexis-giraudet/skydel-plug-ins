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
    /// Set interference vehicle type for Track Trajectory.
    ///
    /// Name Type   Description
    /// ---- ------ -----------------------------------------------------------
    /// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne").
    /// Id   string Transmitter unique identifier.
    ///

    class SetIntTxVehicleType;
    typedef std::shared_ptr<SetIntTxVehicleType> SetIntTxVehicleTypePtr;
    
    
    class SetIntTxVehicleType : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxVehicleType";
      inline static const char* const Documentation = "Set interference vehicle type for Track Trajectory.\n"      "\n"      "Name Type   Description\n"      "---- ------ -----------------------------------------------------------\n"      "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\").\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          SetIntTxVehicleType()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxVehicleType(const std::string& type, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setType(type);
            setId(id);
          }


          static SetIntTxVehicleTypePtr create(const std::string& type, const std::string& id)
          {
            return std::make_shared<SetIntTxVehicleType>(type, id);
          }

      static SetIntTxVehicleTypePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxVehicleType>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Type"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Type", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string type() const
          {
            return parse_json<std::string>::parse(m_values["Type"]);
          }

          void setType(const std::string& type)
          {
            m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetIntTxVehicleType);
  }
}

