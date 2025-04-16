#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) extrapolation of the almanac from the ephemeris in Dynamic SV Data mode.
    /// When disabled, use PushDynamicAlmanacData to push the almanac data
    ///
    /// Name    Type Description
    /// ------- ---- -------------------------------
    /// Enabled bool State of almanac extrapolation.
    ///

    class EnableAlmanacExtrapolationFromEphemeris;
    typedef std::shared_ptr<EnableAlmanacExtrapolationFromEphemeris> EnableAlmanacExtrapolationFromEphemerisPtr;
    
    
    class EnableAlmanacExtrapolationFromEphemeris : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableAlmanacExtrapolationFromEphemeris";
      inline static const char* const Documentation = "Enable (or disable) extrapolation of the almanac from the ephemeris in Dynamic SV Data mode.\n"      "When disabled, use PushDynamicAlmanacData to push the almanac data\n"      "\n"      "Name    Type Description\n"      "------- ---- -------------------------------\n"      "Enabled bool State of almanac extrapolation.";
      inline static const char* const TargetId = "";



          EnableAlmanacExtrapolationFromEphemeris()
            : CommandBase(CmdName, TargetId)
          {}

          EnableAlmanacExtrapolationFromEphemeris(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableAlmanacExtrapolationFromEphemerisPtr create(bool enabled)
          {
            return std::make_shared<EnableAlmanacExtrapolationFromEphemeris>(enabled);
          }

      static EnableAlmanacExtrapolationFromEphemerisPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableAlmanacExtrapolationFromEphemeris>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableAlmanacExtrapolationFromEphemeris);
  }
}

