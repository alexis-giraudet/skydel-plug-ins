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
/// Result of IsIntTxIgnoreRxAntennaGainPattern.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------------
/// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
/// Id     string Transmitter unique identifier.
///

class IsIntTxIgnoreRxAntennaGainPatternResult;
typedef std::shared_ptr<IsIntTxIgnoreRxAntennaGainPatternResult> IsIntTxIgnoreRxAntennaGainPatternResultPtr;

class IsIntTxIgnoreRxAntennaGainPatternResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsIntTxIgnoreRxAntennaGainPatternResult";
  inline static const char* const Documentation =
    "Result of IsIntTxIgnoreRxAntennaGainPattern.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------------\n"
    "Ignore bool   If true, the receiver's antenna gain pattern will be ignored.\n"
    "Id     string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  IsIntTxIgnoreRxAntennaGainPatternResult() : CommandResult(CmdName, TargetId) {}

  IsIntTxIgnoreRxAntennaGainPatternResult(bool ignore, const std::string& id) : CommandResult(CmdName, TargetId)
  {

    setIgnore(ignore);
    setId(id);
  }

  IsIntTxIgnoreRxAntennaGainPatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIgnore(ignore);
    setId(id);
  }

  static IsIntTxIgnoreRxAntennaGainPatternResultPtr create(bool ignore, const std::string& id)
  {
    return std::make_shared<IsIntTxIgnoreRxAntennaGainPatternResult>(ignore, id);
  }

  static IsIntTxIgnoreRxAntennaGainPatternResultPtr create(CommandBasePtr relatedCommand,
                                                           bool ignore,
                                                           const std::string& id)
  {
    return std::make_shared<IsIntTxIgnoreRxAntennaGainPatternResult>(relatedCommand, ignore, id);
  }

  static IsIntTxIgnoreRxAntennaGainPatternResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaGainPatternResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["Ignore"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Ignore", "Id"};
    return names;
  }

  bool ignore() const { return parse_json<bool>::parse(m_values["Ignore"]); }

  void setIgnore(bool ignore)
  {
    m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsIntTxIgnoreRxAntennaGainPatternResult);
} // namespace Cmd
} // namespace Sdx
