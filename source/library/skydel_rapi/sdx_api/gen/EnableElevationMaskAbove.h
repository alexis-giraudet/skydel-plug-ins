#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------
    /// Enabled bool If true, mask satellites with elevation angle above masking angle.
    ///

    class EnableElevationMaskAbove;
    typedef std::shared_ptr<EnableElevationMaskAbove> EnableElevationMaskAbovePtr;
    
    
    class EnableElevationMaskAbove : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableElevationMaskAbove";
      inline static const char* const Documentation = "Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).\n"      "\n"      "Name    Type Description\n"      "------- ---- ------------------------------------------------------------------\n"      "Enabled bool If true, mask satellites with elevation angle above masking angle.";
      inline static const char* const TargetId = "";



          EnableElevationMaskAbove()
            : CommandBase(CmdName, TargetId)
          {}

          EnableElevationMaskAbove(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableElevationMaskAbovePtr create(bool enabled)
          {
            return std::make_shared<EnableElevationMaskAbove>(enabled);
          }

      static EnableElevationMaskAbovePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableElevationMaskAbove>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<bool>::is_valid(m_values["Enabled"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Enabled"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          bool enabled() const
          {
            return parse_json<bool>::parse(m_values["Enabled"]);
          }

          void setEnabled(bool enabled)
          {
            m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(EnableElevationMaskAbove);
  }
}

