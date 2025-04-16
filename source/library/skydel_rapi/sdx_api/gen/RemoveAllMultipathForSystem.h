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
    /// Disable all multipath for the specified constellation.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)
    ///

    class RemoveAllMultipathForSystem;
    typedef std::shared_ptr<RemoveAllMultipathForSystem> RemoveAllMultipathForSystemPtr;
    
    
    class RemoveAllMultipathForSystem : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveAllMultipathForSystem";
      inline static const char* const Documentation = "Disable all multipath for the specified constellation.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------------------------------------------------------------------\n"      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)";
      inline static const char* const TargetId = "";



          RemoveAllMultipathForSystem()
            : CommandBase(CmdName, TargetId)
          {}

          RemoveAllMultipathForSystem(const std::string& system, bool reset)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
            setReset(reset);
          }


          static RemoveAllMultipathForSystemPtr create(const std::string& system, bool reset)
          {
            return std::make_shared<RemoveAllMultipathForSystem>(system, reset);
          }

      static RemoveAllMultipathForSystemPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveAllMultipathForSystem>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<bool>::is_valid(m_values["Reset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "Reset"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool reset() const
          {
            return parse_json<bool>::parse(m_values["Reset"]);
          }

          void setReset(bool reset)
          {
            m_values.AddMember("Reset", parse_json<bool>::format(reset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(RemoveAllMultipathForSystem);
  }
}

