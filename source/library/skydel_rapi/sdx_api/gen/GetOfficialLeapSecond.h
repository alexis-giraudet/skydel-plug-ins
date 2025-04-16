#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"
#include "date_time.h"

namespace Sdx
{
namespace Cmd
{
///
/// Returns the official leap second for a given date
///
/// Name Type     Description
/// ---- -------- ------------------------------
/// Date datetime A date expressed in UTC format
///

class GetOfficialLeapSecond;
typedef std::shared_ptr<GetOfficialLeapSecond> GetOfficialLeapSecondPtr;

class GetOfficialLeapSecond : public CommandBase
{
public:
  inline static const char* const CmdName = "GetOfficialLeapSecond";
  inline static const char* const Documentation = "Returns the official leap second for a given date\n"
                                                  "\n"
                                                  "Name Type     Description\n"
                                                  "---- -------- ------------------------------\n"
                                                  "Date datetime A date expressed in UTC format";
  inline static const char* const TargetId = "";

  GetOfficialLeapSecond() : CommandBase(CmdName, TargetId) {}

  GetOfficialLeapSecond(const Sdx::DateTime& date) : CommandBase(CmdName, TargetId) { setDate(date); }

  static GetOfficialLeapSecondPtr create(const Sdx::DateTime& date)
  {
    return std::make_shared<GetOfficialLeapSecond>(date);
  }

  static GetOfficialLeapSecondPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetOfficialLeapSecond>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<Sdx::DateTime>::is_valid(m_values["Date"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Date"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING; }

  Sdx::DateTime date() const { return parse_json<Sdx::DateTime>::parse(m_values["Date"]); }

  void setDate(const Sdx::DateTime& date)
  {
    m_values.AddMember("Date",
                       parse_json<Sdx::DateTime>::format(date, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetOfficialLeapSecond);
} // namespace Cmd
} // namespace Sdx
