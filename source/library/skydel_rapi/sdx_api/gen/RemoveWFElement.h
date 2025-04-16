#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove last Wavefront element.
    ///
    /// 
    ///

    class RemoveWFElement;
    typedef std::shared_ptr<RemoveWFElement> RemoveWFElementPtr;
    
    
    class RemoveWFElement : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveWFElement";
      inline static const char* const Documentation = "Remove last Wavefront element.";
      inline static const char* const TargetId = "";



          RemoveWFElement()
            : CommandBase(CmdName, TargetId)
          {

          }


          static RemoveWFElementPtr create()
          {
            return std::make_shared<RemoveWFElement>();
          }

      static RemoveWFElementPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveWFElement>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(RemoveWFElement);
  }
}

