#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <optional>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Change modulation offsets of one RF output
    ///
    /// Name        Type            Description
    /// ----------- --------------- ----------------------------------------------------------------
    /// OutputIdx   int             RF Output index (zero-based)
    /// PowerOffset double          Power offset (dB), to apply on all signals of the RF Output
    /// TimeOffset  double          Time offset (seconds), to apply on all signals of the RF Output
    /// PhaseOffset double          Phase offset (radians), to apply on all signals of the RF Output
    /// PhaseStep   optional double How much the phase (radians) should change per millisecond
    ///

    class SetRFOutputOffsets;
    typedef std::shared_ptr<SetRFOutputOffsets> SetRFOutputOffsetsPtr;
    
    
    class SetRFOutputOffsets : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetRFOutputOffsets";
      inline static const char* const Documentation = "Change modulation offsets of one RF output\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- ----------------------------------------------------------------\n"      "OutputIdx   int             RF Output index (zero-based)\n"      "PowerOffset double          Power offset (dB), to apply on all signals of the RF Output\n"      "TimeOffset  double          Time offset (seconds), to apply on all signals of the RF Output\n"      "PhaseOffset double          Phase offset (radians), to apply on all signals of the RF Output\n"      "PhaseStep   optional double How much the phase (radians) should change per millisecond";
      inline static const char* const TargetId = "";



          SetRFOutputOffsets()
            : CommandBase(CmdName, TargetId)
          {}

          SetRFOutputOffsets(int outputIdx, double powerOffset, double timeOffset, double phaseOffset, const std::optional<double>& phaseStep = {})
            : CommandBase(CmdName, TargetId)
          {

            setOutputIdx(outputIdx);
            setPowerOffset(powerOffset);
            setTimeOffset(timeOffset);
            setPhaseOffset(phaseOffset);
            setPhaseStep(phaseStep);
          }


          static SetRFOutputOffsetsPtr create(int outputIdx, double powerOffset, double timeOffset, double phaseOffset, const std::optional<double>& phaseStep = {})
          {
            return std::make_shared<SetRFOutputOffsets>(outputIdx, powerOffset, timeOffset, phaseOffset, phaseStep);
          }

      static SetRFOutputOffsetsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetRFOutputOffsets>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["OutputIdx"])
                  && parse_json<double>::is_valid(m_values["PowerOffset"])
                  && parse_json<double>::is_valid(m_values["TimeOffset"])
                  && parse_json<double>::is_valid(m_values["PhaseOffset"])
                  && parse_json<std::optional<double>>::is_valid(m_values["PhaseStep"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"OutputIdx", "PowerOffset", "TimeOffset", "PhaseOffset", "PhaseStep"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING;
          }


          int outputIdx() const
          {
            return parse_json<int>::parse(m_values["OutputIdx"]);
          }

          void setOutputIdx(int outputIdx)
          {
            m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double powerOffset() const
          {
            return parse_json<double>::parse(m_values["PowerOffset"]);
          }

          void setPowerOffset(double powerOffset)
          {
            m_values.AddMember("PowerOffset", parse_json<double>::format(powerOffset, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double timeOffset() const
          {
            return parse_json<double>::parse(m_values["TimeOffset"]);
          }

          void setTimeOffset(double timeOffset)
          {
            m_values.AddMember("TimeOffset", parse_json<double>::format(timeOffset, m_values.GetAllocator()), m_values.GetAllocator());
          }



          double phaseOffset() const
          {
            return parse_json<double>::parse(m_values["PhaseOffset"]);
          }

          void setPhaseOffset(double phaseOffset)
          {
            m_values.AddMember("PhaseOffset", parse_json<double>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<double> phaseStep() const
          {
            return parse_json<std::optional<double>>::parse(m_values["PhaseStep"]);
          }

          void setPhaseStep(const std::optional<double>& phaseStep)
          {
            m_values.AddMember("PhaseStep", parse_json<std::optional<double>>::format(phaseStep, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetRFOutputOffsets);
  }
}

