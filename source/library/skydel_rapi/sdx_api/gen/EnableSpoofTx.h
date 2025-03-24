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
/// Enable/Disable the spoofer.
///
/// Name    Type   Description
/// ------- ------ ------------------------------------------------
/// Enabled bool   Enable (true) or disable (false) the transmitter
/// Id      string Transmitter unique identifier.
///

class EnableSpoofTx;
typedef std::shared_ptr<EnableSpoofTx> EnableSpoofTxPtr;

class EnableSpoofTx : public CommandBase
{
public:
  inline static const char* const CmdName = "EnableSpoofTx";
  inline static const char* const Documentation = "Enable/Disable the spoofer.\n"
                                                  "\n"
                                                  "Name    Type   Description\n"
                                                  "------- ------ ------------------------------------------------\n"
                                                  "Enabled bool   Enable (true) or disable (false) the transmitter\n"
                                                  "Id      string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  EnableSpoofTx() : CommandBase(CmdName, TargetId) {}

  EnableSpoofTx(bool enabled, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setEnabled(enabled);
    setId(id);
  }

  static EnableSpoofTxPtr create(bool enabled, const std::string& id)
  {
    return std::make_shared<EnableSpoofTx>(enabled, id);
  }

  static EnableSpoofTxPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<EnableSpoofTx>(ptr); }

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

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

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
REGISTER_COMMAND_TO_FACTORY(EnableSpoofTx);
} // namespace Cmd
} // namespace Sdx
