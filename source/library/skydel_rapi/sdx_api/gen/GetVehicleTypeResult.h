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
/// Result of GetVehicleType.
///
/// Name Type   Description
/// ---- ------ ----------------------------------------------------------
/// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne")
///

class GetVehicleTypeResult;
typedef std::shared_ptr<GetVehicleTypeResult> GetVehicleTypeResultPtr;

class GetVehicleTypeResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetVehicleTypeResult";
  inline static const char* const Documentation =
    "Result of GetVehicleType.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ ----------------------------------------------------------\n"
    "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\")";
  inline static const char* const TargetId = "";

  GetVehicleTypeResult() : CommandResult(CmdName, TargetId) {}

  GetVehicleTypeResult(const std::string& type) : CommandResult(CmdName, TargetId) { setType(type); }

  GetVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setType(type);
  }

  static GetVehicleTypeResultPtr create(const std::string& type)
  {
    return std::make_shared<GetVehicleTypeResult>(type);
  }

  static GetVehicleTypeResultPtr create(CommandBasePtr relatedCommand, const std::string& type)
  {
    return std::make_shared<GetVehicleTypeResult>(relatedCommand, type);
  }

  static GetVehicleTypeResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetVehicleTypeResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Type"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type"};
    return names;
  }

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetVehicleTypeResult);
} // namespace Cmd
} // namespace Sdx
