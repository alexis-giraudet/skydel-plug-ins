#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals. Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite power sliders in the Constellation tab is shifted by this offset.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.
    ///

    class SetDynamicRangeOffset;
    typedef std::shared_ptr<SetDynamicRangeOffset> SetDynamicRangeOffsetPtr;
    
    
    class SetDynamicRangeOffset : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetDynamicRangeOffset";
      inline static const char* const Documentation = "Set the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals. Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite power sliders in the Constellation tab is shifted by this offset.\n"      "\n"      "Name   Type   Description\n"      "------ ------ ----------------------------------------------------------------\n"      "Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.";
      inline static const char* const TargetId = "";



          SetDynamicRangeOffset()
            : CommandBase(CmdName, TargetId)
          {}

          SetDynamicRangeOffset(double offset)
            : CommandBase(CmdName, TargetId)
          {

            setOffset(offset);
          }


          static SetDynamicRangeOffsetPtr create(double offset)
          {
            return std::make_shared<SetDynamicRangeOffset>(offset);
          }

      static SetDynamicRangeOffsetPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetDynamicRangeOffset>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<double>::is_valid(m_values["Offset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Offset"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          double offset() const
          {
            return parse_json<double>::parse(m_values["Offset"]);
          }

          void setOffset(double offset)
          {
            m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetDynamicRangeOffset);
  }
}

