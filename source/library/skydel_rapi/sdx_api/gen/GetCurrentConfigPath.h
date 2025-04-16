#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the config file path currently used by Skydel.
    ///
    /// 
    ///

    class GetCurrentConfigPath;
    typedef std::shared_ptr<GetCurrentConfigPath> GetCurrentConfigPathPtr;
    
    
    class GetCurrentConfigPath : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetCurrentConfigPath";
      inline static const char* const Documentation = "Get the config file path currently used by Skydel.";
      inline static const char* const TargetId = "";



          GetCurrentConfigPath()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetCurrentConfigPathPtr create()
          {
            return std::make_shared<GetCurrentConfigPath>();
          }

      static GetCurrentConfigPathPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetCurrentConfigPath>(ptr);
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
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetCurrentConfigPath);
  }
}

