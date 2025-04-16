#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set trajectory smoothing for Track or Route enabled or disabled
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------
    /// Enabled bool If true, trajectory will be smoothed during simulation
    ///

    class EnableTrajectorySmoothing;
    typedef std::shared_ptr<EnableTrajectorySmoothing> EnableTrajectorySmoothingPtr;
    
    
    class EnableTrajectorySmoothing : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableTrajectorySmoothing";
      inline static const char* const Documentation = "Set trajectory smoothing for Track or Route enabled or disabled\n"      "\n"      "Name    Type Description\n"      "------- ---- ------------------------------------------------------\n"      "Enabled bool If true, trajectory will be smoothed during simulation";
      inline static const char* const TargetId = "";



          EnableTrajectorySmoothing()
            : CommandBase(CmdName, TargetId)
          {}

          EnableTrajectorySmoothing(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableTrajectorySmoothingPtr create(bool enabled)
          {
            return std::make_shared<EnableTrajectorySmoothing>(enabled);
          }

      static EnableTrajectorySmoothingPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableTrajectorySmoothing>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableTrajectorySmoothing);
  }
}

