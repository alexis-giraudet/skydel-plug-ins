#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) raw data logging (pseudorange, antenna gain, receiver position, satellite position, etc.)
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------
    /// Enabled bool If true, file will be created during simulation
    ///

    class EnableLogRaw;
    typedef std::shared_ptr<EnableLogRaw> EnableLogRawPtr;
    
    
    class EnableLogRaw : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableLogRaw";
      inline static const char* const Documentation = "Enable (or disable) raw data logging (pseudorange, antenna gain, receiver position, satellite position, etc.)\n"      "\n"      "Name    Type Description\n"      "------- ---- -----------------------------------------------\n"      "Enabled bool If true, file will be created during simulation";
      inline static const char* const TargetId = "";



          EnableLogRaw()
            : CommandBase(CmdName, TargetId)
          {}

          EnableLogRaw(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableLogRawPtr create(bool enabled)
          {
            return std::make_shared<EnableLogRaw>(enabled);
          }

      static EnableLogRawPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableLogRaw>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableLogRaw);
  }
}

