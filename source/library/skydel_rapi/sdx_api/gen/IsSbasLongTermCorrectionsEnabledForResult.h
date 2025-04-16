#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSbasLongTermCorrectionsEnabledFor.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------
    /// System    string As of today, only "GPS" is supported.
    /// IsEnabled bool   True if corrections are enabled.
    ///

    class IsSbasLongTermCorrectionsEnabledForResult;
    typedef std::shared_ptr<IsSbasLongTermCorrectionsEnabledForResult> IsSbasLongTermCorrectionsEnabledForResultPtr;
    
    
    class IsSbasLongTermCorrectionsEnabledForResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsSbasLongTermCorrectionsEnabledForResult";
      inline static const char* const Documentation = "Result of IsSbasLongTermCorrectionsEnabledFor.\n"      "\n"      "Name      Type   Description\n"      "--------- ------ -------------------------------------\n"      "System    string As of today, only \"GPS\" is supported.\n"      "IsEnabled bool   True if corrections are enabled.";
      inline static const char* const TargetId = "";



          IsSbasLongTermCorrectionsEnabledForResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsSbasLongTermCorrectionsEnabledForResult(const std::string& system, bool isEnabled)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setIsEnabled(isEnabled);
          }

          IsSbasLongTermCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setIsEnabled(isEnabled);
          }



          static IsSbasLongTermCorrectionsEnabledForResultPtr create(const std::string& system, bool isEnabled)
          {
            return std::make_shared<IsSbasLongTermCorrectionsEnabledForResult>(system, isEnabled);
          }

          static IsSbasLongTermCorrectionsEnabledForResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled)
          {
            return std::make_shared<IsSbasLongTermCorrectionsEnabledForResult>(relatedCommand, system, isEnabled);
          }

      static IsSbasLongTermCorrectionsEnabledForResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSbasLongTermCorrectionsEnabledForResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<bool>::is_valid(m_values["IsEnabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "IsEnabled"}; 
        return names; 
      }
      


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool isEnabled() const
          {
            return parse_json<bool>::parse(m_values["IsEnabled"]);
          }

          void setIsEnabled(bool isEnabled)
          {
            m_values.AddMember("IsEnabled", parse_json<bool>::format(isEnabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsSbasLongTermCorrectionsEnabledForResult);
  }
}

