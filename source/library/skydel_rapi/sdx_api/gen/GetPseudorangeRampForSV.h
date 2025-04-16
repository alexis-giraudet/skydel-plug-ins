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
/// Get PSR ramp event. This function lets user change the pseudorange of any satellite.
/// If SV ID is set to 0, the change is applied to all satellites.
///
///           Hold Start Time
///           |         Hold Stop Time
///           |         |
///           ...........
///          ..         ...
///         ..            ...
///   .......               .........> Time
///         |               |
///         Start Time      Stop Time
///
///
/// Name Type   Description
/// ---- ------ -----------------------------------------------------------------
/// Id   string Unique identifier automatically set by simulator if empty string.
///             The IDs pool is common between all system.
///

class GetPseudorangeRampForSV;
typedef std::shared_ptr<GetPseudorangeRampForSV> GetPseudorangeRampForSVPtr;

class GetPseudorangeRampForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetPseudorangeRampForSV";
  inline static const char* const Documentation =
    "Get PSR ramp event. This function lets user change the pseudorange of any satellite.\n"
    "If SV ID is set to 0, the change is applied to all satellites.\n"
    "\n"
    "          Hold Start Time\n"
    "          |         Hold Stop Time\n"
    "          |         |\n"
    "          ...........\n"
    "         ..         ...\n"
    "        ..            ...\n"
    "  .......               .........> Time\n"
    "        |               |\n"
    "        Start Time      Stop Time\n"
    "\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ -----------------------------------------------------------------\n"
    "Id   string Unique identifier automatically set by simulator if empty string.\n"
    "            The IDs pool is common between all system.";
  inline static const char* const TargetId = "";

  GetPseudorangeRampForSV() : CommandBase(CmdName, TargetId) {}

  GetPseudorangeRampForSV(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetPseudorangeRampForSVPtr create(const std::string& id)
  {
    return std::make_shared<GetPseudorangeRampForSV>(id);
  }

  static GetPseudorangeRampForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPseudorangeRampForSV>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetPseudorangeRampForSV);
} // namespace Cmd
} // namespace Sdx
