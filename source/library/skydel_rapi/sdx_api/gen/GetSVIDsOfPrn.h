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
/// Mapping PRN to the corresponding SV ID. Get a list of SV IDs based on a specific signal. Accepted signal keys:
/// "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L5", "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
/// "B1", "B2", "B2a", "B1C", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5",
/// "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and "PULSARX5"
///
/// Name   Type   Description
/// ------ ------ ----------------------------------------------------------------------
/// Signal string Signal key - see GetSVIDsOfPrn command description for possible values
/// Prn    int    Satellite PRN number
///

class GetSVIDsOfPrn;
typedef std::shared_ptr<GetSVIDsOfPrn> GetSVIDsOfPrnPtr;

class GetSVIDsOfPrn : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSVIDsOfPrn";
  inline static const char* const Documentation =
    "Mapping PRN to the corresponding SV ID. Get a list of SV IDs based on a specific signal. Accepted signal keys: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ----------------------------------------------------------------------\n"
    "Signal string Signal key - see GetSVIDsOfPrn command description for possible values\n"
    "Prn    int    Satellite PRN number";
  inline static const char* const TargetId = "";

  GetSVIDsOfPrn() : CommandBase(CmdName, TargetId) {}

  GetSVIDsOfPrn(const std::string& signal, int prn) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setPrn(prn);
  }

  static GetSVIDsOfPrnPtr create(const std::string& signal, int prn)
  {
    return std::make_shared<GetSVIDsOfPrn>(signal, prn);
  }

  static GetSVIDsOfPrnPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetSVIDsOfPrn>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<int>::is_valid(m_values["Prn"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "Prn"};
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

  int prn() const { return parse_json<int>::parse(m_values["Prn"]); }

  void setPrn(int prn)
  {
    m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSVIDsOfPrn);
} // namespace Cmd
} // namespace Sdx
