#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsUsingVelocityInSbasMessage25.
///
/// Name        Type Description
/// ----------- ---- --------------------------------------------------------
/// UseVelocity bool Whether SBAS message 25 should send velocity corrections
///

class IsUsingVelocityInSbasMessage25Result;
typedef std::shared_ptr<IsUsingVelocityInSbasMessage25Result> IsUsingVelocityInSbasMessage25ResultPtr;

class IsUsingVelocityInSbasMessage25Result : public CommandResult
{
public:
  inline static const char* const CmdName = "IsUsingVelocityInSbasMessage25Result";
  inline static const char* const Documentation =
    "Result of IsUsingVelocityInSbasMessage25.\n"
    "\n"
    "Name        Type Description\n"
    "----------- ---- --------------------------------------------------------\n"
    "UseVelocity bool Whether SBAS message 25 should send velocity corrections";
  inline static const char* const TargetId = "";

  IsUsingVelocityInSbasMessage25Result() : CommandResult(CmdName, TargetId) {}

  IsUsingVelocityInSbasMessage25Result(bool useVelocity) : CommandResult(CmdName, TargetId)
  {

    setUseVelocity(useVelocity);
  }

  IsUsingVelocityInSbasMessage25Result(CommandBasePtr relatedCommand, bool useVelocity) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setUseVelocity(useVelocity);
  }

  static IsUsingVelocityInSbasMessage25ResultPtr create(bool useVelocity)
  {
    return std::make_shared<IsUsingVelocityInSbasMessage25Result>(useVelocity);
  }

  static IsUsingVelocityInSbasMessage25ResultPtr create(CommandBasePtr relatedCommand, bool useVelocity)
  {
    return std::make_shared<IsUsingVelocityInSbasMessage25Result>(relatedCommand, useVelocity);
  }

  static IsUsingVelocityInSbasMessage25ResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsUsingVelocityInSbasMessage25Result>(ptr);
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

  bool useVelocity() const { return parse_json<bool>::parse(m_values["UseVelocity"]); }

  void setUseVelocity(bool useVelocity)
  {
    m_values.AddMember("UseVelocity",
                       parse_json<bool>::format(useVelocity, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsUsingVelocityInSbasMessage25Result);
} // namespace Cmd
} // namespace Sdx
