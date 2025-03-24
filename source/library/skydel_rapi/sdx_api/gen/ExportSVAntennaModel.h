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
/// Export a space vehicle antenna model in a XML file.
///
/// Name        Type   Description
/// ----------- ------ --------------------------------------------------------------------------
/// AntennaName string SV antenna model name
/// System      string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
/// FilePath    string The antenna model will be exported in this file path.
/// Overwriting bool   Overwrite the old file if true.
///

class ExportSVAntennaModel;
typedef std::shared_ptr<ExportSVAntennaModel> ExportSVAntennaModelPtr;

class ExportSVAntennaModel : public CommandBase
{
public:
  inline static const char* const CmdName = "ExportSVAntennaModel";
  inline static const char* const Documentation =
    "Export a space vehicle antenna model in a XML file.\n"
    "\n"
    "Name        Type   Description\n"
    "----------- ------ --------------------------------------------------------------------------\n"
    "AntennaName string SV antenna model name\n"
    "System      string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
    "FilePath    string The antenna model will be exported in this file path.\n"
    "Overwriting bool   Overwrite the old file if true.";
  inline static const char* const TargetId = "";

  ExportSVAntennaModel() : CommandBase(CmdName, TargetId) {}

  ExportSVAntennaModel(const std::string& antennaName,
                       const std::string& system,
                       const std::string& filePath,
                       bool overwriting) :
    CommandBase(CmdName, TargetId)
  {

    setAntennaName(antennaName);
    setSystem(system);
    setFilePath(filePath);
    setOverwriting(overwriting);
  }

  static ExportSVAntennaModelPtr create(const std::string& antennaName,
                                        const std::string& system,
                                        const std::string& filePath,
                                        bool overwriting)
  {
    return std::make_shared<ExportSVAntennaModel>(antennaName, system, filePath, overwriting);
  }

  static ExportSVAntennaModelPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ExportSVAntennaModel>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["AntennaName"]) &&
           parse_json<std::string>::is_valid(m_values["System"]) &&
           parse_json<std::string>::is_valid(m_values["FilePath"]) &&
           parse_json<bool>::is_valid(m_values["Overwriting"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"AntennaName", "System", "FilePath", "Overwriting"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string antennaName() const { return parse_json<std::string>::parse(m_values["AntennaName"]); }

  void setAntennaName(const std::string& antennaName)
  {
    m_values.AddMember("AntennaName",
                       parse_json<std::string>::format(antennaName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string system() const { return parse_json<std::string>::parse(m_values["System"]); }

  void setSystem(const std::string& system)
  {
    m_values.AddMember("System",
                       parse_json<std::string>::format(system, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string filePath() const { return parse_json<std::string>::parse(m_values["FilePath"]); }

  void setFilePath(const std::string& filePath)
  {
    m_values.AddMember("FilePath",
                       parse_json<std::string>::format(filePath, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool overwriting() const { return parse_json<bool>::parse(m_values["Overwriting"]); }

  void setOverwriting(bool overwriting)
  {
    m_values.AddMember("Overwriting",
                       parse_json<bool>::format(overwriting, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ExportSVAntennaModel);
} // namespace Cmd
} // namespace Sdx
