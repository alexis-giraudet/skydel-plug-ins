#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the GPS ionospheric Alpha coefficient
/// Alpha 0 is in seconds
/// Alpha 1 is in seconds/semicircle
/// Alpha 2 is in seconds/semicircle^2
/// Alpha 3 is in seconds/semicircle^3
///
/// Name  Type Description
/// ----- ---- ------------------------
/// Index int  Coefficient index [0..3]
///

class GetIonoAlpha;
typedef std::shared_ptr<GetIonoAlpha> GetIonoAlphaPtr;

class GetIonoAlpha : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIonoAlpha";
  inline static const char* const Documentation = "Get the GPS ionospheric Alpha coefficient\n"
                                                  "Alpha 0 is in seconds\n"
                                                  "Alpha 1 is in seconds/semicircle\n"
                                                  "Alpha 2 is in seconds/semicircle^2\n"
                                                  "Alpha 3 is in seconds/semicircle^3\n"
                                                  "\n"
                                                  "Name  Type Description\n"
                                                  "----- ---- ------------------------\n"
                                                  "Index int  Coefficient index [0..3]";
  inline static const char* const TargetId = "";

  GetIonoAlpha() : CommandBase(CmdName, TargetId) {}

  GetIonoAlpha(int index) : CommandBase(CmdName, TargetId) { setIndex(index); }

  static GetIonoAlphaPtr create(int index) { return std::make_shared<GetIonoAlpha>(index); }

  static GetIonoAlphaPtr dynamicCast(CommandBasePtr ptr) { return std::dynamic_pointer_cast<GetIonoAlpha>(ptr); }

  virtual bool isValid() const override { return m_values.IsObject() && parse_json<int>::is_valid(m_values["Index"]); }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"Index"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  int index() const { return parse_json<int>::parse(m_values["Index"]); }

  void setIndex(int index)
  {
    m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetIonoAlpha);
} // namespace Cmd
} // namespace Sdx
