#pragma once

#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of IsSatMotionFixed.
///
/// Name    Type   Description
/// ------- ------
/// --------------------------------------------------------------------------------------------------------------
/// System  string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// SvId    int    The satellite's SV ID.
/// IsFixed bool   If true, the satellite relative position is fixed, if false, the satellite motion follows a normal
/// trajectory.
///

class IsSatMotionFixedResult;
typedef std::shared_ptr<IsSatMotionFixedResult> IsSatMotionFixedResultPtr;

class IsSatMotionFixedResult : public CommandResult
{
public:
  inline static const char* const CmdName = "IsSatMotionFixedResult";
  inline static const char* const Documentation =
    "Result of IsSatMotionFixed.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ --------------------------------------------------------------------------------------------------------------\n"
    "System  string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "SvId    int    The satellite's SV ID.\n"
    "IsFixed bool   If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.";
  inline static const char* const TargetId = "";

  IsSatMotionFixedResult() : CommandResult(CmdName, TargetId) {}

  IsSatMotionFixedResult(const std::string& system, int svId, bool isFixed) : CommandResult(CmdName, TargetId)
  {

    setSystem(system);
    setSvId(svId);
    setIsFixed(isFixed);
  }

  IsSatMotionFixedResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool isFixed) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSystem(system);
    setSvId(svId);
    setIsFixed(isFixed);
  }

  static IsSatMotionFixedResultPtr create(const std::string& system, int svId, bool isFixed)
  {
    return std::make_shared<IsSatMotionFixedResult>(system, svId, isFixed);
  }

  static IsSatMotionFixedResultPtr create(CommandBasePtr relatedCommand,
                                          const std::string& system,
                                          int svId,
                                          bool isFixed)
  {
    return std::make_shared<IsSatMotionFixedResult>(relatedCommand, system, svId, isFixed);
  }

  static IsSatMotionFixedResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsSatMotionFixedResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<bool>::is_valid(m_values["IsFixed"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "SvId", "IsFixed"};
    return names;
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool isFixed() const { return parse_json<bool>::parse(m_values["IsFixed"]); }

  void setIsFixed(bool isFixed)
  {
    m_values.AddMember("IsFixed", parse_json<bool>::format(isFixed, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(IsSatMotionFixedResult);
} // namespace Cmd
} // namespace Sdx
