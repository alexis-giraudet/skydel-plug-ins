#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use AddVehiclePhasePatternOffset.
    /// 
    /// Set WF Antenna phase pattern offset (in rad) for this element
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------------
    /// PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]
    /// Element     int    One-based index for element in antenna.
    ///

    class SetWFAntennaElementPhasePatternOffset;
    typedef std::shared_ptr<SetWFAntennaElementPhasePatternOffset> SetWFAntennaElementPhasePatternOffsetPtr;
    
    
    class SetWFAntennaElementPhasePatternOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetWFAntennaElementPhasePatternOffset";
      inline static const char* const Documentation = "Please note the command SetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use AddVehiclePhasePatternOffset.\n"      "\n"      "Set WF Antenna phase pattern offset (in rad) for this element\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -------------------------------------------------------------------------\n"      "PhaseOffset double Antenna phase pattern offset (in rad) to set for this element. [-Pi ; Pi]\n"      "Element     int    One-based index for element in antenna.";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command SetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use AddVehiclePhasePatternOffset.";



          SetWFAntennaElementPhasePatternOffset()
            : CommandBase(CmdName, TargetId)
          {}

          SetWFAntennaElementPhasePatternOffset(double phaseOffset, int element)
            : CommandBase(CmdName, TargetId)
          {

            setPhaseOffset(phaseOffset);
            setElement(element);
          }


          static SetWFAntennaElementPhasePatternOffsetPtr create(double phaseOffset, int element)
          {
            return std::make_shared<SetWFAntennaElementPhasePatternOffset>(phaseOffset, element);
          }

      static SetWFAntennaElementPhasePatternOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetWFAntennaElementPhasePatternOffset>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["PhaseOffset"])
                  && parse_json<int>::is_valid(m_values["Element"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"PhaseOffset", "Element"}; 
        return names; 
      }
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          double phaseOffset() const
          {
            return parse_json<double>::parse(m_values["PhaseOffset"]);
          }

          void setPhaseOffset(double phaseOffset)
          {
            m_values.AddMember("PhaseOffset", parse_json<double>::format(phaseOffset, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int element() const
          {
            return parse_json<int>::parse(m_values["Element"]);
          }

          void setElement(int element)
          {
            m_values.AddMember("Element", parse_json<int>::format(element, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetWFAntennaElementPhasePatternOffset);
  }
}

