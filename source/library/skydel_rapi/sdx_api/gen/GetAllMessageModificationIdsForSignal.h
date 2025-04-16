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
/// Get all the message modification event's IDs for this signal and SV ID.
///
/// Name   Type   Description
/// ------ ------
/// --------------------------------------------------------------------------------------------------------- Signal
/// string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
///                                             "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "B3I",
///                                             "QZSSL1CA", "QZSSL1CB", "QZSSL1S", "NAVICL5", "NAVICS", "SBASL1",
///                                             "SBASL5", "PULSARXL", "PULSARX1" and "PULSARX5"
/// SvId   int    The satellite's SV ID
///

class GetAllMessageModificationIdsForSignal;
typedef std::shared_ptr<GetAllMessageModificationIdsForSignal> GetAllMessageModificationIdsForSignalPtr;

class GetAllMessageModificationIdsForSignal : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAllMessageModificationIdsForSignal";
  inline static const char* const Documentation =
    "Get all the message modification event's IDs for this signal and SV ID.\n"
    "\n"
    "Name   Type   Description\n"
    "------ ------ ---------------------------------------------------------------------------------------------------------\n"
    "Signal string Signal key, accepted values : \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\", \"L2MR\", \"L5\",\n"
    "                                            \"G1\", \"G2\", \"E1\", \"E5a\", \"E5b\", \"B1\", \"B2\", \"B2a\", \"B1C\", \"B3I\",\n"
    "                                            \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1S\", \"NAVICL5\", \"NAVICS\", \"SBASL1\", \"SBASL5\",\n"
    "                                            \"PULSARXL\", \"PULSARX1\" and \"PULSARX5\"\n"
    "SvId   int    The satellite's SV ID";
  inline static const char* const TargetId = "";

  GetAllMessageModificationIdsForSignal() : CommandBase(CmdName, TargetId) {}

  GetAllMessageModificationIdsForSignal(const std::string& signal, int svId) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setSvId(svId);
  }

  static GetAllMessageModificationIdsForSignalPtr create(const std::string& signal, int svId)
  {
    return std::make_shared<GetAllMessageModificationIdsForSignal>(signal, svId);
  }

  static GetAllMessageModificationIdsForSignalPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAllMessageModificationIdsForSignal>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Signal"]) &&
           parse_json<int>::is_valid(m_values["SvId"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Signal", "SvId"};
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
};
REGISTER_COMMAND_TO_FACTORY(GetAllMessageModificationIdsForSignal);
} // namespace Cmd
} // namespace Sdx
