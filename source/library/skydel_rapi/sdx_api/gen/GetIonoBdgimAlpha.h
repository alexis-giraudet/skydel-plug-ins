#pragma once

#include <memory>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Get the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)
///
/// Name  Type Description
/// ----- ---- ------------------------
/// Index int  Coefficient index [1..9]
///

class GetIonoBdgimAlpha;
typedef std::shared_ptr<GetIonoBdgimAlpha> GetIonoBdgimAlphaPtr;

class GetIonoBdgimAlpha : public CommandBase
{
public:
  inline static const char* const CmdName = "GetIonoBdgimAlpha";
  inline static const char* const Documentation = "Get the BeiDou (BDGIM) ionospheric Alpha coefficient (in TECu)\n"
                                                  "\n"
                                                  "Name  Type Description\n"
                                                  "----- ---- ------------------------\n"
                                                  "Index int  Coefficient index [1..9]";
  inline static const char* const TargetId = "";

  GetIonoBdgimAlpha() : CommandBase(CmdName, TargetId) {}

  GetIonoBdgimAlpha(int index) : CommandBase(CmdName, TargetId) { setIndex(index); }

  static GetIonoBdgimAlphaPtr create(int index) { return std::make_shared<GetIonoBdgimAlpha>(index); }

  static GetIonoBdgimAlphaPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetIonoBdgimAlpha>(ptr);
  }

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
REGISTER_COMMAND_TO_FACTORY(GetIonoBdgimAlpha);
} // namespace Cmd
} // namespace Sdx
