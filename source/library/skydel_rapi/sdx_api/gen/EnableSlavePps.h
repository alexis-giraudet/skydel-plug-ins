#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnableSlavePps is deprecated since 23.11. You may use EnableWorkerInstanceSync.
    /// 
    /// Enable/Disable Time Synchronization on worker instance.
    /// The worker instance will wait for the main instance to synchronize the simulators.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------
    /// Enabled bool If true, this simulator will wait for the main instance to synchronize simulators.
    ///

    class EnableSlavePps;
    typedef std::shared_ptr<EnableSlavePps> EnableSlavePpsPtr;
    
    
    class EnableSlavePps : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableSlavePps";
      inline static const char* const Documentation = "Please note the command EnableSlavePps is deprecated since 23.11. You may use EnableWorkerInstanceSync.\n"      "\n"      "Enable/Disable Time Synchronization on worker instance.\n"      "The worker instance will wait for the main instance to synchronize the simulators.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------------------------\n"      "Enabled bool If true, this simulator will wait for the main instance to synchronize simulators.";
      inline static const char* const TargetId = "";



          EnableSlavePps()
            : CommandBase(CmdName, TargetId)
          {}

          EnableSlavePps(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableSlavePpsPtr create(bool enabled)
          {
            return std::make_shared<EnableSlavePps>(enabled);
          }

      static EnableSlavePpsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableSlavePps>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableSlavePps);
  }
}

