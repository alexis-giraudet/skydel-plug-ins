#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clear all antenna changes.
    ///
    /// 
    ///

    class ClearAllAntennaChanges;
    typedef std::shared_ptr<ClearAllAntennaChanges> ClearAllAntennaChangesPtr;
    
    
    class ClearAllAntennaChanges : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ClearAllAntennaChanges";
      inline static const char* const Documentation = "Clear all antenna changes.";
      inline static const char* const TargetId = "";



          ClearAllAntennaChanges()
            : CommandBase(CmdName, TargetId)
          {

          }


          static ClearAllAntennaChangesPtr create()
          {
            return std::make_shared<ClearAllAntennaChanges>();
          }

      static ClearAllAntennaChangesPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ClearAllAntennaChanges>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(ClearAllAntennaChanges);
  }
}

