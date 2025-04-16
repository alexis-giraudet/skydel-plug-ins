#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether the JAM Calibration output is transmitting.
    ///
    /// Name  Type Description
    /// ----- ---- ------------------------------------------------------------------------------
    /// State bool True for the signal to go through the JAM Calibration output, False otherwise.
    ///

    class SetWavefrontJamCalibrationState;
    typedef std::shared_ptr<SetWavefrontJamCalibrationState> SetWavefrontJamCalibrationStatePtr;
    
    
    class SetWavefrontJamCalibrationState : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetWavefrontJamCalibrationState";
      inline static const char* const Documentation = "Set whether the JAM Calibration output is transmitting.\n"      "\n"      "Name  Type Description\n"      "----- ---- ------------------------------------------------------------------------------\n"      "State bool True for the signal to go through the JAM Calibration output, False otherwise.";
      inline static const char* const TargetId = "";



          SetWavefrontJamCalibrationState()
            : CommandBase(CmdName, TargetId)
          {}

          SetWavefrontJamCalibrationState(bool state)
            : CommandBase(CmdName, TargetId)
          {

            setState(state);
          }


          static SetWavefrontJamCalibrationStatePtr create(bool state)
          {
            return std::make_shared<SetWavefrontJamCalibrationState>(state);
          }

      static SetWavefrontJamCalibrationStatePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetWavefrontJamCalibrationState>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["State"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"State"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING;
          }


          bool state() const
          {
            return parse_json<bool>::parse(m_values["State"]);
          }

          void setState(bool state)
          {
            m_values.AddMember("State", parse_json<bool>::format(state, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetWavefrontJamCalibrationState);
  }
}

