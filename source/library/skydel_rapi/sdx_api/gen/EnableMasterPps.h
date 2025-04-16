#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnableMasterPps is deprecated since 23.11. You may use EnableMainInstanceSync.
    /// 
    /// Enable/Disable Time Synchronization on main instance.
    /// The main instance will control other Skydel simulators with main instance PPS Enabled.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------
    /// Enabled bool If true, this simulator will be the main instance to synchronize simulators.
    ///

    class EnableMasterPps;
    typedef std::shared_ptr<EnableMasterPps> EnableMasterPpsPtr;
    
    
    class EnableMasterPps : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableMasterPps";
      inline static const char* const Documentation = "Please note the command EnableMasterPps is deprecated since 23.11. You may use EnableMainInstanceSync.\n"      "\n"      "Enable/Disable Time Synchronization on main instance.\n"      "The main instance will control other Skydel simulators with main instance PPS Enabled.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------------------\n"      "Enabled bool If true, this simulator will be the main instance to synchronize simulators.";
      inline static const char* const TargetId = "";



          EnableMasterPps()
            : CommandBase(CmdName, TargetId)
          {}

          EnableMasterPps(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableMasterPpsPtr create(bool enabled)
          {
            return std::make_shared<EnableMasterPps>(enabled);
          }

      static EnableMasterPpsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableMasterPps>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableMasterPps);
  }
}

