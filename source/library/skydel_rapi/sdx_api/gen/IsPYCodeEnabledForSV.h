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
/// Tells if P(Y)-Code is enabled for the specified satellite.
///
/// Name   Type   Description
/// ------ ------ -----------------------------------------------
/// Signal string Accepted signal keys: "L1P", "L2P"
/// SvId   int    The satellite's SV ID 1..32 (use 0 for all SVs)
///

class IsPYCodeEnabledForSV;
typedef std::shared_ptr<IsPYCodeEnabledForSV> IsPYCodeEnabledForSVPtr;

class IsPYCodeEnabledForSV : public CommandBase
{
public:
  inline static const char* const CmdName = "IsPYCodeEnabledForSV";
  inline static const char* const Documentation = "Tells if P(Y)-Code is enabled for the specified satellite.\n"
                                                  "\n"
                                                  "Name   Type   Description\n"
                                                  "------ ------ -----------------------------------------------\n"
                                                  "Signal string Accepted signal keys: \"L1P\", \"L2P\"\n"
                                                  "SvId   int    The satellite's SV ID 1..32 (use 0 for all SVs)";
  inline static const char* const TargetId = "";

  IsPYCodeEnabledForSV() : CommandBase(CmdName, TargetId) {}

  IsPYCodeEnabledForSV(const std::string& signal, int svId) : CommandBase(CmdName, TargetId)
  {

    setSignal(signal);
    setSvId(svId);
  }

  static IsPYCodeEnabledForSVPtr create(const std::string& signal, int svId)
  {
    return std::make_shared<IsPYCodeEnabledForSV>(signal, svId);
  }

  static IsPYCodeEnabledForSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<IsPYCodeEnabledForSV>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(IsPYCodeEnabledForSV);
} // namespace Cmd
} // namespace Sdx
