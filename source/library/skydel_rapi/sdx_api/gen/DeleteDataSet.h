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
/// Delete data set.
///
/// Name        Type   Description
/// ----------- ------ -------------------------------------------------------
/// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// DataSetName string The name of the data set to delete.
///

class DeleteDataSet;
typedef std::shared_ptr<DeleteDataSet> DeleteDataSetPtr;

class DeleteDataSet : public CommandBase
{
public:
  inline static const char* const CmdName = "DeleteDataSet";
  inline static const char* const Documentation =
    "Delete data set.\n"
    "\n"
    "Name        Type   Description\n"
    "----------- ------ -------------------------------------------------------\n"
    "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "DataSetName string The name of the data set to delete.";
  inline static const char* const TargetId = "";

  DeleteDataSet() : CommandBase(CmdName, TargetId) {}

  DeleteDataSet(const std::string& system, const std::string& dataSetName) : CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setDataSetName(dataSetName);
  }

  static DeleteDataSetPtr create(const std::string& system, const std::string& dataSetName)
  {
    return std::make_shared<DeleteDataSet>(system, dataSetName);
  }

  static DeleteDataSetPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<DeleteDataSet>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::string>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "DataSetName"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string dataSetName() const { return parse_json<std::string>::parse(m_values["DataSetName"]); }

  void setDataSetName(const std::string& dataSetName)
  {
    m_values.AddMember("DataSetName",
                       parse_json<std::string>::format(dataSetName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(DeleteDataSet);
} // namespace Cmd
} // namespace Sdx
