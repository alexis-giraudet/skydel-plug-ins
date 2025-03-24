#pragma once

#include <memory>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get whether a dynamic transmitter ignore the receiver's antenna phase pattern.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class IsIntTxIgnoreRxAntennaPhasePattern;
typedef std::shared_ptr<IsIntTxIgnoreRxAntennaPhasePattern> IsIntTxIgnoreRxAntennaPhasePatternPtr;

class IsIntTxIgnoreRxAntennaPhasePattern : public CommandBase
{
public:
  inline static const char* const CmdName = "IsIntTxIgnoreRxAntennaPhasePattern";
  inline static const char* const Documentation =
    "Get whether a dynamic transmitter ignore the receiver's antenna phase pattern.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ------------------------------\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  IsIntTxIgnoreRxAntennaPhasePattern() : CommandBase(CmdName, TargetId) {}

  IsIntTxIgnoreRxAntennaPhasePattern(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static IsIntTxIgnoreRxAntennaPhasePatternPtr create(const std::string& id)
  {
    return std::make_shared<IsIntTxIgnoreRxAntennaPhasePattern>(id);
  }

  static IsIntTxIgnoreRxAntennaPhasePatternPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaPhasePattern>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsIntTxIgnoreRxAntennaPhasePattern);
} // namespace Cmd
} // namespace Sdx
