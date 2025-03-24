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
/// Result of GetWFElement.
///
/// Name             Type   Description
/// ---------------- ------
/// ------------------------------------------------------------------------------------------------- Element int
/// One-based index of the element. Value -1 adds a new element at the end of the list. Enabled          bool   If True,
/// this antenna element will be simulated. AntennaModelName string Antenna Model name for this element. Antenna models
/// can be defined in Vehicle Antenna Model menu.
///

class GetWFElementResult;
typedef std::shared_ptr<GetWFElementResult> GetWFElementResultPtr;

class GetWFElementResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetWFElementResult";
  inline static const char* const Documentation =
    "Result of GetWFElement.\n"
    "\n"
    "Name             Type   Description\n"
    "---------------- ------ -------------------------------------------------------------------------------------------------\n"
    "Element          int    One-based index of the element. Value -1 adds a new element at the end of the list.\n"
    "Enabled          bool   If True, this antenna element will be simulated.\n"
    "AntennaModelName string Antenna Model name for this element. Antenna models can be defined in Vehicle Antenna Model menu.";
  inline static const char* const TargetId = "";

  GetWFElementResult() : CommandResult(CmdName, TargetId) {}

  GetWFElementResult(int element, bool enabled, const std::string& antennaModelName) : CommandResult(CmdName, TargetId)
  {

    setElement(element);
    setEnabled(enabled);
    setAntennaModelName(antennaModelName);
  }

  GetWFElementResult(CommandBasePtr relatedCommand, int element, bool enabled, const std::string& antennaModelName) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setElement(element);
    setEnabled(enabled);
    setAntennaModelName(antennaModelName);
  }

  static GetWFElementResultPtr create(int element, bool enabled, const std::string& antennaModelName)
  {
    return std::make_shared<GetWFElementResult>(element, enabled, antennaModelName);
  }

  static GetWFElementResultPtr create(CommandBasePtr relatedCommand,
                                      int element,
                                      bool enabled,
                                      const std::string& antennaModelName)
  {
    return std::make_shared<GetWFElementResult>(relatedCommand, element, enabled, antennaModelName);
  }

  static GetWFElementResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetWFElementResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Element"]) &&
           parse_json<bool>::is_valid(m_values["Enabled"]) &&
           parse_json<std::string>::is_valid(m_values["AntennaModelName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Element", "Enabled", "AntennaModelName"};
    return names;
  }

  int element() const { return parse_json<int>::parse(m_values["Element"]); }

  void setElement(int element)
  {
    m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool enabled() const { return parse_json<bool>::parse(m_values["Enabled"]); }

  void setEnabled(bool enabled)
  {
    m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string antennaModelName() const { return parse_json<std::string>::parse(m_values["AntennaModelName"]); }

  void setAntennaModelName(const std::string& antennaModelName)
  {
    m_values.AddMember("AntennaModelName",
                       parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetWFElementResult);
} // namespace Cmd
} // namespace Sdx
