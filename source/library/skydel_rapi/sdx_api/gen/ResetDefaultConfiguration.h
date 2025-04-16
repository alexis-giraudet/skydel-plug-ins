#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Reset the default configuration.
    ///
    /// 
    ///

    class ResetDefaultConfiguration;
    typedef std::shared_ptr<ResetDefaultConfiguration> ResetDefaultConfigurationPtr;
    
    
    class ResetDefaultConfiguration : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ResetDefaultConfiguration";
      inline static const char* const Documentation = "Reset the default configuration.";
      inline static const char* const TargetId = "";



          ResetDefaultConfiguration()
            : CommandBase(CmdName, TargetId)
          {

          }


          static ResetDefaultConfigurationPtr create()
          {
            return std::make_shared<ResetDefaultConfiguration>();
          }

      static ResetDefaultConfigurationPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ResetDefaultConfiguration>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(ResetDefaultConfiguration);
  }
}

