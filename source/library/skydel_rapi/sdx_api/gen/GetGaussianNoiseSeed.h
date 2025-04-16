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
/// Get the seed used to generate the Gaussian Noise. Gaussian Noise must be enabled on the output. It is optional to
/// set the seed of an output. By default, the seed value used is the index of the output.
///
/// Name      Type   Description
/// --------- ------ -----------------------------
/// Id        string Target identifier.
/// OutputIdx int    RF Output index (zero-based).
///

class GetGaussianNoiseSeed;
typedef std::shared_ptr<GetGaussianNoiseSeed> GetGaussianNoiseSeedPtr;

class GetGaussianNoiseSeed : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGaussianNoiseSeed";
  inline static const char* const Documentation =
    "Get the seed used to generate the Gaussian Noise. Gaussian Noise must be enabled on the output. It is optional to set the seed of an output. By default, the seed value used is the index of the output.\n"
    "\n"
    "Name      Type   Description\n"
    "--------- ------ -----------------------------\n"
    "Id        string Target identifier.\n"
    "OutputIdx int    RF Output index (zero-based).";
  inline static const char* const TargetId = "";

  GetGaussianNoiseSeed() : CommandBase(CmdName, TargetId) {}

  GetGaussianNoiseSeed(const std::string& id, int outputIdx) : CommandBase(CmdName, TargetId)
  {

    setId(id);
    setOutputIdx(outputIdx);
  }

  static GetGaussianNoiseSeedPtr create(const std::string& id, int outputIdx)
  {
    return std::make_shared<GetGaussianNoiseSeed>(id, outputIdx);
  }

  static GetGaussianNoiseSeedPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetGaussianNoiseSeed>(ptr);
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
REGISTER_COMMAND_TO_FACTORY(GetGaussianNoiseSeed);
} // namespace Cmd
} // namespace Sdx
