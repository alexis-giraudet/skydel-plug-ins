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
/// Get interference transmitter trajectory.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class GetIntTxTrajectory;
typedef std::shared_ptr<GetIntTxTrajectory> GetIntTxTrajectoryPtr;

class GetIntTxTrajectory : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIntTxTrajectory";
  inline static const char* const Documentation = "Get interference transmitter trajectory.\n"
                                                  "\n"
                                                  "Name Type   Description\n"
                                                  "---- ------ ------------------------------\n"
                                                  "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  GetIntTxTrajectory() : CommandBase(CmdName, TargetId) {}

  GetIntTxTrajectory(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetIntTxTrajectoryPtr create(const std::string& id) { return std::make_shared<GetIntTxTrajectory>(id); }

  static GetIntTxTrajectoryPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxTrajectory>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIntTxTrajectory);
} // namespace Cmd
} // namespace Sdx
