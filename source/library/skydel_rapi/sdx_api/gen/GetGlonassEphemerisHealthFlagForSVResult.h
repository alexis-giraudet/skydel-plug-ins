#pragma once

#include <memory>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetGlonassEphemerisHealthFlagForSV.
///
/// Name   Type Description
/// ------ ---- --------------------------------------
/// SvId   int  The satellite's SV ID 1..24
/// Health bool Status, false = OK, true = Malfunction
///

class GetGlonassEphemerisHealthFlagForSVResult;
typedef std::shared_ptr<GetGlonassEphemerisHealthFlagForSVResult> GetGlonassEphemerisHealthFlagForSVResultPtr;

class GetGlonassEphemerisHealthFlagForSVResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetGlonassEphemerisHealthFlagForSVResult";
  inline static const char* const Documentation = "Result of GetGlonassEphemerisHealthFlagForSV.\n"
                                                  "\n"
                                                  "Name   Type Description\n"
                                                  "------ ---- --------------------------------------\n"
                                                  "SvId   int  The satellite's SV ID 1..24\n"
                                                  "Health bool Status, false = OK, true = Malfunction";
  inline static const char* const TargetId = "";

  GetGlonassEphemerisHealthFlagForSVResult() : CommandResult(CmdName, TargetId) {}

  GetGlonassEphemerisHealthFlagForSVResult(int svId, bool health) : CommandResult(CmdName, TargetId)
  {

    setSvId(svId);
    setHealth(health);
  }

  GetGlonassEphemerisHealthFlagForSVResult(CommandBasePtr relatedCommand, int svId, bool health) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSvId(svId);
    setHealth(health);
  }

  static GetGlonassEphemerisHealthFlagForSVResultPtr create(int svId, bool health)
  {
    return std::make_shared<GetGlonassEphemerisHealthFlagForSVResult>(svId, health);
  }

  static GetGlonassEphemerisHealthFlagForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health)
  {
    return std::make_shared<GetGlonassEphemerisHealthFlagForSVResult>(relatedCommand, svId, health);
  }

  static GetGlonassEphemerisHealthFlagForSVResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGlonassEphemerisHealthFlagForSVResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["SvId"]) &&
           parse_json<bool>::is_valid(m_values["Health"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SvId", "Health"};
    return names;
  }

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool health() const { return parse_json<bool>::parse(m_values["Health"]); }

  void setHealth(bool health)
  {
    m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGlonassEphemerisHealthFlagForSVResult);
} // namespace Cmd
} // namespace Sdx
