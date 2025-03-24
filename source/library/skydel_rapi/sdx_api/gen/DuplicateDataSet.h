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
/// Duplicate an existing data set.
///
/// Name           Type            Description
/// -------------- --------------- ----------------------------------------------------------------------------------
/// System         string          "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// DataSetName    string          The name of the data set to duplicate.
/// NewDataSetName optional string The name of the new duplicate data set. If omitted, a copy name will be generated.
///

class DuplicateDataSet;
typedef std::shared_ptr<DuplicateDataSet> DuplicateDataSetPtr;

class DuplicateDataSet : public CommandBase
{
public:
  inline static const char* const CmdName = "DuplicateDataSet";
  inline static const char* const Documentation =
    "Duplicate an existing data set.\n"
    "\n"
    "Name           Type            Description\n"
    "-------------- --------------- ----------------------------------------------------------------------------------\n"
    "System         string          \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "DataSetName    string          The name of the data set to duplicate.\n"
    "NewDataSetName optional string The name of the new duplicate data set. If omitted, a copy name will be generated.";
  inline static const char* const TargetId = "";

  DuplicateDataSet() : CommandBase(CmdName, TargetId) {}

  DuplicateDataSet(const std::string& system,
                   const std::string& dataSetName,
                   const std::optional<std::string>& newDataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setDataSetName(dataSetName);
    setNewDataSetName(newDataSetName);
  }

  static DuplicateDataSetPtr create(const std::string& system,
                                    const std::string& dataSetName,
                                    const std::optional<std::string>& newDataSetName = {})
  {
    return std::make_shared<DuplicateDataSet>(system, dataSetName, newDataSetName);
  }

  static DuplicateDataSetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<DuplicateDataSet>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::string>::is_valid(m_values["DataSetName"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["NewDataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "DataSetName", "NewDataSetName"};
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

  std::optional<std::string> newDataSetName() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["NewDataSetName"]);
  }

  void setNewDataSetName(const std::optional<std::string>& newDataSetName)
  {
    m_values.AddMember("NewDataSetName",
                       parse_json<std::optional<std::string>>::format(newDataSetName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(DuplicateDataSet);
} // namespace Cmd
} // namespace Sdx
