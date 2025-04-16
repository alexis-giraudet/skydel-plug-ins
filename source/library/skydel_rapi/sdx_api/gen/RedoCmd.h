#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Redo the last undone command like Ctrl+Shift+Z in the UI
    ///
    /// 
    ///

    class RedoCmd;
    typedef std::shared_ptr<RedoCmd> RedoCmdPtr;
    
    
    class RedoCmd : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RedoCmd";
      inline static const char* const Documentation = "Redo the last undone command like Ctrl+Shift+Z in the UI";
      inline static const char* const TargetId = "";



          RedoCmd()
            : CommandBase(CmdName, TargetId)
          {

          }


          static RedoCmdPtr create()
          {
            return std::make_shared<RedoCmd>();
          }

      static RedoCmdPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RedoCmd>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(RedoCmd);
  }
}

