#pragma once

#include <map>
#include <memory>
#include <string>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetTransmittedPrnForSV.
///
/// Name          Type            Description
/// ------------- --------------- -------------------------------------------------------------------------------
/// SvId          int             Satellite SV ID.
/// SignalPrnDict dict string:int A dictionary of signal prn pairs.
///                               Accepted keys are: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C",
///                                                  "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB",
///                                                  "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S",
///                                                  "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL",
///                                                  "PULSARX1" and "PULSARX5"
///

class GetTransmittedPrnForSVResult;
typedef std::shared_ptr<GetTransmittedPrnForSVResult> GetTransmittedPrnForSVResultPtr;

class GetTransmittedPrnForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetTransmittedPrnForSVResult";
  inline static const char* const Documentation =
    "Result of GetTransmittedPrnForSV.\n"
    "\n"
    "Name          Type            Description\n"
    "------------- --------------- -------------------------------------------------------------------------------\n"
    "SvId          int             Satellite SV ID.\n"
    "SignalPrnDict dict string:int A dictionary of signal prn pairs.\n"
    "                              Accepted keys are: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\",\n"
    "                                                 \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\",\n"
    "                                                 \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\",\n"
    "                                                 \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\",\n"
    "                                                 \"PULSARX1\" and \"PULSARX5\"";
  inline static const char* const TargetId = "";

  GetTransmittedPrnForSVResult() : CommandResult(CmdName, TargetId) {}

  GetTransmittedPrnForSVResult(int svId, const std::map<std::string, int>& signalPrnDict) :
    CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setSignalPrnDict(signalPrnDict);
  }

  GetTransmittedPrnForSVResult(CommandBasePtr relatedCommand,
                               int svId,
                               const std::map<std::string, int>& signalPrnDict) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setSignalPrnDict(signalPrnDict);
  }

  static GetTransmittedPrnForSVResultPtr create(int svId, const std::map<std::string, int>& signalPrnDict)
  {
    return std::make_shared<GetTransmittedPrnForSVResult>(svId, signalPrnDict);
  }

  static GetTransmittedPrnForSVResultPtr create(CommandBasePtr relatedCommand,
                                                int svId,
                                                const std::map<std::string, int>& signalPrnDict)
  {
    return std::make_shared<GetTransmittedPrnForSVResult>(relatedCommand, svId, signalPrnDict);
  }

  static GetTransmittedPrnForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetTransmittedPrnForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<std::map<std::string, int>>::is_valid(m_values["SignalPrnDict"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "SignalPrnDict"};
    return names;
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::map<std::string, int> signalPrnDict() const
  {
    return parse_json<std::map<std::string, int>>::parse(m_values["SignalPrnDict"]);
  }

  void setSignalPrnDict(const std::map<std::string, int>& signalPrnDict)
  {
    m_values.AddMember("SignalPrnDict",
                       parse_json<std::map<std::string, int>>::format(signalPrnDict, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetTransmittedPrnForSVResult);
} // namespace Cmd
} // namespace Sdx
