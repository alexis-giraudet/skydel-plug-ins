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
/// Result of GetIntTxTrajectory.
///
/// Name           Type   Description
/// -------------- ------ ---------------------------------------------------------
/// TrajectoryType string Type of the trajectory of the interferences transmitters.
/// Id             string Transmitter unique identifier.
///

class GetIntTxTrajectoryResult;
typedef std::shared_ptr<GetIntTxTrajectoryResult> GetIntTxTrajectoryResultPtr;

class GetIntTxTrajectoryResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIntTxTrajectoryResult";
  inline static const char* const Documentation =
    "Result of GetIntTxTrajectory.\n"
    "\n"
    "Name           Type   Description\n"
    "-------------- ------ ---------------------------------------------------------\n"
    "TrajectoryType string Type of the trajectory of the interferences transmitters.\n"
    "Id             string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  GetIntTxTrajectoryResult() : CommandResult(CmdName, TargetId) {}

  GetIntTxTrajectoryResult(const std::string& trajectoryType, const std::string& id) : CommandResult(CmdName, TargetId)
  {

    setTrajectoryType(trajectoryType);
    setId(id);
  }

  GetIntTxTrajectoryResult(CommandBasePtr relatedCommand, const std::string& trajectoryType, const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setTrajectoryType(trajectoryType);
    setId(id);
  }

  static GetIntTxTrajectoryResultPtr create(const std::string& trajectoryType, const std::string& id)
  {
    return std::make_shared<GetIntTxTrajectoryResult>(trajectoryType, id);
  }

  static GetIntTxTrajectoryResultPtr create(CommandBasePtr relatedCommand,
                                            const std::string& trajectoryType,
                                            const std::string& id)
  {
    return std::make_shared<GetIntTxTrajectoryResult>(relatedCommand, trajectoryType, id);
  }

  static GetIntTxTrajectoryResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxTrajectoryResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["TrajectoryType"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"TrajectoryType", "Id"};
    return names;
  }

  std::string trajectoryType() const { return parse_json<std::string>::parse(m_values["TrajectoryType"]); }

  void setTrajectoryType(const std::string& trajectoryType)
  {
    m_values.AddMember("TrajectoryType",
                       parse_json<std::string>::format(trajectoryType, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIntTxTrajectoryResult);
} // namespace Cmd
} // namespace Sdx
