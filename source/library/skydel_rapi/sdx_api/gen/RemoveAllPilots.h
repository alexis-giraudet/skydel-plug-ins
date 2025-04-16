#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove all pilots on all outputs
    ///
    /// 
    ///

    class RemoveAllPilots;
    typedef std::shared_ptr<RemoveAllPilots> RemoveAllPilotsPtr;
    
    
    class RemoveAllPilots : public CommandBase
    {
    public:
      inline static const char* const CmdName = "RemoveAllPilots";
      inline static const char* const Documentation = "Remove all pilots on all outputs";
      inline static const char* const TargetId = "";



          RemoveAllPilots()
            : CommandBase(CmdName, TargetId)
          {

          }


          static RemoveAllPilotsPtr create()
          {
            return std::make_shared<RemoveAllPilots>();
          }

      static RemoveAllPilotsPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<RemoveAllPilots>(ptr);
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
            return EXECUTE_IF_SIMULATING;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(RemoveAllPilots);
  }
}

