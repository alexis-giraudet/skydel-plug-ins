
#include "gen/SetMessageModificationToBeiDouD2Nav.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetMessageModificationToBeiDouD2Nav
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetMessageModificationToBeiDouD2Nav::CmdName = "SetMessageModificationToBeiDouD2Nav";
    const char* const SetMessageModificationToBeiDouD2Nav::Documentation = "Set (or Modify) event to change BeiDou D2 NAV message bits.\n\nNote that start and stop time are automatically extended to beginning and ending of overlapped\nsubframes. The Modification parameter is a string where the first character applies to the first\nbit of subframe word and last character applies to last bit of subframe word.\n   '0' will force bit to zero\n   '1' will for bit to one\n   'X' will negate bit value\n   any other byte value will have no effect\n\nExample: \"-00------------------1-X------\" will force bits 1 and 2 to zero and bit 22 to one\n                      and negate bit 24\n\nNote: if UpdateParity is true, any modification to parity bits will have no effect.\n\nThe ID parameter is automatically updated with a unique ID by the simulator for future reference.\nIf the ID is set with a value other than an empty string, the simulator will try to find a match\nwith previously added events. If there is a match, the event is updated with this message\ninstead of adding a new event. If there is no match, the event is added and the ID is not\nchanged.";

    REGISTER_COMMAND_FACTORY(SetMessageModificationToBeiDouD2Nav);


    SetMessageModificationToBeiDouD2Nav::SetMessageModificationToBeiDouD2Nav()
      : CommandBase(CmdName)
    {}

    SetMessageModificationToBeiDouD2Nav::SetMessageModificationToBeiDouD2Nav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
      : CommandBase(CmdName)
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

    SetMessageModificationToBeiDouD2NavPtr SetMessageModificationToBeiDouD2Nav::create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int subframe, int page, int word, bool updateParity, const std::string& wordModification, const std::string& id)
    {
      return std::make_shared<SetMessageModificationToBeiDouD2Nav>(signalArray, svId, startTime, stopTime, subframe, page, word, updateParity, wordModification, id);
    }

    SetMessageModificationToBeiDouD2NavPtr SetMessageModificationToBeiDouD2Nav::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetMessageModificationToBeiDouD2Nav>(ptr);
    }

    bool SetMessageModificationToBeiDouD2Nav::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<int>::is_valid(m_values["Subframe"])
          && parse_json<int>::is_valid(m_values["Page"])
          && parse_json<int>::is_valid(m_values["Word"])
          && parse_json<bool>::is_valid(m_values["UpdateParity"])
          && parse_json<std::string>::is_valid(m_values["WordModification"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetMessageModificationToBeiDouD2Nav::documentation() const { return Documentation; }


    int SetMessageModificationToBeiDouD2Nav::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<std::string> SetMessageModificationToBeiDouD2Nav::signalArray() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setSignalArray(const std::vector<std::string>& signalArray)
    {
      m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD2Nav::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD2Nav::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD2Nav::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD2Nav::subframe() const
    {
      return parse_json<int>::parse(m_values["Subframe"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setSubframe(int subframe)
    {
      m_values.AddMember("Subframe", parse_json<int>::format(subframe, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD2Nav::page() const
    {
      return parse_json<int>::parse(m_values["Page"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setPage(int page)
    {
      m_values.AddMember("Page", parse_json<int>::format(page, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int SetMessageModificationToBeiDouD2Nav::word() const
    {
      return parse_json<int>::parse(m_values["Word"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setWord(int word)
    {
      m_values.AddMember("Word", parse_json<int>::format(word, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool SetMessageModificationToBeiDouD2Nav::updateParity() const
    {
      return parse_json<bool>::parse(m_values["UpdateParity"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setUpdateParity(bool updateParity)
    {
      m_values.AddMember("UpdateParity", parse_json<bool>::format(updateParity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToBeiDouD2Nav::wordModification() const
    {
      return parse_json<std::string>::parse(m_values["WordModification"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setWordModification(const std::string& wordModification)
    {
      m_values.AddMember("WordModification", parse_json<std::string>::format(wordModification, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetMessageModificationToBeiDouD2Nav::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetMessageModificationToBeiDouD2Nav::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
