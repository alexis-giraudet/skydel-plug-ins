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
/// Get the GPU associated with a RF output of a modulation target.
///
/// Name   Type   Description
/// ------ ------ -------------------------
/// Output int    Output index (zero based)
/// Id     string Target identifier
///

class GetGpu;
typedef std::shared_ptr<GetGpu> GetGpuPtr;

class GetGpu : public CommandBase
{
public:
  inline static const char* const CmdName = "GetGpu";
  inline static const char* const Documentation = "Get the GPU associated with a RF output of a modulation target.\n"
                                                  "\n"
                                                  "Name   Type   Description\n"
                                                  "------ ------ -------------------------\n"
                                                  "Output int    Output index (zero based)\n"
                                                  "Id     string Target identifier";
  inline static const char* const TargetId = "";

  GetGpu() : CommandBase(CmdName, TargetId) {}

  GetGpu(int output, const std::string& id) : CommandBase(CmdName, TargetId)
  {

    setOutput(output);
    setId(id);
  }

  static GetGpuPtr create(int output, const std::string& id) { return std::make_shared<GetGpu>(output, id); }

  static GetGpuPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetGpu>(ptr); }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<int>::is_valid(m_values["Output"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Output", "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int output() const { return parse_json<int>::parse(m_values["Output"]); }

  void setOutput(int output)
  {
    m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetGpu);
} // namespace Cmd
} // namespace Sdx
