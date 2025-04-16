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
    /// Get whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------
    /// System string As of today, only "GPS" is supported.
    ///

    class IsSbasLongTermCorrectionsEnabledFor;
    typedef std::shared_ptr<IsSbasLongTermCorrectionsEnabledFor> IsSbasLongTermCorrectionsEnabledForPtr;
    
    
    class IsSbasLongTermCorrectionsEnabledFor : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsSbasLongTermCorrectionsEnabledFor";
      inline static const char* const Documentation = "Get whether ephemeris errors for this constellation should be compensated in SBAS long term corrections.\n"      "\n"      "Name   Type   Description\n"      "------ ------ -------------------------------------\n"      "System string As of today, only \"GPS\" is supported.";
      inline static const char* const TargetId = "";



          IsSbasLongTermCorrectionsEnabledFor()
            : CommandBase(CmdName, TargetId)
          {}

          IsSbasLongTermCorrectionsEnabledFor(const std::string& system)
            : CommandBase(CmdName, TargetId)
          {

            setSystem(system);
          }


          static IsSbasLongTermCorrectionsEnabledForPtr create(const std::string& system)
          {
            return std::make_shared<IsSbasLongTermCorrectionsEnabledFor>(system);
          }

      static IsSbasLongTermCorrectionsEnabledForPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSbasLongTermCorrectionsEnabledFor>(ptr);
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
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
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
    REGISTER_COMMAND_TO_FACTORY(IsSbasLongTermCorrectionsEnabledFor);
  }
}

