#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// EndTrackDefinition Result with created track informations.
///
/// Name  Type Description
/// ----- ---- ----------------------------------------------------------------------------------------------------
/// Count int  Number of nodes in the track. The client can compare this value with the number of positions pushed.
///

class EndTrackDefinitionResult;
typedef std::shared_ptr<EndTrackDefinitionResult> EndTrackDefinitionResultPtr;

class EndTrackDefinitionResult : public CommandResult
{
public:
  inline static const char* const CmdName = "EndTrackDefinitionResult";
  inline static const char* const Documentation =
    "EndTrackDefinition Result with created track informations.\n"
    "\n"
    "Name  Type Description\n"
    "----- ---- ----------------------------------------------------------------------------------------------------\n"
    "Count int  Number of nodes in the track. The client can compare this value with the number of positions pushed.";
  inline static const char* const TargetId = "";

  EndTrackDefinitionResult() : CommandResult(CmdName, TargetId) {}

  EndTrackDefinitionResult(int count) : CommandResult(CmdName, TargetId) { setCount(count); }

  EndTrackDefinitionResult(CommandBasePtr relatedCommand, int count) : CommandResult(CmdName, TargetId, relatedCommand)
  {

    setCount(count);
  }

  static EndTrackDefinitionResultPtr create(int count) { return std::make_shared<EndTrackDefinitionResult>(count); }

  static EndTrackDefinitionResultPtr create(CommandBasePtr relatedCommand, int count)
  {
    return std::make_shared<EndTrackDefinitionResult>(relatedCommand, count);
  }

  static EndTrackDefinitionResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<EndTrackDefinitionResult>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Count"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Count"};
    return names;
  }

  int count() const { return parse_json<int>::parse(m_values["Count"]); }

  void setCount(int count)
  {
    m_values.AddMember("Count", parse_json<int>::format(count, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(EndTrackDefinitionResult);
} // namespace Cmd
} // namespace Sdx
