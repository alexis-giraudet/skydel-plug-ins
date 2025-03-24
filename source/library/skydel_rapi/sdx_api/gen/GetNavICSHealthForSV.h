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
/// Get NavIC S health (Health of S signal)
///
/// Name        Type            Description
/// ----------- ---------------
/// ------------------------------------------------------------------------------------------- SvId        int
/// Satellite SV ID 1..14, or use 0 to apply new value to all satellites. DataSetName optional string Optional name of
/// the data set to use. If no value is provided, the active data set is used.
///

class GetNavICSHealthForSV;
typedef std::shared_ptr<GetNavICSHealthForSV> GetNavICSHealthForSVPtr;

class GetNavICSHealthForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetNavICSHealthForSV";
  inline static const char* const Documentation =
    "Get NavIC S health (Health of S signal)\n"
    "\n"
    "Name        Type            Description\n"
    "----------- --------------- -------------------------------------------------------------------------------------------\n"
    "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"
    "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
  inline static const char* const TargetId = "";

  GetNavICSHealthForSV() : CommandBase(CmdName, TargetId) {}

  GetNavICSHealthForSV(int svId, const std::optional<std::string>& dataSetName = {}) : CommandBase(CmdName, TargetId)
  {

    setSvId(svId);
    setDataSetName(dataSetName);
  }

  static GetNavICSHealthForSVPtr create(int svId, const std::optional<std::string>& dataSetName = {})
  {
    return std::make_shared<GetNavICSHealthForSV>(svId, dataSetName);
  }

  static GetNavICSHealthForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetNavICSHealthForSV>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "DataSetName"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
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
REGISTER_COMMAND_TO_FACTORY(GetNavICSHealthForSV);
} // namespace Cmd
} // namespace Sdx
