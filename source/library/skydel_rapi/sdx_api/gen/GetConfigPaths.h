#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a list of paths for all the files in the Configurations folder.
    ///
    /// 
    ///

    class GetConfigPaths;
    typedef std::shared_ptr<GetConfigPaths> GetConfigPathsPtr;
    
    
    class GetConfigPaths : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetConfigPaths";
      inline static const char* const Documentation = "Get a list of paths for all the files in the Configurations folder.";
      inline static const char* const TargetId = "";



          GetConfigPaths()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetConfigPathsPtr create()
          {
            return std::make_shared<GetConfigPaths>();
          }

      static GetConfigPathsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetConfigPaths>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetConfigPaths);
  }
}

