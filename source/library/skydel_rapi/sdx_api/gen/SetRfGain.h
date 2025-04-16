#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// USE AT YOUR OWN RISKS. Set the RF Gain of the SDR
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------
    /// Output int    Output index (zero based)
    /// Gain   double RF Gain of the SDR, in dB. Default value is 0. Only supported for USRP.
    ///

    class SetRfGain;
    typedef std::shared_ptr<SetRfGain> SetRfGainPtr;
    
    
    class SetRfGain : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetRfGain";
      inline static const char* const Documentation = "USE AT YOUR OWN RISKS. Set the RF Gain of the SDR\n"      "\n"      "Name   Type   Description\n"      "------ ------ -----------------------------------------------------------------------\n"      "Output int    Output index (zero based)\n"      "Gain   double RF Gain of the SDR, in dB. Default value is 0. Only supported for USRP.";
      inline static const char* const TargetId = "";



          SetRfGain()
            : CommandBase(CmdName, TargetId)
          {}

          SetRfGain(int output, double gain)
            : CommandBase(CmdName, TargetId)
          {

            setOutput(output);
            setGain(gain);
          }


          static SetRfGainPtr create(int output, double gain)
          {
            return std::make_shared<SetRfGain>(output, gain);
          }

      static SetRfGainPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetRfGain>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Output"])
                  && parse_json<double>::is_valid(m_values["Gain"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Output", "Gain"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          int output() const
          {
            return parse_json<int>::parse(m_values["Output"]);
          }

          void setOutput(int output)
          {
            m_values.AddMember("Output", parse_json<int>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double gain() const
          {
            return parse_json<double>::parse(m_values["Gain"]);
          }

          void setGain(double gain)
          {
            m_values.AddMember("Gain", parse_json<double>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetRfGain);
  }
}

