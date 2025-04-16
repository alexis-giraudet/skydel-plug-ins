#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsSbasFastCorrectionsEnabledFor.
    ///
    /// Name      Type            Description
    /// --------- --------------- ----------------------------------------------------------------------------------------------------
    /// System    string          "GPS" or "SBAS"
    /// IsEnabled bool            True if corrections are enabled
    /// ErrorType optional string Comma separated error type to enable/disable. Accepted error types are "PSR offset" and "PSR error".
    ///                           Default value is "PSR error". Getter only accepts one error type.
    ///

    class IsSbasFastCorrectionsEnabledForResult;
    typedef std::shared_ptr<IsSbasFastCorrectionsEnabledForResult> IsSbasFastCorrectionsEnabledForResultPtr;
    
    
    class IsSbasFastCorrectionsEnabledForResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "IsSbasFastCorrectionsEnabledForResult";
      inline static const char* const Documentation = "Result of IsSbasFastCorrectionsEnabledFor.\n"      "\n"      "Name      Type            Description\n"      "--------- --------------- ----------------------------------------------------------------------------------------------------\n"      "System    string          \"GPS\" or \"SBAS\"\n"      "IsEnabled bool            True if corrections are enabled\n"      "ErrorType optional string Comma separated error type to enable/disable. Accepted error types are \"PSR offset\" and \"PSR error\".\n"      "                          Default value is \"PSR error\". Getter only accepts one error type.";
      inline static const char* const TargetId = "";



          IsSbasFastCorrectionsEnabledForResult()
            : CommandResult(CmdName, TargetId)
          {}

          IsSbasFastCorrectionsEnabledForResult(const std::string& system, bool isEnabled, const std::optional<std::string>& errorType = {})
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setIsEnabled(isEnabled);
            setErrorType(errorType);
          }

          IsSbasFastCorrectionsEnabledForResult(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled, const std::optional<std::string>& errorType = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setIsEnabled(isEnabled);
            setErrorType(errorType);
          }



          static IsSbasFastCorrectionsEnabledForResultPtr create(const std::string& system, bool isEnabled, const std::optional<std::string>& errorType = {})
          {
            return std::make_shared<IsSbasFastCorrectionsEnabledForResult>(system, isEnabled, errorType);
          }

          static IsSbasFastCorrectionsEnabledForResultPtr create(CommandBasePtr relatedCommand, const std::string& system, bool isEnabled, const std::optional<std::string>& errorType = {})
          {
            return std::make_shared<IsSbasFastCorrectionsEnabledForResult>(relatedCommand, system, isEnabled, errorType);
          }

      static IsSbasFastCorrectionsEnabledForResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsSbasFastCorrectionsEnabledForResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<bool>::is_valid(m_values["IsEnabled"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["ErrorType"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "IsEnabled", "ErrorType"}; 
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



          std::optional<std::string> errorType() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["ErrorType"]);
          }

          void setErrorType(const std::optional<std::string>& errorType)
          {
            m_values.AddMember("ErrorType", parse_json<std::optional<std::string>>::format(errorType, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(IsSbasFastCorrectionsEnabledForResult);
  }
}

