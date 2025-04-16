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
/// Get whether a dynamic transmitter ignore the receiver's antenna gain pattern.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class IsIntTxIgnoreRxAntennaGainPattern;
typedef std::shared_ptr<IsIntTxIgnoreRxAntennaGainPattern> IsIntTxIgnoreRxAntennaGainPatternPtr;

class IsIntTxIgnoreRxAntennaGainPattern : public CommandBase
{
public:
  inline static const char* const CmdName = "IsIntTxIgnoreRxAntennaGainPattern";
  inline static const char* const Documentation =
    "Get whether a dynamic transmitter ignore the receiver's antenna gain pattern.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ------------------------------\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  IsIntTxIgnoreRxAntennaGainPattern() : CommandBase(CmdName, TargetId) {}

  IsIntTxIgnoreRxAntennaGainPattern(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static IsIntTxIgnoreRxAntennaGainPatternPtr create(const std::string& id)
  {
    return std::make_shared<IsIntTxIgnoreRxAntennaGainPattern>(id);
  }

  static IsIntTxIgnoreRxAntennaGainPatternPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsIntTxIgnoreRxAntennaGainPattern>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsIntTxIgnoreRxAntennaGainPattern);
} // namespace Cmd
} // namespace Sdx
