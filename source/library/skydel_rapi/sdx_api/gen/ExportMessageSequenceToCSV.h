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
/// Export the signal's message sequence into a csv file.
///
/// Name        Type   Description
/// ----------- ------ -------------------------------------------------------------------------------------------------
/// Signal      string Signal key ("L2C" for example).
/// Path        string The full path to the csv file.
/// Overwriting bool   Overwrites an existing file if set to true, returns an error if set to false and the file exists.
///

class ExportMessageSequenceToCSV;
typedef std::shared_ptr<ExportMessageSequenceToCSV> ExportMessageSequenceToCSVPtr;

class ExportMessageSequenceToCSV : public CommandBase
{
public:
  inline static const char* const CmdName = "ExportMessageSequenceToCSV";
  inline static const char* const Documentation =
    "Export the signal's message sequence into a csv file.\n"
    "\n"
    "Name        Type   Description\n"
    "----------- ------ -------------------------------------------------------------------------------------------------\n"
    "Signal      string Signal key (\"L2C\" for example).\n"
    "Path        string The full path to the csv file.\n"
    "Overwriting bool   Overwrites an existing file if set to true, returns an error if set to false and the file exists.";
  inline static const char* const TargetId = "";

  ExportMessageSequenceToCSV() : CommandBase(CmdName, TargetId) {}

  ExportMessageSequenceToCSV(const std::string& signal, const std::string& path, bool overwriting) :
    CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setPath(path);
    setOverwriting(overwriting);
  }

  static ExportMessageSequenceToCSVPtr create(const std::string& signal, const std::string& path, bool overwriting)
  {
    return std::make_shared<ExportMessageSequenceToCSV>(signal, path, overwriting);
  }

  static ExportMessageSequenceToCSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<ExportMessageSequenceToCSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<std::string>::is_valid(m_values["Path"]) && parse_json<bool>::is_valid(m_values["Overwriting"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Path", "Overwriting"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string path() const { return parse_json<std::string>::parse(m_values["Path"]); }

  void setPath(const std::string& path)
  {
    m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool overwriting() const { return parse_json<bool>::parse(m_values["Overwriting"]); }

  void setOverwriting(bool overwriting)
  {
    m_values.AddMember("Overwriting",
                       parse_json<bool>::format(overwriting, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(ExportMessageSequenceToCSV);
} // namespace Cmd
} // namespace Sdx
