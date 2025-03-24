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
/// Result of GetIntTxVehicleType.
///
/// Name Type   Description
/// ---- ------ -----------------------------------------------------------
/// Type string Vehicle type ("Ground / Water" or "Airborne / Spaceborne").
/// Id   string Transmitter unique identifier.
///

class GetIntTxVehicleTypeResult;
typedef std::shared_ptr<GetIntTxVehicleTypeResult> GetIntTxVehicleTypeResultPtr;

class GetIntTxVehicleTypeResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetIntTxVehicleTypeResult";
  inline static const char* const Documentation =
    "Result of GetIntTxVehicleType.\n"
    "\n"
    "Name Type   Description\n"
    "---- ------ -----------------------------------------------------------\n"
    "Type string Vehicle type (\"Ground / Water\" or \"Airborne / Spaceborne\").\n"
    "Id   string Transmitter unique identifier.";
  inline static const char* const TargetId = "";

  GetIntTxVehicleTypeResult() : CommandResult(CmdName, TargetId) {}

  GetIntTxVehicleTypeResult(const std::string& type, const std::string& id) : CommandResult(CmdName, TargetId)
  {

    setType(type);
    setId(id);
  }

  GetIntTxVehicleTypeResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setType(type);
    setId(id);
  }

  static GetIntTxVehicleTypeResultPtr create(const std::string& type, const std::string& id)
  {
    return std::make_shared<GetIntTxVehicleTypeResult>(type, id);
  }

  static GetIntTxVehicleTypeResultPtr create(CommandBasePtr relatedCommand,
                                             const std::string& type,
                                             const std::string& id)
  {
    return std::make_shared<GetIntTxVehicleTypeResult>(relatedCommand, type, id);
  }

  static GetIntTxVehicleTypeResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIntTxVehicleTypeResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Type"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Type", "Id"};
    return names;
  }

  std::string type() const { return parse_json<std::string>::parse(m_values["Type"]); }

  void setType(const std::string& type)
  {
    m_values.AddMember("Type", parse_json<std::string>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIntTxVehicleTypeResult);
} // namespace Cmd
} // namespace Sdx
