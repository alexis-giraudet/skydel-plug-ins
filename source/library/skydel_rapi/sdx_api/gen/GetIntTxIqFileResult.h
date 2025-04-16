#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIntTxIqFile.
    ///
    /// Name          Type         Description
    /// ------------- ------------ ---------------------------------------------------
    /// Enabled       bool         Enable (true) or disable (false) the signal
    /// CentralFreq   double       Central frequency (Hz)
    /// Power         double       Power (dB), relative to transmitter reference power
    /// Path          string       Path to the file to play
    /// TransmitterId string       Transmitter unique identifier.
    /// SignalId      string       AWGN unique identifier.
    /// Group         optional int Group, if not using default group.
    ///

    class GetIntTxIqFileResult;
    typedef std::shared_ptr<GetIntTxIqFileResult> GetIntTxIqFileResultPtr;
    
    
    class GetIntTxIqFileResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIntTxIqFileResult";
      inline static const char* const Documentation = "Result of GetIntTxIqFile.\n"      "\n"      "Name          Type         Description\n"      "------------- ------------ ---------------------------------------------------\n"      "Enabled       bool         Enable (true) or disable (false) the signal\n"      "CentralFreq   double       Central frequency (Hz)\n"      "Power         double       Power (dB), relative to transmitter reference power\n"      "Path          string       Path to the file to play\n"      "TransmitterId string       Transmitter unique identifier.\n"      "SignalId      string       AWGN unique identifier.\n"      "Group         optional int Group, if not using default group.";
      inline static const char* const TargetId = "";



          GetIntTxIqFileResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIntTxIqFileResult(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {})
            : CommandResult(CmdName, TargetId)
          {

            setEnabled(enabled);
            setCentralFreq(centralFreq);
            setPower(power);
            setPath(path);
            setTransmitterId(transmitterId);
            setSignalId(signalId);
            setGroup(group);
          }

          GetIntTxIqFileResult(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setEnabled(enabled);
            setCentralFreq(centralFreq);
            setPower(power);
            setPath(path);
            setTransmitterId(transmitterId);
            setSignalId(signalId);
            setGroup(group);
          }



          static GetIntTxIqFileResultPtr create(bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {})
          {
            return std::make_shared<GetIntTxIqFileResult>(enabled, centralFreq, power, path, transmitterId, signalId, group);
          }

          static GetIntTxIqFileResultPtr create(CommandBasePtr relatedCommand, bool enabled, double centralFreq, double power, const std::string& path, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& group = {})
          {
            return std::make_shared<GetIntTxIqFileResult>(relatedCommand, enabled, centralFreq, power, path, transmitterId, signalId, group);
          }

      static GetIntTxIqFileResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIntTxIqFileResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<double>::is_valid(m_values["CentralFreq"])
                  && parse_json<double>::is_valid(m_values["Power"])
                  && parse_json<std::string>::is_valid(m_values["Path"])
                  && parse_json<std::string>::is_valid(m_values["TransmitterId"])
                  && parse_json<std::string>::is_valid(m_values["SignalId"])
                  && parse_json<std::optional<int>>::is_valid(m_values["Group"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "Path", "TransmitterId", "SignalId", "Group"}; 
        return names; 
      }
      


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double centralFreq() const
          {
            return parse_json<double>::parse(m_values["CentralFreq"]);
          }

          void setCentralFreq(double centralFreq)
          {
            m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double power() const
          {
            return parse_json<double>::parse(m_values["Power"]);
          }

          void setPower(double power)
          {
            m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string path() const
          {
            return parse_json<std::string>::parse(m_values["Path"]);
          }

          void setPath(const std::string& path)
          {
            m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string transmitterId() const
          {
            return parse_json<std::string>::parse(m_values["TransmitterId"]);
          }

          void setTransmitterId(const std::string& transmitterId)
          {
            m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string signalId() const
          {
            return parse_json<std::string>::parse(m_values["SignalId"]);
          }

          void setSignalId(const std::string& signalId)
          {
            m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<int> group() const
          {
            return parse_json<std::optional<int>>::parse(m_values["Group"]);
          }

          void setGroup(const std::optional<int>& group)
          {
            m_values.AddMember("Group", parse_json<std::optional<int>>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIntTxIqFileResult);
  }
}

