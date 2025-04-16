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
/// Please note the command RemoveMessageModification is deprecated since 21.3. You may use
/// RemoveMessageModificationForSignal.
///
/// Removes the signal for the message modification.
///
/// Name   Type   Description
/// ------ ------
/// --------------------------------------------------------------------------------------------------------- Signal
/// string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
///                                             "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "B3I",
///                                             "QZSSL1CA", "QZSSL1CB", "QZSSL1S", "NAVICL5", "NAVICS", "SBASL1",
///                                             "SBASL5", "PULSARXL", "PULSARX1" and "PULSARX5"
/// Id     string Unique identifier
///

class RemoveMessageModification;
typedef std::shared_ptr<RemoveMessageModification> RemoveMessageModificationPtr;

class RemoveMessageModification : public CommandBase
{
public:
  inline static const char* const CmdName = "RemoveMessageModification";
  inline static const char* const Documentation =
    "Please note the command RemoveMessageModification is deprecated since 21.3. You may use RemoveMessageModificationForSignal.\n"
    "\n"
    "Removes the signal for the message modification.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ---------------------------------------------------------------------------------------------------------\n"
    "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
    "                                            \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\",\n"
    "                                            \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"NAVICS\", \"SBASL1\", \"SBASL5\",\n"
    "                                            \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"\n"
    "Id     string Unique identifier";
  inline static const char* const TargetId = "";

  RemoveMessageModification() : CommandBase(CmdName, TargetId) {}

  RemoveMessageModification(const std::string& signal, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setId(id);
  }

  static RemoveMessageModificationPtr create(const std::string& signal, const std::string& id)
  {
    return std::make_shared<RemoveMessageModification>(signal, id);
  }

  static RemoveMessageModificationPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RemoveMessageModification>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RemoveMessageModification);
} // namespace Cmd
} // namespace Sdx
