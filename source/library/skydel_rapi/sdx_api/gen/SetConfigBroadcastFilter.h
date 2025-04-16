#pragma once

#include <memory>
#include <vector>

#include "command_base.h"
#include "command_factory.h"
#include "gen/ConfigFilter.h"

namespace Sdx
{
namespace Cmd
{
///
/// Set the filter for configuration broadcast.
///
/// Name   Type               Description
/// ------ ------------------ ------------------------------------------------------------------------------
/// Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.
///

class SetConfigBroadcastFilter;
typedef std::shared_ptr<SetConfigBroadcastFilter> SetConfigBroadcastFilterPtr;

class SetConfigBroadcastFilter : public CommandBase
{
public:
  inline static const char* const CmdName = "SetConfigBroadcastFilter";
  inline static const char* const Documentation =
    "Set the filter for configuration broadcast.\n"
    "\n"
    "Name   Type               Description\n"
    "------ ------------------ ------------------------------------------------------------------------------\n"
    "Filter array ConfigFilter Every configuration section set in this array will be excluded from broadcast.";
  inline static const char* const TargetId = "";

  SetConfigBroadcastFilter() : CommandBase(CmdName, TargetId) {}

  SetConfigBroadcastFilter(const std::vector<Sdx::ConfigFilter>& filter) : CommandBase(CmdName, TargetId)
  {

    setFilter(filter);
  }

  static SetConfigBroadcastFilterPtr create(const std::vector<Sdx::ConfigFilter>& filter)
  {
    return std::make_shared<SetConfigBroadcastFilter>(filter);
  }

  static SetConfigBroadcastFilterPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetConfigBroadcastFilter>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<Sdx::ConfigFilter>>::is_valid(m_values["Filter"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Filter"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::vector<Sdx::ConfigFilter> filter() const
  {
    return parse_json<std::vector<Sdx::ConfigFilter>>::parse(m_values["Filter"]);
  }

  void setFilter(const std::vector<Sdx::ConfigFilter>& filter)
  {
    m_values.AddMember("Filter",
                       parse_json<std::vector<Sdx::ConfigFilter>>::format(filter, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetConfigBroadcastFilter);
} // namespace Cmd
} // namespace Sdx
