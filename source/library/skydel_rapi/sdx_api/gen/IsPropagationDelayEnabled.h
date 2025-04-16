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
    /// Tells if the propagation delay is enabled.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class IsPropagationDelayEnabled;
    typedef std::shared_ptr<IsPropagationDelayEnabled> IsPropagationDelayEnabledPtr;
    
    
    class IsPropagationDelayEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsPropagationDelayEnabled";
      inline static const char* const Documentation = "Tells if the propagation delay is enabled.\n"      "\n"      "Name   Type   Description\n"      "------ ------ --------------------------------------------------------------------------\n"      "System string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
      inline static const char* const TargetId = "";



          IsPropagationDelayEnabled()
            : CommandBase(CmdName, TargetId)
          {}

          IsPropagationDelayEnabled(const std::string& system)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
          }


          static IsPropagationDelayEnabledPtr create(const std::string& system)
          {
            return std::make_shared<IsPropagationDelayEnabled>(system);
          }

      static IsPropagationDelayEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsPropagationDelayEnabled>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System"}; 
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

    };
    REGISTER_COMMAND_TO_FACTORY(IsPropagationDelayEnabled);
  }
}

