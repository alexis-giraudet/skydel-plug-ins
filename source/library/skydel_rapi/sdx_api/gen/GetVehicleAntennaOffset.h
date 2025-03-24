#pragma once

#include <memory>
#include <optional>
#include <string>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the vehicle antenna offset infos. If no name is specified, the default vehicle antenna is get.
///
/// Name Type            Description
/// ---- --------------- ---------------------------
/// Name optional string Unique vehicle antenna name
///

class GetVehicleAntennaOffset;
typedef std::shared_ptr<GetVehicleAntennaOffset> GetVehicleAntennaOffsetPtr;

class GetVehicleAntennaOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetVehicleAntennaOffset";
  inline static const char* const Documentation =
    "Get the vehicle antenna offset infos. If no name is specified, the default vehicle antenna is get.\n"
    "\n"
    "Name Type            Description\n"
    "---- --------------- ---------------------------\n"
    "Name optional string Unique vehicle antenna name";
  inline static const char* const TargetId = "";

  GetVehicleAntennaOffset(const std::optional<std::string>& name = {}) : CommandBase(CmdName, TargetId)
  {

    setName(name);
  }

  static GetVehicleAntennaOffsetPtr create(const std::optional<std::string>& name = {})
  {
    return std::make_shared<GetVehicleAntennaOffset>(name);
  }

  static GetVehicleAntennaOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleAntennaOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::optional<std::string>>::is_valid(m_values["Name"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Name"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::optional<std::string> name() const { return parse_json<std::optional<std::string>>::parse(m_values["Name"]); }

  void setName(const std::optional<std::string>& name)
  {
    m_values.AddMember("Name",
                       parse_json<std::optional<std::string>>::format(name, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleAntennaOffset);
} // namespace Cmd
} // namespace Sdx
