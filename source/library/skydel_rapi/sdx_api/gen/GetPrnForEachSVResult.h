#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetPrnForEachSV.
///
/// Name   Type      Description
/// ------ ---------
/// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// Signal string    Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C", "B2a", "B3I",
/// "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
/// "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1", "PULSARX5" Prn    array int PRN value to set for each
/// satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)
///

class GetPrnForEachSVResult;
typedef std::shared_ptr<GetPrnForEachSVResult> GetPrnForEachSVResultPtr;

class GetPrnForEachSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetPrnForEachSVResult";
  inline static const char* const Documentation =
    "Result of GetPrnForEachSV.\n"
    "\n"
    "Name   Type      Description\n"
    "------ --------- -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "Signal string    Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
    "Prn    array int PRN value to set for each satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)";
  inline static const char* const TargetId = "";

  GetPrnForEachSVResult() : CommandResult(CmdName, TargetId) {}

  GetPrnForEachSVResult(const std::string& signal, const std::vector<int>& prn) : CommandResult(CmdName, TargetId)
  {

    setSignal(signal);
    setPrn(prn);
  }

  GetPrnForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& prn) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSignal(signal);
    setPrn(prn);
  }

  static GetPrnForEachSVResultPtr create(const std::string& signal, const std::vector<int>& prn)
  {
    return std::make_shared<GetPrnForEachSVResult>(signal, prn);
  }

  static GetPrnForEachSVResultPtr create(CommandBasePtr relatedCommand,
                                         const std::string& signal,
                                         const std::vector<int>& prn)
  {
    return std::make_shared<GetPrnForEachSVResult>(relatedCommand, signal, prn);
  }

  static GetPrnForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetPrnForEachSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<std::vector<int>>::is_valid(m_values["Prn"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Prn"};
    return names;
  }

  std::string signal() const { return parse_json<std::string>::parse(m_values["Signal"]); }

  void setSignal(const std::string& signal)
  {
    m_values.AddMember("Signal",
                       parse_json<std::string>::format(signal, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::vector<int> prn() const { return parse_json<std::vector<int>>::parse(m_values["Prn"]); }

  void setPrn(const std::vector<int>& prn)
  {
    m_values.AddMember("Prn",
                       parse_json<std::vector<int>>::format(prn, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetPrnForEachSVResult);
} // namespace Cmd
} // namespace Sdx
