#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get almanac upload interval in seconds. After the initial upload set with command
/// SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.
///
///
///

class GetAlmanacUploadTimeInterval;
typedef std::shared_ptr<GetAlmanacUploadTimeInterval> GetAlmanacUploadTimeIntervalPtr;

class GetAlmanacUploadTimeInterval : public CommandBase
{
public:
  inline static const char* const CmdName = "GetAlmanacUploadTimeInterval";
  inline static const char* const Documentation =
    "Get almanac upload interval in seconds. After the initial upload set with command \n"
    "SetAlmanacInitialUploadTimeOffset, the almanac will automatically update at each interval.";
  inline static const char* const TargetId = "";

  GetAlmanacUploadTimeInterval() : CommandBase(CmdName, TargetId) {}

  static GetAlmanacUploadTimeIntervalPtr create() { return std::make_shared<GetAlmanacUploadTimeInterval>(); }

  static GetAlmanacUploadTimeIntervalPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetAlmanacUploadTimeInterval>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetAlmanacUploadTimeInterval);
} // namespace Cmd
} // namespace Sdx
