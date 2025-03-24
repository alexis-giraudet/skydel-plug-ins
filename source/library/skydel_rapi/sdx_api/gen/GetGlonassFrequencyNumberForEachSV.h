#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get GLONASS frequency number for all satellites. Return values range from -7 to 13. Value -8 is an invalid value, it
/// indicates that the almanac for the satellite is invalid.
///
///
///

class GetGlonassFrequencyNumberForEachSV;
typedef std::shared_ptr<GetGlonassFrequencyNumberForEachSV> GetGlonassFrequencyNumberForEachSVPtr;

class GetGlonassFrequencyNumberForEachSV : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGlonassFrequencyNumberForEachSV";
  inline static const char* const Documentation =
    "Get GLONASS frequency number for all satellites. Return values range from -7 to 13. Value -8 is an invalid value, it indicates that the almanac for the satellite is invalid.";
  inline static const char* const TargetId = "";

  GetGlonassFrequencyNumberForEachSV() : CommandBase(CmdName, TargetId) {}

  static GetGlonassFrequencyNumberForEachSVPtr create()
  {
    return std::make_shared<GetGlonassFrequencyNumberForEachSV>();
  }

  static GetGlonassFrequencyNumberForEachSVPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGlonassFrequencyNumberForEachSV>(ptr);
  }

  virtual bool isValid() const override { return m_values.IsObject(); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }
};
REGISTER_COMMAND_TO_FACTORY(GetGlonassFrequencyNumberForEachSV);
} // namespace Cmd
} // namespace Sdx
