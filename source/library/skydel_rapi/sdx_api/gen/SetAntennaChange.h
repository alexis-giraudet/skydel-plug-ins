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
/// Add/edit an antenna change.
///
/// Name      Type   Description
/// --------- ------ --------------------------------------------------
/// StartTime double Elapsed time in seconds since start of simulation.
/// Antenna   string Antenna model name
/// Id        string Unique identifier of the event
///

class SetAntennaChange;
typedef std::shared_ptr<SetAntennaChange> SetAntennaChangePtr;

class SetAntennaChange : public CommandBase
{
public:
  inline static const char* const CmdName = "SetAntennaChange";
  inline static const char* const Documentation =
    "Add/edit an antenna change.\n"
    "\n"
    "Name      Type   Description\n"
    "--------- ------ --------------------------------------------------\n"
    "StartTime double Elapsed time in seconds since start of simulation.\n"
    "Antenna   string Antenna model name\n"
    "Id        string Unique identifier of the event";
  inline static const char* const TargetId = "";

  SetAntennaChange() : CommandBase(CmdName, TargetId) {}

  SetAntennaChange(double startTime, const std::string& antenna, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setStartTime(startTime);
    setAntenna(antenna);
    setId(id);
  }

  static SetAntennaChangePtr create(double startTime, const std::string& antenna, const std::string& id)
  {
    return std::make_shared<SetAntennaChange>(startTime, antenna, id);
  }

  static SetAntennaChangePtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetAntennaChange>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<double>::is_valid(m_values["StartTime"]) &&
           parse_json<std::string>::is_valid(m_values["Antenna"]) && parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"StartTime", "Antenna", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  double startTime() const { return parse_json<double>::parse(m_values["StartTime"]); }

  void setStartTime(double startTime)
  {
    m_values.AddMember("StartTime",
                       parse_json<double>::format(startTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string antenna() const { return parse_json<std::string>::parse(m_values["Antenna"]); }

  void setAntenna(const std::string& antenna)
  {
    m_values.AddMember("Antenna",
                       parse_json<std::string>::format(antenna, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetAntennaChange);
} // namespace Cmd
} // namespace Sdx
