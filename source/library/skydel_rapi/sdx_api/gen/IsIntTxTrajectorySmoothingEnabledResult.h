#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsIntTxTrajectorySmoothingEnabled.
///
/// Name    Type   Description
/// ------- ------ -------------------------------------------------------------------
/// Enabled bool   If true, interference trajectory will be smoothed during simulation
/// Id      string Transmitter unique identifier.
///

class IsIntTxTrajectorySmoothingEnabledResult;
typedef std::shared_ptr<IsIntTxTrajectorySmoothingEnabledResult> IsIntTxTrajectorySmoothingEnabledResultPtr;

class IsIntTxTrajectorySmoothingEnabledResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsIntTxTrajectorySmoothingEnabledResult";
  inline static const char* const Documentation =
    "Result of IsIntTxTrajectorySmoothingEnabled.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ -------------------------------------------------------------------\n"
    "Enabled bool   If true, interference trajectory will be smoothed during simulation\n"
    "Id      string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  IsIntTxTrajectorySmoothingEnabledResult() : CommandResult(CmdName, TargetId) {}

  IsIntTxTrajectorySmoothingEnabledResult(bool enabled, const std::string& id) : CommandResult(CmdName, TargetId)
  {

    setEnabled(enabled);
    setId(id);
  }

  IsIntTxTrajectorySmoothingEnabledResult(CommandBasePtr relatedCommand, bool enabled, const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setEnabled(enabled);
    setId(id);
  }

  static IsIntTxTrajectorySmoothingEnabledResultPtr create(bool enabled, const std::string& id)
  {
    return std::make_shared<IsIntTxTrajectorySmoothingEnabledResult>(enabled, id);
  }

  static IsIntTxTrajectorySmoothingEnabledResultPtr create(CommandBasePtr relatedCommand,
                                                           bool enabled,
                                                           const std::string& id)
  {
    return std::make_shared<IsIntTxTrajectorySmoothingEnabledResult>(relatedCommand, enabled, id);
  }

  static IsIntTxTrajectorySmoothingEnabledResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsIntTxTrajectorySmoothingEnabledResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Enabled", "Id"};
    return names;
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsIntTxTrajectorySmoothingEnabledResult);
} // namespace Cmd
} // namespace Sdx
