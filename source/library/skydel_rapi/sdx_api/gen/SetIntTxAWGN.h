#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set AWGN signal interference.
    ///
    /// Name          Type         Description
    /// ------------- ------------ ------------------------------------------------------------------------------------------
    /// Enabled       bool         Enable (true) or disable (false) the signal
    /// CentralFreq   double       Central frequency (Hz)
    /// Power         double       Power (dB), relative to transmitter reference power
    /// Bandwidth     double       Bandwidth (Hz)
    /// TransmitterId string       Transmitter unique identifier.
    /// SignalId      string       AWGN unique identifier.
    /// Seed          optional int Seed for the random number generator. Signals with the same seed will have the same shape.
    /// Group         optional int Group, if not using default group.
    ///

    class SetIntTxAWGN;
    typedef std::shared_ptr<SetIntTxAWGN> SetIntTxAWGNPtr;
    
    
    class SetIntTxAWGN : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetIntTxAWGN";
      inline static const char* const Documentation = "Set AWGN signal interference.\n"      "\n"      "Name          Type         Description\n"      "------------- ------------ ------------------------------------------------------------------------------------------\n"      "Enabled       bool         Enable (true) or disable (false) the signal\n"      "CentralFreq   double       Central frequency (Hz)\n"      "Power         double       Power (dB), relative to transmitter reference power\n"      "Bandwidth     double       Bandwidth (Hz)\n"      "TransmitterId string       Transmitter unique identifier.\n"      "SignalId      string       AWGN unique identifier.\n"      "Seed          optional int Seed for the random number generator. Signals with the same seed will have the same shape.\n"      "Group         optional int Group, if not using default group.";
      inline static const char* const TargetId = "";



          SetIntTxAWGN()
            : CommandBase(CmdName, TargetId)
          {}

          SetIntTxAWGN(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed = {}, const std::optional<int>& group = {})
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
            setCentralFreq(centralFreq);
            setPower(power);
            setBandwidth(bandwidth);
            setTransmitterId(transmitterId);
            setSignalId(signalId);
            setSeed(seed);
            setGroup(group);
          }


          static SetIntTxAWGNPtr create(bool enabled, double centralFreq, double power, double bandwidth, const std::string& transmitterId, const std::string& signalId, const std::optional<int>& seed = {}, const std::optional<int>& group = {})
          {
            return std::make_shared<SetIntTxAWGN>(enabled, centralFreq, power, bandwidth, transmitterId, signalId, seed, group);
          }

      static SetIntTxAWGNPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetIntTxAWGN>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<double>::is_valid(m_values["CentralFreq"])
                  && parse_json<double>::is_valid(m_values["Power"])
                  && parse_json<double>::is_valid(m_values["Bandwidth"])
                  && parse_json<std::string>::is_valid(m_values["TransmitterId"])
                  && parse_json<std::string>::is_valid(m_values["SignalId"])
                  && parse_json<std::optional<int>>::is_valid(m_values["Seed"])
                  && parse_json<std::optional<int>>::is_valid(m_values["Group"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled", "CentralFreq", "Power", "Bandwidth", "TransmitterId", "SignalId", "Seed", "Group"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
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



          double bandwidth() const
          {
            return parse_json<double>::parse(m_values["Bandwidth"]);
          }

          void setBandwidth(double bandwidth)
          {
            m_values.AddMember("Bandwidth", parse_json<double>::format(bandwidth, m_values.GetAllocator()), m_values.GetAllocator());
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



          std::optional<int> seed() const
          {
            return parse_json<std::optional<int>>::parse(m_values["Seed"]);
          }

          void setSeed(const std::optional<int>& seed)
          {
            m_values.AddMember("Seed", parse_json<std::optional<int>>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetIntTxAWGN);
  }
}

