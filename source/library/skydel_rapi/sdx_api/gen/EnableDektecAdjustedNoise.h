#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Adjusts the Advanced Jammer IQ data amplitude on the Dektec output by adding noise to ensure power level linearity on weak jammer signals. Note that enabling this option will increase the noise observed at the RF output for all jammer signal power levels.
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------------
    /// Enable bool True to enable Advance Jammer noise adjustment on Dektec output.
    ///

    class EnableDektecAdjustedNoise;
    typedef std::shared_ptr<EnableDektecAdjustedNoise> EnableDektecAdjustedNoisePtr;
    
    
    class EnableDektecAdjustedNoise : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableDektecAdjustedNoise";
      inline static const char* const Documentation = "Adjusts the Advanced Jammer IQ data amplitude on the Dektec output by adding noise to ensure power level linearity on weak jammer signals. Note that enabling this option will increase the noise observed at the RF output for all jammer signal power levels.\n"      "\n"      "Name   Type Description\n"      "------ ---- ----------------------------------------------------------------\n"      "Enable bool True to enable Advance Jammer noise adjustment on Dektec output.";
      inline static const char* const TargetId = "";



          EnableDektecAdjustedNoise()
            : CommandBase(CmdName, TargetId)
          {}

          EnableDektecAdjustedNoise(bool enable)
            : CommandBase(CmdName, TargetId)
          {

            setEnable(enable);
          }


          static EnableDektecAdjustedNoisePtr create(bool enable)
          {
            return std::make_shared<EnableDektecAdjustedNoise>(enable);
          }

      static EnableDektecAdjustedNoisePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableDektecAdjustedNoise>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enable"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enable"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          bool enable() const
          {
            return parse_json<bool>::parse(m_values["Enable"]);
          }

          void setEnable(bool enable)
          {
            m_values.AddMember("Enable", parse_json<bool>::format(enable, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EnableDektecAdjustedNoise);
  }
}

