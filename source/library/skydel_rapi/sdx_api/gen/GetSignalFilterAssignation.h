#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_base.h"
#include "command_factory.h"

namespace Sdx
{
namespace Cmd
{
///
/// Returns filter names assigned to requested signals.
///
/// Name        Type         Description
/// ----------- ------------ --------------------------------------------------------------------------------
/// SignalArray array string An array of signals.
///                          Accepted values are: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME",
///                                               "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a", "E5b",
///                                               "E5AltBOC", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a",
///                                               "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB",
///                                               "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S",
///                                               "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL",
///                                               "PULSARX1" and "PULSARX5"
///

class GetSignalFilterAssignation;
typedef std::shared_ptr<GetSignalFilterAssignation> GetSignalFilterAssignationPtr;

class GetSignalFilterAssignation : public CommandBase
{
public:
  inline static const char* const CmdName = "GetSignalFilterAssignation";
  inline static const char* const Documentation =
    "Returns filter names assigned to requested signals.\n"
    "\n"
    "Name        Type         Description\n"
    "----------- ------------ --------------------------------------------------------------------------------\n"
    "SignalArray array string An array of signals.\n"
    "                         Accepted values are: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\",\n"
    "                                              \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\",\n"
    "                                              \"E5AltBOC\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\",\n"
    "                                              \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\",\n"
    "                                              \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\",\n"
    "                                              \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\",\n"
    "                                              \"PULSARX1\" and \"PULSARX5\"";
  inline static const char* const TargetId = "";

  GetSignalFilterAssignation() : CommandBase(CmdName, TargetId) {}

  GetSignalFilterAssignation(const std::vector<std::string>& signalArray) : CommandBase(CmdName, TargetId)
  {

    setSignalArray(signalArray);
  }

  static GetSignalFilterAssignationPtr create(const std::vector<std::string>& signalArray)
  {
    return std::make_shared<GetSignalFilterAssignation>(signalArray);
  }

  static GetSignalFilterAssignationPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetSignalFilterAssignation>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SignalArray"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_IDLE; }

  std::vector<std::string> signalArray() const
  {
    return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
  }

  void setSignalArray(const std::vector<std::string>& signalArray)
  {
    m_values.AddMember("SignalArray",
                       parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetSignalFilterAssignation);
} // namespace Cmd
} // namespace Sdx
