#pragma once

#include <memory>
#include <string>
#include <vector>

#include "command_factory.h"
#include "command_result.h"

namespace Sdx
{
namespace Cmd
{
///
/// Result of GetMessageModificationToGlonassNav.
///
/// Name               Type         Description
/// ------------------ ------------
/// -------------------------------------------------------------------------------------------- SignalArray array
/// string Array of signals to apply the message modification to, accepts "G1" and "G2" (empty for all) SvId int The
/// satellite's SV ID number 1..24 (use 0 to apply modification to all SVs) StartTime          int          Elapsed time
/// in seconds since start of simulation StopTime           int          Elapsed time in seconds since start of
/// simulation (use 0 for no stop time) Frame              int          Frame 1..5 (use 0 to apply modification to all
/// frames) StringNumber       int          String 1..15 (use 0 to apply modification to all strings) UpdateHammingCode
/// bool         Recalculate Hamming Code after making modification StringModification string       Modification string
/// must be 85 bits long (or more if using white spaces) Id                 string       Unique identifier of the event
///

class GetMessageModificationToGlonassNavResult;
typedef std::shared_ptr<GetMessageModificationToGlonassNavResult> GetMessageModificationToGlonassNavResultPtr;

class GetMessageModificationToGlonassNavResult : public CommandResult
{
public:
  inline static const char* const CmdName = "GetMessageModificationToGlonassNavResult";
  inline static const char* const Documentation =
    "Result of GetMessageModificationToGlonassNav.\n"
    "\n"
    "Name               Type         Description\n"
    "------------------ ------------ --------------------------------------------------------------------------------------------\n"
    "SignalArray        array string Array of signals to apply the message modification to, accepts \"G1\" and \"G2\" (empty for all)\n"
    "SvId               int          The satellite's SV ID number 1..24 (use 0 to apply modification to all SVs)\n"
    "StartTime          int          Elapsed time in seconds since start of simulation\n"
    "StopTime           int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"
    "Frame              int          Frame 1..5 (use 0 to apply modification to all frames)\n"
    "StringNumber       int          String 1..15 (use 0 to apply modification to all strings)\n"
    "UpdateHammingCode  bool         Recalculate Hamming Code after making modification\n"
    "StringModification string       Modification string must be 85 bits long (or more if using white spaces)\n"
    "Id                 string       Unique identifier of the event";
  inline static const char* const TargetId = "";

  GetMessageModificationToGlonassNavResult() : CommandResult(CmdName, TargetId) {}

  GetMessageModificationToGlonassNavResult(const std::vector<std::string>& signalArray,
                                           int svId,
                                           int startTime,
                                           int stopTime,
                                           int frame,
                                           int stringNumber,
                                           bool updateHammingCode,
                                           const std::string& stringModification,
                                           const std::string& id) :
    CommandResult(CmdName, TargetId)
  {

    setSignalArray(signalArray);
    setSvId(svId);
    setStartTime(startTime);
    setStopTime(stopTime);
    setFrame(frame);
    setStringNumber(stringNumber);
    setUpdateHammingCode(updateHammingCode);
    setStringModification(stringModification);
    setId(id);
  }

  GetMessageModificationToGlonassNavResult(CommandBasePtr relatedCommand,
                                           const std::vector<std::string>& signalArray,
                                           int svId,
                                           int startTime,
                                           int stopTime,
                                           int frame,
                                           int stringNumber,
                                           bool updateHammingCode,
                                           const std::string& stringModification,
                                           const std::string& id) :
    CommandResult(CmdName, TargetId, relatedCommand)
  {

    setSignalArray(signalArray);
    setSvId(svId);
    setStartTime(startTime);
    setStopTime(stopTime);
    setFrame(frame);
    setStringNumber(stringNumber);
    setUpdateHammingCode(updateHammingCode);
    setStringModification(stringModification);
    setId(id);
  }

  static GetMessageModificationToGlonassNavResultPtr create(const std::vector<std::string>& signalArray,
                                                            int svId,
                                                            int startTime,
                                                            int stopTime,
                                                            int frame,
                                                            int stringNumber,
                                                            bool updateHammingCode,
                                                            const std::string& stringModification,
                                                            const std::string& id)
  {
    return std::make_shared<GetMessageModificationToGlonassNavResult>(signalArray,
                                                                      svId,
                                                                      startTime,
                                                                      stopTime,
                                                                      frame,
                                                                      stringNumber,
                                                                      updateHammingCode,
                                                                      stringModification,
                                                                      id);
  }

  static GetMessageModificationToGlonassNavResultPtr create(CommandBasePtr relatedCommand,
                                                            const std::vector<std::string>& signalArray,
                                                            int svId,
                                                            int startTime,
                                                            int stopTime,
                                                            int frame,
                                                            int stringNumber,
                                                            bool updateHammingCode,
                                                            const std::string& stringModification,
                                                            const std::string& id)
  {
    return std::make_shared<GetMessageModificationToGlonassNavResult>(relatedCommand,
                                                                      signalArray,
                                                                      svId,
                                                                      startTime,
                                                                      stopTime,
                                                                      frame,
                                                                      stringNumber,
                                                                      updateHammingCode,
                                                                      stringModification,
                                                                      id);
  }

  static GetMessageModificationToGlonassNavResultPtr dynamicCast(CommandBasePtr ptr)
  {
    return std::dynamic_pointer_cast<GetMessageModificationToGlonassNavResult>(ptr);
  }

  virtual bool isValid() const override
  {

    return m_values.IsObject() && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"]) &&
           parse_json<int>::is_valid(m_values["SvId"]) && parse_json<int>::is_valid(m_values["StartTime"]) &&
           parse_json<int>::is_valid(m_values["StopTime"]) && parse_json<int>::is_valid(m_values["Frame"]) &&
           parse_json<int>::is_valid(m_values["StringNumber"]) &&
           parse_json<bool>::is_valid(m_values["UpdateHammingCode"]) &&
           parse_json<std::string>::is_valid(m_values["StringModification"]) &&
           parse_json<std::string>::is_valid(m_values["Id"]);
  }

  virtual std::string documentation() const override { return Documentation; }

  virtual const std::vector<std::string>& fieldNames() const override
  {
    static const std::vector<std::string> names {"SignalArray",
                                                 "SvId",
                                                 "StartTime",
                                                 "StopTime",
                                                 "Frame",
                                                 "StringNumber",
                                                 "UpdateHammingCode",
                                                 "StringModification",
                                                 "Id"};
    return names;
  }

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

  int frame() const { return parse_json<int>::parse(m_values["Frame"]); }

  void setFrame(int frame)
  {
    m_values.AddMember("Frame", parse_json<int>::format(frame, m_values.GetAllocator()), m_values.GetAllocator());
  }

  int stringNumber() const { return parse_json<int>::parse(m_values["StringNumber"]); }

  void setStringNumber(int stringNumber)
  {
    m_values.AddMember("StringNumber",
                       parse_json<int>::format(stringNumber, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  bool updateHammingCode() const { return parse_json<bool>::parse(m_values["UpdateHammingCode"]); }

  void setUpdateHammingCode(bool updateHammingCode)
  {
    m_values.AddMember("UpdateHammingCode",
                       parse_json<bool>::format(updateHammingCode, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string stringModification() const { return parse_json<std::string>::parse(m_values["StringModification"]); }

  void setStringModification(const std::string& stringModification)
  {
    m_values.AddMember("StringModification",
                       parse_json<std::string>::format(stringModification, m_values.GetAllocator()),
                       m_values.GetAllocator());
  }

  std::string id() const { return parse_json<std::string>::parse(m_values["Id"]); }

  void setId(const std::string& id)
  {
    m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
  }
};
REGISTER_COMMAND_TO_FACTORY(GetMessageModificationToGlonassNavResult);
} // namespace Cmd
} // namespace Sdx
