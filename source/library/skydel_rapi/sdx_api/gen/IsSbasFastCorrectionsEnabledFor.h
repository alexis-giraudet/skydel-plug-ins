#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get whether specific errors type for this constellation should be compensated in SBAS fast corrections
///
/// Name      Type            Description
/// --------- ---------------
/// ---------------------------------------------------------------------------------------------------- System string
/// "GPS" or "SBAS" ErrorType optional string Comma separated error type to enable/disable. Accepted error types are
/// "PSR offset" and "PSR error".
///                           Default value is "PSR error". Getter only accepts one error type.
///

class IsSbasFastCorrectionsEnabledFor;
typedef std::shared_ptr<IsSbasFastCorrectionsEnabledFor> IsSbasFastCorrectionsEnabledForPtr;

class IsSbasFastCorrectionsEnabledFor : public CommandBase
{
public:
  inline static const char* const CmdName = "IsSbasFastCorrectionsEnabledFor";
  inline static const char* const Documentation =
    "Get whether specific errors type for this constellation should be compensated in SBAS fast corrections\n"
    "\n"
    "Name      Type            Description\n"
    "--------- --------------- ----------------------------------------------------------------------------------------------------\n"
    "System    string          \"GPS\" or \"SBAS\"\n"
    "ErrorType optional string Comma separated error type to enable/disable. Accepted error types are \"PSR offset\" and \"PSR error\".\n"
    "                          Default value is \"PSR error\". Getter only accepts one error type.";
  inline static const char* const TargetId = "";

  IsSbasFastCorrectionsEnabledFor() : CommandBase(CmdName, TargetId) {}

  IsSbasFastCorrectionsEnabledFor(const std::string& system, const std::optional<std::string>& errorType = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setErrorType(errorType);
  }

  static IsSbasFastCorrectionsEnabledForPtr create(const std::string& system,
                                                   const std::optional<std::string>& errorType = {})
  {
    return std::make_shared<IsSbasFastCorrectionsEnabledFor>(system, errorType);
  }

  static IsSbasFastCorrectionsEnabledForPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSbasFastCorrectionsEnabledFor>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["ErrorType"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "ErrorType"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<std::string> errorType() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["ErrorType"]);
  }

  void setErrorType(const std::optional<std::string>& errorType)
  {
    m_values.AddMember("ErrorType",
                       parse_json<std::optional<std::string>>::format(errorType, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsSbasFastCorrectionsEnabledFor);
} // namespace Cmd
} // namespace Sdx
