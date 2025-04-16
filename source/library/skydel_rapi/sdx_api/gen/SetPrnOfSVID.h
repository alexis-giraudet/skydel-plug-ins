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
/// Set the PRN transmitted by the SV ID for this signal.
///
/// Name   Type   Description
/// ------ ------
/// -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/// Signal string Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C", "B2a", "B3I",
/// "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
/// "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1", "PULSARX5" SvId   int    Satellite SV ID. Prn    int    PRN
/// number.
///

class SetPrnOfSVID;
typedef std::shared_ptr<SetPrnOfSVID> SetPrnOfSVIDPtr;

class SetPrnOfSVID : public CommandBase
{
public:
  inline static const char* const CmdName = "SetPrnOfSVID";
  inline static const char* const Documentation =
    "Set the PRN transmitted by the SV ID for this signal.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
    "Signal string Accepted signal keys: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\", \"PULSARX5\"\n"
    "SvId   int    Satellite SV ID.\n"
    "Prn    int    PRN number.";
  inline static const char* const TargetId = "";

  SetPrnOfSVID() : CommandBase(CmdName, TargetId) {}

  SetPrnOfSVID(const std::string& signal, int svId, int prn) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setSvId(svId);
    setPrn(prn);
  }

  static SetPrnOfSVIDPtr create(const std::string& signal, int svId, int prn)
  {
    return std::make_shared<SetPrnOfSVID>(signal, svId, prn);
  }

  static SetPrnOfSVIDPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<SetPrnOfSVID>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<int>::is_valid(m_values["Prn"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "SvId", "Prn"};
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

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int prn() const { return parse_json<int>::parse(m_values["Prn"]); }

  void setPrn(int prn)
  {
    m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetPrnOfSVID);
} // namespace Cmd
} // namespace Sdx
