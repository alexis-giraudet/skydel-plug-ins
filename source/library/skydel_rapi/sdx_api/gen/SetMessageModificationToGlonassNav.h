#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set (or Modify) event to change GLONASS NAV message bits.
    /// 
    /// Note that start and stop time are automatically extended to beginning and ending of overlapped
    /// message strings. The Modification parameter is a string where the first character applies to bit
    /// 85 of frame string and last character applies to Hamming Code bit 1.
    ///    '0' will force bit to zero
    ///    '1' will for bit to one
    ///    'X' will negate bit value
    ///    ' ' white space are ignored (use them to separate the string into bytes to help reading)
    ///    '-' or any other byte value will have no effect
    /// 
    /// Example:
    /// 
    /// "-0--- 1------- -------- -------- -------- -------- -------- -------- -------- -------- ---1--X-"
    ///   |  |                                           |  |
    ///   |  +- Force bit 80 to '1'               Force Hamming code bit 5 to '1' -+  |
    ///   |                                               |
    ///   +------ Force bit 84 to 0                   Negate Hamming code bit 2 ----+
    /// 
    /// Note: if UpdateHammingCode is true, any modification to bits 1..8 will have no effect.
    /// 
    /// The ID parameter is automatically updated with a unique ID by the simulator for future reference.
    /// If the ID is set with a value other than an empty string, the simulator will try to find a match
    /// with previously added events. If there is a match, the event is updated with this message
    /// instead of adding a new event. If there is no match, the event is added and the ID is not
    /// changed.
    ///
    /// Name               Type         Description
    /// ------------------ ------------ --------------------------------------------------------------------------------------------
    /// SignalArray        array string Array of signals to apply the message modification to, accepts "G1" and "G2" (empty for all)
    /// SvId               int          The satellite's SV ID number 1..24 (use 0 to apply modification to all SVs)
    /// StartTime          int          Elapsed time in seconds since start of simulation
    /// StopTime           int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// Frame              int          Frame 1..5 (use 0 to apply modification to all frames)
    /// StringNumber       int          String 1..15 (use 0 to apply modification to all strings)
    /// UpdateHammingCode  bool         Recalculate Hamming Code after making modification
    /// StringModification string       Modification string must be 85 bits long (or more if using white spaces)
    /// Id                 string       Unique identifier of the event
    ///

    class SetMessageModificationToGlonassNav;
    typedef std::shared_ptr<SetMessageModificationToGlonassNav> SetMessageModificationToGlonassNavPtr;
    
    
    class SetMessageModificationToGlonassNav : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetMessageModificationToGlonassNav";
      inline static const char* const Documentation = "Set (or Modify) event to change GLONASS NAV message bits.\n"      "\n"      "Note that start and stop time are automatically extended to beginning and ending of overlapped\n"      "message strings. The Modification parameter is a string where the first character applies to bit\n"      "85 of frame string and last character applies to Hamming Code bit 1.\n"      "   '0' will force bit to zero\n"      "   '1' will for bit to one\n"      "   'X' will negate bit value\n"      "   ' ' white space are ignored (use them to separate the string into bytes to help reading)\n"      "   '-' or any other byte value will have no effect\n"      "\n"      "Example:\n"      "\n"      "\"-0--- 1------- -------- -------- -------- -------- -------- -------- -------- -------- ---1--X-\"\n"      "  |  |                                           |  |\n"      "  |  +- Force bit 80 to '1'               Force Hamming code bit 5 to '1' -+  |\n"      "  |                                               |\n"      "  +------ Force bit 84 to 0                   Negate Hamming code bit 2 ----+\n"      "\n"      "Note: if UpdateHammingCode is true, any modification to bits 1..8 will have no effect.\n"      "\n"      "The ID parameter is automatically updated with a unique ID by the simulator for future reference.\n"      "If the ID is set with a value other than an empty string, the simulator will try to find a match\n"      "with previously added events. If there is a match, the event is updated with this message\n"      "instead of adding a new event. If there is no match, the event is added and the ID is not\n"      "changed.\n"      "\n"      "Name               Type         Description\n"      "------------------ ------------ --------------------------------------------------------------------------------------------\n"      "SignalArray        array string Array of signals to apply the message modification to, accepts \"G1\" and \"G2\" (empty for all)\n"      "SvId               int          The satellite's SV ID number 1..24 (use 0 to apply modification to all SVs)\n"      "StartTime          int          Elapsed time in seconds since start of simulation\n"      "StopTime           int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"      "Frame              int          Frame 1..5 (use 0 to apply modification to all frames)\n"      "StringNumber       int          String 1..15 (use 0 to apply modification to all strings)\n"      "UpdateHammingCode  bool         Recalculate Hamming Code after making modification\n"      "StringModification string       Modification string must be 85 bits long (or more if using white spaces)\n"      "Id                 string       Unique identifier of the event";
      inline static const char* const TargetId = "";



          SetMessageModificationToGlonassNav()
            : CommandBase(CmdName, TargetId)
          {}

          SetMessageModificationToGlonassNav(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
            : CommandBase(CmdName, TargetId)
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


          static SetMessageModificationToGlonassNavPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int frame, int stringNumber, bool updateHammingCode, const std::string& stringModification, const std::string& id)
          {
            return std::make_shared<SetMessageModificationToGlonassNav>(signalArray, svId, startTime, stopTime, frame, stringNumber, updateHammingCode, stringModification, id);
          }

      static SetMessageModificationToGlonassNavPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetMessageModificationToGlonassNav>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["StartTime"])
                  && parse_json<int>::is_valid(m_values["StopTime"])
                  && parse_json<int>::is_valid(m_values["Frame"])
                  && parse_json<int>::is_valid(m_values["StringNumber"])
                  && parse_json<bool>::is_valid(m_values["UpdateHammingCode"])
                  && parse_json<std::string>::is_valid(m_values["StringModification"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "Frame", "StringNumber", "UpdateHammingCode", "StringModification", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          std::vector<std::string> signalArray() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["SignalArray"]);
          }

          void setSignalArray(const std::vector<std::string>& signalArray)
          {
            m_values.AddMember("SignalArray", parse_json<std::vector<std::string>>::format(signalArray, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int startTime() const
          {
            return parse_json<int>::parse(m_values["StartTime"]);
          }

          void setStartTime(int startTime)
          {
            m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int stopTime() const
          {
            return parse_json<int>::parse(m_values["StopTime"]);
          }

          void setStopTime(int stopTime)
          {
            m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int frame() const
          {
            return parse_json<int>::parse(m_values["Frame"]);
          }

          void setFrame(int frame)
          {
            m_values.AddMember("Frame", parse_json<int>::format(frame, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int stringNumber() const
          {
            return parse_json<int>::parse(m_values["StringNumber"]);
          }

          void setStringNumber(int stringNumber)
          {
            m_values.AddMember("StringNumber", parse_json<int>::format(stringNumber, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool updateHammingCode() const
          {
            return parse_json<bool>::parse(m_values["UpdateHammingCode"]);
          }

          void setUpdateHammingCode(bool updateHammingCode)
          {
            m_values.AddMember("UpdateHammingCode", parse_json<bool>::format(updateHammingCode, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string stringModification() const
          {
            return parse_json<std::string>::parse(m_values["StringModification"]);
          }

          void setStringModification(const std::string& stringModification)
          {
            m_values.AddMember("StringModification", parse_json<std::string>::format(stringModification, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetMessageModificationToGlonassNav);
  }
}

