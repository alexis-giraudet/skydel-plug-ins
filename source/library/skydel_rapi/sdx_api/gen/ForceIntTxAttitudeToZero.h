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
/// Set force interference vehicle yaw, pitch and roll to zero enabled or disabled
///
/// Name    Type   Description
/// ------- ------ ------------------------------------------------------------
/// Enabled bool   If true, interference vehicle won't rotate during simulation
/// Id      string Transmitter unique identifier.
///

class ForceIntTxAttitudeToZero;
typedef std::shared_ptr<ForceIntTxAttitudeToZero> ForceIntTxAttitudeToZeroPtr;

class ForceIntTxAttitudeToZero : public CommandBase
{
public:
  inline static const char* const CmdName = "ForceIntTxAttitudeToZero";
  inline static const char* const Documentation =
    "Set force interference vehicle yaw, pitch and roll to zero enabled or disabled\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ ------------------------------------------------------------\n"
    "Enabled bool   If true, interference vehicle won't rotate during simulation\n"
    "Id      string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  ForceIntTxAttitudeToZero() : CommandBase(CmdName, TargetId) {}

  ForceIntTxAttitudeToZero(bool enabled, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setEnabled(enabled);
    setId(id);
  }

  static ForceIntTxAttitudeToZeroPtr create(bool enabled, const std::string& id)
  {
    return std::make_shared<ForceIntTxAttitudeToZero>(enabled, id);
  }

  static ForceIntTxAttitudeToZeroPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ForceIntTxAttitudeToZero>(ptr);
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

  int executePermission() const { return EXECUTE_IF_IDLE; }

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
REGISTER_COMMAND_TO_FACTORY(ForceIntTxAttitudeToZero);
} // namespace Cmd
} // namespace Sdx
