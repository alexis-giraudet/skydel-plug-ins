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
/// Get the Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density on the GNSS output (-174
/// dB/Hz). Default offset value is 0. If Gaussian Noise is not enabled on the output, this offset has no effect.
///
/// Name      Type   Description
/// --------- ------ ----------------------------
/// Id        string Target identifier
/// OutputIdx int    RF Output index (zero-based)
///

class GetGaussianNoisePowerDensityOffset;
typedef std::shared_ptr<GetGaussianNoisePowerDensityOffset> GetGaussianNoisePowerDensityOffsetPtr;

class GetGaussianNoisePowerDensityOffset : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGaussianNoisePowerDensityOffset";
  inline static const char* const Documentation =
    "Get the Noise Power Density Offset (dB/Hz) added to the base Gaussian Noise power density on the GNSS output (-174 dB/Hz). Default offset value is 0. If Gaussian Noise is not enabled on the output, this offset has no effect.\n"
    "\n"
    "Name      Type   Description\n"
    "--------- ------ ----------------------------\n"
    "Id        string Target identifier\n"
    "OutputIdx int    RF Output index (zero-based)";
  inline static const char* const TargetId = "";

  GetGaussianNoisePowerDensityOffset() : CommandBase(CmdName, TargetId) {}

  GetGaussianNoisePowerDensityOffset(const std::string& id, int outputIdx) : CommandBase(CmdName, TargetId)
  {

    setId(id);
    setOutputIdx(outputIdx);
  }

  static GetGaussianNoisePowerDensityOffsetPtr create(const std::string& id, int outputIdx)
  {
    return std::make_shared<GetGaussianNoisePowerDensityOffset>(id, outputIdx);
  }

  static GetGaussianNoisePowerDensityOffsetPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGaussianNoisePowerDensityOffset>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::string>::is_valid(m_values["Id"]) &&
           parse_json<int>::is_valid(m_values["OutputIdx"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Id", "OutputIdx"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int outputIdx() const { return parse_json<int>::parse(m_values["OutputIdx"]); }

  void setOutputIdx(int outputIdx)
  {
    m_values.AddMember("OutputIdx",
                       parse_json<int>::format(outputIdx, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGaussianNoisePowerDensityOffset);
} // namespace Cmd
} // namespace Sdx
