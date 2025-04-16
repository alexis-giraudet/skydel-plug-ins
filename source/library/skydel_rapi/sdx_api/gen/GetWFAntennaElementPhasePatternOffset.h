#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use GetVehiclePhasePatternOffset.
    /// 
    /// Get WF Antenna phase pattern offset (in rad) for this element
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Element int  One-based index for element in antenna.
    ///

    class GetWFAntennaElementPhasePatternOffset;
    typedef std::shared_ptr<GetWFAntennaElementPhasePatternOffset> GetWFAntennaElementPhasePatternOffsetPtr;
    
    
    class GetWFAntennaElementPhasePatternOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetWFAntennaElementPhasePatternOffset";
      inline static const char* const Documentation = "Please note the command GetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use GetVehiclePhasePatternOffset.\n"      "\n"      "Get WF Antenna phase pattern offset (in rad) for this element\n"      "\n"      "Name    Type Description\n"      "------- ---- ---------------------------------------\n"      "Element int  One-based index for element in antenna.";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command GetWFAntennaElementPhasePatternOffset is deprecated since 23.11. You may use GetVehiclePhasePatternOffset.";



          GetWFAntennaElementPhasePatternOffset()
            : CommandBase(CmdName, TargetId)
          {}

          GetWFAntennaElementPhasePatternOffset(int element)
            : CommandBase(CmdName, TargetId)
          {

            setElement(element);
          }


          static GetWFAntennaElementPhasePatternOffsetPtr create(int element)
          {
            return std::make_shared<GetWFAntennaElementPhasePatternOffset>(element);
          }

      static GetWFAntennaElementPhasePatternOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetWFAntennaElementPhasePatternOffset>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Element"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Element"}; 
        return names; 
      }
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(GetWFAntennaElementPhasePatternOffset);
  }
}

