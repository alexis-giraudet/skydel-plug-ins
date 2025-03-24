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
/// Get active data set.
///
/// Name   Type   Description
/// ------ ------ -------------------------------------------------------
/// System string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
///

class GetActiveDataSet;
typedef std::shared_ptr<GetActiveDataSet> GetActiveDataSetPtr;

class GetActiveDataSet : public CommandBase
{
public:
  inline static const char* const CmdName = "GetActiveDataSet";
  inline static const char* const Documentation =
    "Get active data set.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------\n"
    "System string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  GetActiveDataSet() : CommandBase(CmdName, TargetId) {}

  GetActiveDataSet(const std::string& system) : CommandBase(CmdName, TargetId) { setSystem(system); }

  static GetActiveDataSetPtr create(const std::string& system) { return std::make_shared<GetActiveDataSet>(system); }

  static GetActiveDataSetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetActiveDataSet>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetActiveDataSet);
} // namespace Cmd
} // namespace Sdx
