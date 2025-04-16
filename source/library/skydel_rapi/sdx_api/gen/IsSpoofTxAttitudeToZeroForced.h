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
    /// Get whether the spoofer transmitter vehicle yaw, pitch and roll should be forced to zero.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class IsSpoofTxAttitudeToZeroForced;
    typedef std::shared_ptr<IsSpoofTxAttitudeToZeroForced> IsSpoofTxAttitudeToZeroForcedPtr;
    
    
    class IsSpoofTxAttitudeToZeroForced : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSpoofTxAttitudeToZeroForced";
      inline static const char* const Documentation = "Get whether the spoofer transmitter vehicle yaw, pitch and roll should be forced to zero.\n"      "\n"      "Name Type   Description\n"      "---- ------ ------------------------------\n"      "Id   string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          IsSpoofTxAttitudeToZeroForced()
            : CommandBase(CmdName, TargetId)
          {}

          IsSpoofTxAttitudeToZeroForced(const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setId(id);
          }


          static IsSpoofTxAttitudeToZeroForcedPtr create(const std::string& id)
          {
            return std::make_shared<IsSpoofTxAttitudeToZeroForced>(id);
          }

      static IsSpoofTxAttitudeToZeroForcedPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSpoofTxAttitudeToZeroForced>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(IsSpoofTxAttitudeToZeroForced);
  }
}

