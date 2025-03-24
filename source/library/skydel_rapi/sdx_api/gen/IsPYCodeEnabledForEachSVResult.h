#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsPYCodeEnabledForEachSV.
///
/// Name    Type       Description
/// ------- ---------- ----------------------------------------------------------------------------------------
/// Signal  string     Accepted signal keys: "L1P", "L2P"
/// Enabled array bool Enable P(Y)-Code if True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
///

class IsPYCodeEnabledForEachSVResult;
typedef std::shared_ptr<IsPYCodeEnabledForEachSVResult> IsPYCodeEnabledForEachSVResultPtr;

class IsPYCodeEnabledForEachSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsPYCodeEnabledForEachSVResult";
  inline static const char* const Documentation =
    "Result of IsPYCodeEnabledForEachSV.\n"
    "\n"
    "Name    Type       Description\n"
    "------- ---------- ----------------------------------------------------------------------------------------\n"
    "Signal  string     Accepted signal keys: \"L1P\", \"L2P\"\n"
    "Enabled array bool Enable P(Y)-Code if True. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
  inline static const char* const TargetId = "";

  IsPYCodeEnabledForEachSVResult() : CommandResult(CmdName, TargetId) {}

  IsPYCodeEnabledForEachSVResult(const std::string& signal, const std::vector<bool>& enabled) :
    CommandResult(CmdName, TargetId)
  {

    setSignal(signal);
    setEnabled(enabled);
  }

  IsPYCodeEnabledForEachSVResult(CommandBasePtr relatedCommand,
                                 const std::string& signal,
                                 const std::vector<bool>& enabled) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSignal(signal);
    setEnabled(enabled);
  }

  static IsPYCodeEnabledForEachSVResultPtr create(const std::string& signal, const std::vector<bool>& enabled)
  {
    return std::make_shared<IsPYCodeEnabledForEachSVResult>(signal, enabled);
  }

  static IsPYCodeEnabledForEachSVResultPtr create(CommandBasePtr relatedCommand,
                                                  const std::string& signal,
                                                  const std::vector<bool>& enabled)
  {
    return std::make_shared<IsPYCodeEnabledForEachSVResult>(relatedCommand, signal, enabled);
  }

  static IsPYCodeEnabledForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsPYCodeEnabledForEachSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<std::vector<bool>>::is_valid(m_values["Enabled"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Enabled"};
    return names;
  }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<bool> enabled() const { return parse_json<std::vector<bool>>::parse(m_values["Enabled"]); }

  void setEnabled(const std::vector<bool>& enabled)
  {
    m_values.AddMember("Enabled",
                       parse_json<std::vector<bool>>::format(enabled, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsPYCodeEnabledForEachSVResult);
} // namespace Cmd
} // namespace Sdx
