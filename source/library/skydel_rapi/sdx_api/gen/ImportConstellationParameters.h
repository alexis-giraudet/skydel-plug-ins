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
/// Import navigation message file for the specified constellation. This could be Rinex, SEM or YUMA file for GPS. Only
/// Rinex for the others.
///
/// Name        Type            Description
/// ----------- ---------------
/// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// System      string          "GPS", "GLONASS", "Galileo", "SBAS", "BeiDou", "QZSS", "NavIC" or "PULSAR"
/// Path        string          File path
/// Rollover    optional int    Rollover for file types that does not precise it (YUMA, SEM). Default value is the
/// current rollover. DataSetName optional string Name of the data set to import. This parameter is optional, the
/// default value will be the name of the imported file. Constellations that support this parameter are  "GPS",
/// "Galileo", "BeiDou", "QZSS" and "NavIC"
///

class ImportConstellationParameters;
typedef std::shared_ptr<ImportConstellationParameters> ImportConstellationParametersPtr;

class ImportConstellationParameters : public CommandBase
{
public:
  inline static const char* const CmdName = "ImportConstellationParameters";
  inline static const char* const Documentation =
    "Import navigation message file for the specified constellation. This could be Rinex, SEM or YUMA file for GPS. Only Rinex for the others.\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "System      string          \"GPS\", \"GLONASS\", \"Galileo\", \"SBAS\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "Path        string          File path\n"
    "Rollover    optional int    Rollover for file types that does not precise it (YUMA, SEM). Default value is the current rollover.\n"
    "DataSetName optional string Name of the data set to import. This parameter is optional, the default value will be the name of the imported file. Constellations that support this parameter are  \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\" and \"NavIC\"";
  inline static const char* const TargetId = "";

  ImportConstellationParameters() : CommandBase(CmdName, TargetId) {}

  ImportConstellationParameters(const std::string& system,
                                const std::string& path,
                                const std::optional<int>& rollover = {},
                                const std::optional<std::string>& dataSetName = {}) :
    CommandBase(CmdName, TargetId)
  {

    setSystem(system);
    setPath(path);
    setRollover(rollover);
    setDataSetName(dataSetName);
  }

  static ImportConstellationParametersPtr create(const std::string& system,
                                                 const std::string& path,
                                                 const std::optional<int>& rollover = {},
                                                 const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<ImportConstellationParameters>(system, path, rollover, dataSetName);
  }

  static ImportConstellationParametersPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ImportConstellationParameters>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::string>::is_valid(m_values["Path"]) &&
           parse_json<std::optional<int>>::is_valid(m_values["Rollover"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"System", "Path", "Rollover", "DataSetName"};
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

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::optional<int> rollover() const { return parse_json<std::optional<int>>::parse(m_values["Rollover"]); }

  void setRollover(const std::optional<int>& rollover)
  {
    m_values.AddMember("Rollover",
                       parse_json<std::optional<int>>::format(rollover, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::optional<std::string> dataSetName() const
  {
    return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
  }

  void setDataSetName(const std::optional<std::string>& dataSetName)
  {
    m_values.AddMember("DataSetName",
                       parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ImportConstellationParameters);
} // namespace Cmd
} // namespace Sdx
