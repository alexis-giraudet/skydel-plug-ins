#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set whether SBAS message 25 should send velocity corrections
///
/// Name        Type Description
/// ----------- ---- --------------------------------------------------------
/// UseVelocity bool Whether SBAS message 25 should send velocity corrections
///

class SetUsingVelocityInSbasMessage25;
typedef std::shared_ptr<SetUsingVelocityInSbasMessage25> SetUsingVelocityInSbasMessage25Ptr;

class SetUsingVelocityInSbasMessage25 : public CommandBase
{
public:
  inline static const char* const CmdName = "SetUsingVelocityInSbasMessage25";
  inline static const char* const Documentation =
    "Set whether SBAS message 25 should send velocity corrections\n"
    "\n"
    "Name        Type Description\n"
    "----------- ---- --------------------------------------------------------\n"
    "UseVelocity bool Whether SBAS message 25 should send velocity corrections";
  inline static const char* const TargetId = "";

  SetUsingVelocityInSbasMessage25() : CommandBase(CmdName, TargetId) {}

  SetUsingVelocityInSbasMessage25(bool useVelocity) : CommandBase(CmdName, TargetId) { setUseVelocity(useVelocity); }

  static SetUsingVelocityInSbasMessage25Ptr create(bool useVelocity)
  {
    return std::make_shared<SetUsingVelocityInSbasMessage25>(useVelocity);
  }

  static SetUsingVelocityInSbasMessage25Ptr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetUsingVelocityInSbasMessage25>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<bool>::is_valid(m_values["UseVelocity"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"UseVelocity"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  bool useVelocity() const { return parse_json<bool>::parse(m_values["UseVelocity"]); }

  void setUseVelocity(bool useVelocity)
  {
    m_values.AddMember("UseVelocity",
                       parse_json<bool>::format(useVelocity, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetUsingVelocityInSbasMessage25);
} // namespace Cmd
} // namespace Sdx
