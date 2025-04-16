#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) the Earth mask.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------
    /// Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.
    ///

    class EnableEarthMask;
    typedef std::shared_ptr<EnableEarthMask> EnableEarthMaskPtr;
    
    
    class EnableEarthMask : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableEarthMask";
      inline static const char* const Documentation = "Enable (or disable) the Earth mask.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------------------------------------\n"      "Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.";
      inline static const char* const TargetId = "";



          EnableEarthMask()
            : CommandBase(CmdName, TargetId)
          {}

          EnableEarthMask(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableEarthMaskPtr create(bool enabled)
          {
            return std::make_shared<EnableEarthMask>(enabled);
          }

      static EnableEarthMaskPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableEarthMask>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableEarthMask);
  }
}

