#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set CW pilot added to signal
    ///
    /// Name              Type   Description
    /// ----------------- ------ ---------------------------------------------------
    /// Enabled           bool   Enable (true) or disable (false) the signal
    /// OutputIdx         int    RF Output index (zero-based)
    /// CentralFreqOffset double Central frequency offset of the Pilot (Hz)
    /// Power             double Power (dB), relative to transmitter reference power
    /// PilotId           string CW Pilot unique identifier.
    ///

    class SetPilotCW;
    typedef std::shared_ptr<SetPilotCW> SetPilotCWPtr;
    
    
    class SetPilotCW : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetPilotCW";
      inline static const char* const Documentation = "Set CW pilot added to signal\n"      "\n"      "Name              Type   Description\n"      "----------------- ------ ---------------------------------------------------\n"      "Enabled           bool   Enable (true) or disable (false) the signal\n"      "OutputIdx         int    RF Output index (zero-based)\n"      "CentralFreqOffset double Central frequency offset of the Pilot (Hz)\n"      "Power             double Power (dB), relative to transmitter reference power\n"      "PilotId           string CW Pilot unique identifier.";
      inline static const char* const TargetId = "";



          SetPilotCW()
            : CommandBase(CmdName, TargetId)
          {}

          SetPilotCW(bool enabled, int outputIdx, double centralFreqOffset, double power, const std::string& pilotId)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
            setOutputIdx(outputIdx);
            setCentralFreqOffset(centralFreqOffset);
            setPower(power);
            setPilotId(pilotId);
          }


          static SetPilotCWPtr create(bool enabled, int outputIdx, double centralFreqOffset, double power, const std::string& pilotId)
          {
            return std::make_shared<SetPilotCW>(enabled, outputIdx, centralFreqOffset, power, pilotId);
          }

      static SetPilotCWPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetPilotCW>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                  && parse_json<int>::is_valid(m_values["OutputIdx"])
                  && parse_json<double>::is_valid(m_values["CentralFreqOffset"])
                  && parse_json<double>::is_valid(m_values["Power"])
                  && parse_json<std::string>::is_valid(m_values["PilotId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled", "OutputIdx", "CentralFreqOffset", "Power", "PilotId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING;
          }


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int outputIdx() const
          {
            return parse_json<int>::parse(m_values["OutputIdx"]);
          }

          void setOutputIdx(int outputIdx)
          {
            m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double centralFreqOffset() const
          {
            return parse_json<double>::parse(m_values["CentralFreqOffset"]);
          }

          void setCentralFreqOffset(double centralFreqOffset)
          {
            m_values.AddMember("CentralFreqOffset", parse_json<double>::format(centralFreqOffset, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double power() const
          {
            return parse_json<double>::parse(m_values["Power"]);
          }

          void setPower(double power)
          {
            m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string pilotId() const
          {
            return parse_json<std::string>::parse(m_values["PilotId"]);
          }

          void setPilotId(const std::string& pilotId)
          {
            m_values.AddMember("PilotId", parse_json<std::string>::format(pilotId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetPilotCW);
  }
}

