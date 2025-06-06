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
/// Set (or Modify) event to change GPS LNAV message bits.
///
/// Note that start and stop time are automatically extended to beginning and ending of overlapped
/// subframes. The Modification parameter is a string where the first character applies to the first
/// bit of subframe word and last character applies to last bit of subframe word.
///    '0' will force bit to zero
///    '1' will for bit to one
///    'X' will negate bit value
///    any other byte value will have no effect
///
/// Example: "-00------------------1-X------" will force bits 1 and 2 to zero and bit 22 to one
///                       and negate bit 24
///
/// Note: if UpdateParity is true, any modification to bits 25..30 will have no effect.
///
/// The ID parameter is automatically updated with a unique ID by the simulator for future reference.
/// If the ID is set with a value other than an empty string, the simulator will try to find a match
/// with previously added events. If there is a match, the event is updated with this message
/// instead of adding a new event. If there is no match, the event is added and the ID is not
/// changed.
///
/// Name             Type         Description
/// ---------------- ------------
/// ------------------------------------------------------------------------------------------------------ SignalArray
/// array string Array of signals to apply the message modification to, accepts "L1CA", "L1P" and "L2P" (empty for all)
/// SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)
/// StartTime        int          Elapsed time in seconds since start of simulation
/// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
/// Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)
/// Page             int          Page 1..25 (use 0 to apply modification to all pages)
/// Word             int          Word 1..10 (use 0 to apply modification to all words)
/// UpdateParity     bool         Recalculate parity after making modification
/// WordModification string       Modification string must be 30 bits long
/// Id               string       Unique identifier of the event
///

class SetMessageModificationToGpsLNav;
typedef std::shared_ptr<SetMessageModificationToGpsLNav> SetMessageModificationToGpsLNavPtr;

class SetMessageModificationToGpsLNav : public CommandBase
{
public:
  inline static const char* const CmdName = "SetMessageModificationToGpsLNav";
  inline static const char* const Documentation =
    "Set (or Modify) event to change GPS LNAV message bits.\n"
    "\n"
    "Note that start and stop time are automatically extended to beginning and ending of overlapped\n"
    "subframes. The Modification parameter is a string where the first character applies to the first\n"
    "bit of subframe word and last character applies to last bit of subframe word.\n"
    "   '0' will force bit to zero\n"
    "   '1' will for bit to one\n"
    "   'X' will negate bit value\n"
    "   any other byte value will have no effect\n"
    "\n"
    "Example: \"-00------------------1-X------\" will force bits 1 and 2 to zero and bit 22 to one\n"
    "                      and negate bit 24\n"
    "\n"
    "Note: if UpdateParity is true, any modification to bits 25..30 will have no effect.\n"
    "\n"
    "The ID parameter is automatically updated with a unique ID by the simulator for future reference.\n"
    "If the ID is set with a value other than an empty string, the simulator will try to find a match\n"
    "with previously added events. If there is a match, the event is updated with this message\n"
    "instead of adding a new event. If there is no match, the event is added and the ID is not\n"
    "changed.\n"
    "\n"
    "Name             Type         Description\n"
    "---------------- ------------ ------------------------------------------------------------------------------------------------------\n"
    "SignalArray      array string Array of signals to apply the message modification to, accepts \"L1CA\", \"L1P\" and \"L2P\" (empty for all)\n"
    "SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)\n"
    "StartTime        int          Elapsed time in seconds since start of simulation\n"
    "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
    "Subframe         int          Subframe 1..5 (use 0 to apply modification to all subframes)\n"
    "Page             int          Page 1..25 (use 0 to apply modification to all pages)\n"
    "Word             int          Word 1..10 (use 0 to apply modification to all words)\n"
    "UpdateParity     bool         Recalculate parity after making modification\n"
    "WordModification string       Modification string must be 30 bits long\n"
    "Id               string       Unique identifier of the event";
  inline static const char* const TargetId = "";

  SetMessageModificationToGpsLNav() : CommandBase(CmdName, TargetId) {}

  SetMessageModificationToGpsLNav(const std::vector<std::string>& signalArray,
                                  int svId,
                                  int startTime,
                                  int stopTime,
                                  int subframe,
                                  int page,
                                  int word,
                                  bool updateParity,
                                  const std::string& wordModification,
                                  const std::string& id) :
    CommandBase(CmdName, TargetId)
  {

    setSignalArray(signalArray);
    setSvId(svId);
    setStartTime(startTime);
    setStopTime(stopTime);
    setSubframe(subframe);
    setPage(page);
    setWord(word);
    setUpdateParity(updateParity);
    setWordModification(wordModification);
    setId(id);
  }

  static SetMessageModificationToGpsLNavPtr create(const std::vector<std::string>& signalArray,
                                                   int svId,
                                                   int startTime,
                                                   int stopTime,
                                                   int subframe,
                                                   int page,
                                                   int word,
                                                   bool updateParity,
                                                   const std::string& wordModification,
                                                   const std::string& id)
  {
    return std::make_shared<SetMessageModificationToGpsLNav>(signalArray,
                                                             svId,
                                                             startTime,
                                                             stopTime,
                                                             subframe,
                                                             page,
                                                             word,
                                                             updateParity,
                                                             wordModification,
                                                             id);
  }

  static SetMessageModificationToGpsLNavPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<SetMessageModificationToGpsLNav>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<int>::is_valid(m_values["StartTime"]) &&
           parse_json<int>::is_valid(m_values["StopTime"]) && parse_json<int>::is_valid(m_values["Subframe"]) &&
           parse_json<int>::is_valid(m_values["Page"]) && parse_json<int>::is_valid(m_values["Word"]) &&
           parse_json<bool>::is_valid(m_values["UpdateParity"]) &&
           parse_json<std::string>::is_valid(m_values["WordModification"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SignalArray",
                                                 "SvId",
                                                 "StartTime",
                                                 "StopTime",
                                                 "Subframe",
                                                 "Page",
                                                 "Word",
                                                 "UpdateParity",
                                                 "WordModification",
                                                 "Id"};
    return names;
  }

  int executePermission() const { return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE; }

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

  int svId() const { return parse_json<int>::parse(m_values["SvId"]); }

  void setSvId(int svId)
  {
    m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int startTime() const { return parse_json<int>::parse(m_values["StartTime"]); }

  void setStartTime(int startTime)
  {
    m_values.AddMember("StartTime",
                       parse_json<int>::format(startTime, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  int stopTime() const { return parse_json<int>::parse(m_values["StopTime"]); }

  void setStopTime(int stopTime)
  {
    m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int subframe() const { return parse_json<int>::parse(m_values["Subframe"]); }

  void setSubframe(int subframe)
  {
    m_values.AddMember("Subframe", parse_json<int>::format(subframe, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int page() const { return parse_json<int>::parse(m_values["Page"]); }

  void setPage(int page)
  {
    m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int word() const { return parse_json<int>::parse(m_values["Word"]); }

  void setWord(int word)
  {
    m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
  }

  bool updateParity() const { return parse_json<bool>::parse(m_values["UpdateParity"]); }

  void setUpdateParity(bool updateParity)
  {
    m_values.AddMember("UpdateParity",
                       parse_json<bool>::format(updateParity, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string wordModification() const { return parse_json<std::string>::parse(m_values["WordModification"]); }

  void setWordModification(const std::string& wordModification)
  {
    m_values.AddMember("WordModification",
                       parse_json<std::string>::format(wordModification, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(SetMessageModificationToGpsLNav);
} // namespace Cmd
} // namespace Sdx
