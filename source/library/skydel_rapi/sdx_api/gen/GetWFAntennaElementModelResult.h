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
/// Result of GetWFAntennaElementModel.
///
/// Name             Type   Description
/// ---------------- ------
/// ----------------------------------------------------------------------------------------------------
/// AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle
/// antenna model. Element          int    One-based index for element in antenna.
///

class GetWFAntennaElementModelResult;
typedef std::shared_ptr<GetWFAntennaElementModelResult> GetWFAntennaElementModelResultPtr;

class GetWFAntennaElementModelResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetWFAntennaElementModelResult";
  inline static const char* const Documentation =
    "Result of GetWFAntennaElementModel.\n"
    "\n"
    "Name             Type   Description\n"
    "---------------- ------ ----------------------------------------------------------------------------------------------------\n"
    "AntennaModelName string Antenna Model name to set for this element. Antenna models must be defined in vehicle antenna model.\n"
    "Element          int    One-based index for element in antenna.";
  inline static const char* const TargetId = "";

  GetWFAntennaElementModelResult() : CommandResult(CmdName, TargetId) {}

  GetWFAntennaElementModelResult(const std::string& antennaModelName, int element) : CommandResult(CmdName, TargetId)
  {

    setAntennaModelName(antennaModelName);
    setElement(element);
  }

  GetWFAntennaElementModelResult(CommandBasePtr relatedCommand, const std::string& antennaModelName, int element) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setAntennaModelName(antennaModelName);
    setElement(element);
  }

  static GetWFAntennaElementModelResultPtr create(const std::string& antennaModelName, int element)
  {
    return std::make_shared<GetWFAntennaElementModelResult>(antennaModelName, element);
  }

  static GetWFAntennaElementModelResultPtr create(CommandBasePtr relatedCommand,
                                                  const std::string& antennaModelName,
                                                  int element)
  {
    return std::make_shared<GetWFAntennaElementModelResult>(relatedCommand, antennaModelName, element);
  }

  static GetWFAntennaElementModelResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetWFAntennaElementModelResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["AntennaModelName"]) &&
           parse_json<int>::is_valid(m_values["Element"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"AntennaModelName", "Element"};
    return names;
  }

  std::string antennaModelName() const { return parse_json<std::string>::parse(m_values["AntennaModelName"]); }

  void setAntennaModelName(const std::string& antennaModelName)
  {
    m_values.AddMember("AntennaModelName",
                       parse_json<std::string>::format(antennaModelName, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int element() const { return parse_json<int>::parse(m_values["Element"]); }

  void setElement(int element)
  {
    m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetWFAntennaElementModelResult);
} // namespace Cmd
} // namespace Sdx
