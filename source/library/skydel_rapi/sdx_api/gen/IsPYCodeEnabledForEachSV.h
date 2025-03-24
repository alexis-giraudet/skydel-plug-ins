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
/// Tells if the P(Y)-Code is enabled or disabled for each satellite.
///
/// Name   Type   Description
/// ------ ------ ----------------------------------
/// Signal string Accepted signal keys: "L1P", "L2P"
///

class IsPYCodeEnabledForEachSV;
typedef std::shared_ptr<IsPYCodeEnabledForEachSV> IsPYCodeEnabledForEachSVPtr;

class IsPYCodeEnabledForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "IsPYCodeEnabledForEachSV";
  inline static const char* const Documentation = "Tells if the P(Y)-Code is enabled or disabled for each satellite.\n"
                                                  "\n"
                                                  "Name   Type   Description\n"
                                                  "------ ------ ----------------------------------\n"
                                                  "Signal string Accepted signal keys: \"L1P\", \"L2P\"";
  inline static const char* const TargetId = "";

  IsPYCodeEnabledForEachSV() : CommandBase(CmdName, TargetId) {}

  IsPYCodeEnabledForEachSV(const std::string& signal) : CommandBase(CmdName, TargetId) { setSignal(signal); }

  static IsPYCodeEnabledForEachSVPtr create(const std::string& signal)
  {
    return std::make_shared<IsPYCodeEnabledForEachSV>(signal);
  }

  static IsPYCodeEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsPYCodeEnabledForEachSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal"};
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
};
REGISTER_COMMAND_TO_FACTORY(IsPYCodeEnabledForEachSV);
} // namespace Cmd
} // namespace Sdx
