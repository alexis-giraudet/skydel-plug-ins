#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Undo the last command like Ctrl+Z in the UI
    ///
    /// 
    ///

    class UndoCmd;
    typedef std::shared_ptr<UndoCmd> UndoCmdPtr;
    
    
    class UndoCmd : public CommandBase
    {
    public:
      inline static const char* const CmdName = "UndoCmd";
      inline static const char* const Documentation = "Undo the last command like Ctrl+Z in the UI";
      inline static const char* const TargetId = "";



          UndoCmd()
            : CommandBase(CmdName, TargetId)
          {

          }


          static UndoCmdPtr create()
          {
            return std::make_shared<UndoCmd>();
          }

      static UndoCmdPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<UndoCmd>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(UndoCmd);
  }
}

