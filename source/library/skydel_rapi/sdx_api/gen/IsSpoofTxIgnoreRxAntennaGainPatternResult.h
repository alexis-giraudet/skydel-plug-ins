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
/// Result of IsSpoofTxIgnoreRxAntennaGainPattern.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------------
/// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
/// Id     string Transmitter unique identifier.
///

class IsSpoofTxIgnoreRxAntennaGainPatternResult;
typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaGainPatternResult> IsSpoofTxIgnoreRxAntennaGainPatternResultPtr;

class IsSpoofTxIgnoreRxAntennaGainPatternResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsSpoofTxIgnoreRxAntennaGainPatternResult";
  inline static const char* const Documentation =
    "Result of IsSpoofTxIgnoreRxAntennaGainPattern.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------------\n"
    "Ignore bool   If true, the receiver's antenna gain pattern will be ignored.\n"
    "Id     string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  IsSpoofTxIgnoreRxAntennaGainPatternResult() : CommandResult(CmdName, TargetId) {}

  IsSpoofTxIgnoreRxAntennaGainPatternResult(bool ignore, const std::string& id) : CommandResult(CmdName, TargetId)
  {

    setIgnore(ignore);
    setId(id);
  }

  IsSpoofTxIgnoreRxAntennaGainPatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setIgnore(ignore);
    setId(id);
  }

  static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr create(bool ignore, const std::string& id)
  {
    return std::make_shared<IsSpoofTxIgnoreRxAntennaGainPatternResult>(ignore, id);
  }

  static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr create(CommandBasePtr relatedCommand,
                                                             bool ignore,
                                                             const std::string& id)
  {
    return std::make_shared<IsSpoofTxIgnoreRxAntennaGainPatternResult>(relatedCommand, ignore, id);
  }

  static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSpoofTxIgnoreRxAntennaGainPatternResult>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsSpoofTxIgnoreRxAntennaGainPatternResult);
} // namespace Cmd
} // namespace Sdx
