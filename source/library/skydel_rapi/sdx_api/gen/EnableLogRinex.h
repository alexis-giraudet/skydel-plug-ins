#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) ephemeris data logging in RINEX v3.03 format
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------
    /// Enabled bool If true, files will be created during simulation
    ///

    class EnableLogRinex;
    typedef std::shared_ptr<EnableLogRinex> EnableLogRinexPtr;
    
    
    class EnableLogRinex : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableLogRinex";
      inline static const char* const Documentation = "Enable (or disable) ephemeris data logging in RINEX v3.03 format\n"      "\n"      "Name    Type Description\n"      "------- ---- ------------------------------------------------\n"      "Enabled bool If true, files will be created during simulation";
      inline static const char* const TargetId = "";



          EnableLogRinex()
            : CommandBase(CmdName, TargetId)
          {}

          EnableLogRinex(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableLogRinexPtr create(bool enabled)
          {
            return std::make_shared<EnableLogRinex>(enabled);
          }

      static EnableLogRinexPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableLogRinex>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableLogRinex);
  }
}

