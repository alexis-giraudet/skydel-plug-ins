#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// Enabled bool If true, signal strengh model is enabled for all satellites
    ///

    class EnableSignalStrengthModel;
    typedef std::shared_ptr<EnableSignalStrengthModel> EnableSignalStrengthModelPtr;
    
    
    class EnableSignalStrengthModel : public CommandBase
    {
    public:
      inline static const char* const CmdName = "EnableSignalStrengthModel";
      inline static const char* const Documentation = "Set signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle\n"      "\n"      "Name    Type Description\n"      "------- ---- -----------------------------------------------------------\n"      "Enabled bool If true, signal strengh model is enabled for all satellites";
      inline static const char* const TargetId = "";



          EnableSignalStrengthModel()
            : CommandBase(CmdName, TargetId)
          {}

          EnableSignalStrengthModel(bool enabled)
            : CommandBase(CmdName, TargetId)
          {

            setEnabled(enabled);
          }


          static EnableSignalStrengthModelPtr create(bool enabled)
          {
            return std::make_shared<EnableSignalStrengthModel>(enabled);
          }

      static EnableSignalStrengthModelPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<EnableSignalStrengthModel>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(EnableSignalStrengthModel);
  }
}

