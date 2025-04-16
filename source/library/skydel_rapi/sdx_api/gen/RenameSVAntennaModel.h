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
/// Rename a space vehicle antenna model.
///
/// Name    Type   Description
/// ------- ------ --------------------------------------------------------------------------
/// Name    string Reference space vehicle antenna model name
/// NewName string New space vehicle antenna model name
/// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
///

class RenameSVAntennaModel;
typedef std::shared_ptr<RenameSVAntennaModel> RenameSVAntennaModelPtr;

class RenameSVAntennaModel : public CommandBase
{
public:
  inline static const char* const CmdName = "RenameSVAntennaModel";
  inline static const char* const Documentation =
    "Rename a space vehicle antenna model.\n"
    "\n"
    "Name    Type   Description\n"
    "------- ------ --------------------------------------------------------------------------\n"
    "Name    string Reference space vehicle antenna model name\n"
    "NewName string New space vehicle antenna model name\n"
    "System  string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"";
  inline static const char* const TargetId = "";

  RenameSVAntennaModel() : CommandBase(CmdName, TargetId) {}

  RenameSVAntennaModel(const std::string& name, const std::string& newName, const std::string& system) :
    CommandBase(CmdName, TargetId)
  {

    setName(name);
    setNewName(newName);
    setSystem(system);
  }

  static RenameSVAntennaModelPtr create(const std::string& name, const std::string& newName, const std::string& system)
  {
    return std::make_shared<RenameSVAntennaModel>(name, newName, system);
  }

  static RenameSVAntennaModelPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<RenameSVAntennaModel>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Name"]) &&
           parse_json<std::string>::is_valid(m_values["NewName"]) &&
           parse_json<std::string>::is_valid(m_values["System"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Name", "NewName", "System"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string name() const { return parse_json<std::string>::parse(m_values["Name"]); }

  void setName(const std::string& name)
  {
    m_values.AddMember("Name", parse_json<std::string>::format(name, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string newName() const { return parse_json<std::string>::parse(m_values["NewName"]); }

  void setNewName(const std::string& newName)
  {
    m_values.AddMember("NewName",
                       parse_json<std::string>::format(newName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(RenameSVAntennaModel);
} // namespace Cmd
} // namespace Sdx
