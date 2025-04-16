#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set force vehicle yaw, pitch and roll to zero enabled or disabled
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------
    /// Enabled bool If true, vehicle won't rotate during simulation
    ///

    class ForceAttitudeToZero;
    typedef std::shared_ptr<ForceAttitudeToZero> ForceAttitudeToZeroPtr;
    
    
    class ForceAttitudeToZero : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ForceAttitudeToZero";
      inline static const char* const Documentation = "Set force vehicle yaw, pitch and roll to zero enabled or disabled\n"      "\n"      "Name    Type Description\n"      "------- ---- -----------------------------------------------\n"      "Enabled bool If true, vehicle won't rotate during simulation";
      inline static const char* const TargetId = "";



          ForceAttitudeToZero()
            : CommandBase(CmdName, TargetId)
          {}

          ForceAttitudeToZero(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static ForceAttitudeToZeroPtr create(bool enabled)
          {
            return std::make_shared<ForceAttitudeToZero>(enabled);
          }

      static ForceAttitudeToZeroPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ForceAttitudeToZero>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(ForceAttitudeToZero);
  }
}

