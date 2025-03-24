#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// HIL Tjoin. Value is in milliseconds.
///
/// Name     Type Description
/// -------- ---- -----------
/// HilTjoin int  HIL Tjoin.
///

class SetHilTjoin;
typedef std::shared_ptr<SetHilTjoin> SetHilTjoinPtr;

class SetHilTjoin : public CommandBase
{
public:
  inline static const char* const CmdName = "SetHilTjoin";
  inline static const char* const Documentation = "HIL Tjoin. Value is in milliseconds.\n"
                                                  "\n"
                                                  "Name     Type Description\n"
                                                  "-------- ---- -----------\n"
                                                  "HilTjoin int  HIL Tjoin.";
  inline static const char* const TargetId = "";

  SetHilTjoin() : CommandBase(CmdName, TargetId) {}

  SetHilTjoin(int hilTjoin) : CommandBase(CmdName, TargetId) { setHilTjoin(hilTjoin); }

  static SetHilTjoinPtr create(int hilTjoin) { return std::make_shared<SetHilTjoin>(hilTjoin); }

  static SetHilTjoinPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetHilTjoin>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["HilTjoin"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"HilTjoin"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int hilTjoin() const { return parse_json<int>::parse(m_values["HilTjoin"]); }

  void setHilTjoin(int hilTjoin)
  {
    m_values.AddMember("HilTjoin", parse_json<int>::format(hilTjoin, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetHilTjoin);
} // namespace Cmd
} // namespace Sdx
