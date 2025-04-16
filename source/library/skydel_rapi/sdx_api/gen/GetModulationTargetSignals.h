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
/// Get the signals for the specified target and output index.
/// Skydel tries to keep the sampling rate as low as possible,
/// but it is possible to set constaints with MinRate and MaxRate.
///
/// Name   Type   Description
/// ------ ------ -------------------------
/// Output int    Output index (zero based)
/// Id     string Target identifier
///

class GetModulationTargetSignals;
typedef std::shared_ptr<GetModulationTargetSignals> GetModulationTargetSignalsPtr;

class GetModulationTargetSignals : public CommandBase
{
public:
  inline static const char* const CmdName = "GetModulationTargetSignals";
  inline static const char* const Documentation = "Get the signals for the specified target and output index.\n"
                                                  "Skydel tries to keep the sampling rate as low as possible,\n"
                                                  "but it is possible to set constaints with MinRate and MaxRate.\n"
                                                  "\n"
                                                  "Name   Type   Description\n"
                                                  "------ ------ -------------------------\n"
                                                  "Output int    Output index (zero based)\n"
                                                  "Id     string Target identifier";
  inline static const char* const TargetId = "";

  GetModulationTargetSignals() : CommandBase(CmdName, TargetId) {}

  GetModulationTargetSignals(int output, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setOutput(output);
    setId(id);
  }

  static GetModulationTargetSignalsPtr create(int output, const std::string& id)
  {
    return std::make_shared<GetModulationTargetSignals>(output, id);
  }

  static GetModulationTargetSignalsPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetModulationTargetSignals>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Output"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Output", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int output() const { return parse_json<int>::parse(m_values["Output"]); }

  void setOutput(int output)
  {
    m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetModulationTargetSignals);
} // namespace Cmd
} // namespace Sdx
