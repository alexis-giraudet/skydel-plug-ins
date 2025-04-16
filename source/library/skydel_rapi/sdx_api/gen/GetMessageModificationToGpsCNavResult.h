#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetMessageModificationToGpsCNav.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ ---------------------------------------------------------------------------------------------
    /// SignalArray      array string Array of signals to apply the message modification to, accepts "L2C" and "L5" (empty for all)
    /// SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)
    /// StartTime        int          Elapsed time in seconds since start of simulation
    /// StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)
    /// MessageType      int          CNAV Message type (use -1 to apply modification to all message types)
    /// Condition        string       Optional condition to match message content, ex: "EQUAL(45, 10, 0x3f)"
    /// UpdateCRC        bool         Recalculate CRC after making modification
    /// BitModifications string       Comma separated bit modifications
    /// Id               string       Unique identifier of the event
    ///

    class GetMessageModificationToGpsCNavResult;
    typedef std::shared_ptr<GetMessageModificationToGpsCNavResult> GetMessageModificationToGpsCNavResultPtr;
    
    
    class GetMessageModificationToGpsCNavResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetMessageModificationToGpsCNavResult";
      inline static const char* const Documentation = "Result of GetMessageModificationToGpsCNav.\n"      "\n"      "Name             Type         Description\n"      "---------------- ------------ ---------------------------------------------------------------------------------------------\n"      "SignalArray      array string Array of signals to apply the message modification to, accepts \"L2C\" and \"L5\" (empty for all)\n"      "SvId             int          The satellite's SV ID 1..32 (use 0 to apply modification to all SVs)\n"      "StartTime        int          Elapsed time in seconds since start of simulation\n"      "StopTime         int          Elapsed time in seconds since start of simulation (use 0 for no stop time)\n"      "MessageType      int          CNAV Message type (use -1 to apply modification to all message types)\n"      "Condition        string       Optional condition to match message content, ex: \"EQUAL(45, 10, 0x3f)\"\n"      "UpdateCRC        bool         Recalculate CRC after making modification\n"      "BitModifications string       Comma separated bit modifications\n"      "Id               string       Unique identifier of the event";
      inline static const char* const TargetId = "";



          GetMessageModificationToGpsCNavResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetMessageModificationToGpsCNavResult(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setSignalArray(signalArray);
            setSvId(svId);
            setStartTime(startTime);
            setStopTime(stopTime);
            setMessageType(messageType);
            setCondition(condition);
            setUpdateCRC(updateCRC);
            setBitModifications(bitModifications);
            setId(id);
          }

          GetMessageModificationToGpsCNavResult(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSignalArray(signalArray);
            setSvId(svId);
            setStartTime(startTime);
            setStopTime(stopTime);
            setMessageType(messageType);
            setCondition(condition);
            setUpdateCRC(updateCRC);
            setBitModifications(bitModifications);
            setId(id);
          }



          static GetMessageModificationToGpsCNavResultPtr create(const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
          {
            return std::make_shared<GetMessageModificationToGpsCNavResult>(signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
          }

          static GetMessageModificationToGpsCNavResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& signalArray, int svId, int startTime, int stopTime, int messageType, const std::string& condition, bool updateCRC, const std::string& bitModifications, const std::string& id)
          {
            return std::make_shared<GetMessageModificationToGpsCNavResult>(relatedCommand, signalArray, svId, startTime, stopTime, messageType, condition, updateCRC, bitModifications, id);
          }

      static GetMessageModificationToGpsCNavResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetMessageModificationToGpsCNavResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["SignalArray"])
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["StartTime"])
                  && parse_json<int>::is_valid(m_values["StopTime"])
                  && parse_json<int>::is_valid(m_values["MessageType"])
                  && parse_json<std::string>::is_valid(m_values["Condition"])
                  && parse_json<bool>::is_valid(m_values["UpdateCRC"])
                  && parse_json<std::string>::is_valid(m_values["BitModifications"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SignalArray", "SvId", "StartTime", "StopTime", "MessageType", "Condition", "UpdateCRC", "BitModifications", "Id"}; 
        return names; 
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



          int messageType() const
          {
            return parse_json<int>::parse(m_values["MessageType"]);
          }

          void setMessageType(int messageType)
          {
            m_values.AddMember("MessageType", parse_json<int>::format(messageType, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string condition() const
          {
            return parse_json<std::string>::parse(m_values["Condition"]);
          }

          void setCondition(const std::string& condition)
          {
            m_values.AddMember("Condition", parse_json<std::string>::format(condition, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool updateCRC() const
          {
            return parse_json<bool>::parse(m_values["UpdateCRC"]);
          }

          void setUpdateCRC(bool updateCRC)
          {
            m_values.AddMember("UpdateCRC", parse_json<bool>::format(updateCRC, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string bitModifications() const
          {
            return parse_json<std::string>::parse(m_values["BitModifications"]);
          }

          void setBitModifications(const std::string& bitModifications)
          {
            m_values.AddMember("BitModifications", parse_json<std::string>::format(bitModifications, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(GetMessageModificationToGpsCNavResult);
  }
}

