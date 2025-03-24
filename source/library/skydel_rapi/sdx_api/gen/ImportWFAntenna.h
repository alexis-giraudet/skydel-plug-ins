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
/// Import Wavefront Antenna settings from an XML file.
///
/// Name     Type   Description
/// -------- ------ -----------------------------------------
/// FilePath string File path for Wavefront Antenna settings.
///

class ImportWFAntenna;
typedef std::shared_ptr<ImportWFAntenna> ImportWFAntennaPtr;

class ImportWFAntenna : public CommandBase
{
public:
  inline static const char* const CmdName = "ImportWFAntenna";
  inline static const char* const Documentation = "Import Wavefront Antenna settings from an XML file.\n"
                                                  "\n"
                                                  "Name     Type   Description\n"
                                                  "-------- ------ -----------------------------------------\n"
                                                  "FilePath string File path for Wavefront Antenna settings.";
  inline static const char* const TargetId = "";

  ImportWFAntenna() : CommandBase(CmdName, TargetId) {}

  ImportWFAntenna(const std::string& filePath) : CommandBase(CmdName, TargetId) { setFilePath(filePath); }

  static ImportWFAntennaPtr create(const std::string& filePath) { return std::make_shared<ImportWFAntenna>(filePath); }

  static ImportWFAntennaPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<ImportWFAntenna>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["FilePath"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"FilePath"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string filePath() const { return parse_json<std::string>::parse(m_values["FilePath"]); }

  void setFilePath(const std::string& filePath)
  {
    m_values.AddMember("FilePath",
                       parse_json<std::string>::format(filePath, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ImportWFAntenna);
} // namespace Cmd
} // namespace Sdx
