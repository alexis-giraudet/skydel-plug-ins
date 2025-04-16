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
/// Get antenna offset and orientation relative to body frame.
/// The origin of the body frame follows the transmitter trajectory.
/// When the body yaw/pitch/roll are zeros, the body X-axis is pointing north
///                          Y-axis is pointing east
///                          Z-axis is pointing down
/// The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and
/// the Roll is rotating arond the X-axis of the body frame.
///
/// Name Type   Description
/// ---- ------ ------------------------------
/// Id   string Transmitter unique identifier.
///

class GetIntTxAntennaOffset;
typedef std::shared_ptr<GetIntTxAntennaOffset> GetIntTxAntennaOffsetPtr;

class GetIntTxAntennaOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIntTxAntennaOffset";
  inline static const char* const Documentation =
    "Get antenna offset and orientation relative to body frame.\n"
    "The origin of the body frame follows the transmitter trajectory.\n"
    "When the body yaw/pitch/roll are zeros, the body X-axis is pointing north\n"
    "                         Y-axis is pointing east\n"
    "                         Z-axis is pointing down\n"
    "The antenna Yaw is rotating around Z-axis. Pitch is rotating around Y-axis and\n"
    "the Roll is rotating arond the X-axis of the body frame.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ------------------------------\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  GetIntTxAntennaOffset() : CommandBase(CmdName, TargetId) {}

  GetIntTxAntennaOffset(const std::string& id) : CommandBase(CmdName, TargetId) { setId(id); }

  static GetIntTxAntennaOffsetPtr create(const std::string& id) { return std::make_shared<GetIntTxAntennaOffset>(id); }

  static GetIntTxAntennaOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxAntennaOffset>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetIntTxAntennaOffset);
} // namespace Cmd
} // namespace Sdx
