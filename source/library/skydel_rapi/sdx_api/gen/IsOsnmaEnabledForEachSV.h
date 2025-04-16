#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if OSNMA is enabled or disabled for each satellite.
    ///
    /// 
    ///

    class IsOsnmaEnabledForEachSV;
    typedef std::shared_ptr<IsOsnmaEnabledForEachSV> IsOsnmaEnabledForEachSVPtr;
    
    
    class IsOsnmaEnabledForEachSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsOsnmaEnabledForEachSV";
      inline static const char* const Documentation = "Tells if OSNMA is enabled or disabled for each satellite.";
      inline static const char* const TargetId = "";



          IsOsnmaEnabledForEachSV()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsOsnmaEnabledForEachSVPtr create()
          {
            return std::make_shared<IsOsnmaEnabledForEachSV>();
          }

      static IsOsnmaEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsOsnmaEnabledForEachSV>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsOsnmaEnabledForEachSV);
  }
}

