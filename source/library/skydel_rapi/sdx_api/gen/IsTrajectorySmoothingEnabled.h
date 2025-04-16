#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get trajectory smoothing for Track or Route enabled or disabled
    ///
    /// 
    ///

    class IsTrajectorySmoothingEnabled;
    typedef std::shared_ptr<IsTrajectorySmoothingEnabled> IsTrajectorySmoothingEnabledPtr;
    
    
    class IsTrajectorySmoothingEnabled : public CommandBase
    {
    public:
      inline static const char* const CmdName = "IsTrajectorySmoothingEnabled";
      inline static const char* const Documentation = "Get trajectory smoothing for Track or Route enabled or disabled";
      inline static const char* const TargetId = "";



          IsTrajectorySmoothingEnabled()
            : CommandBase(CmdName, TargetId)
          {

          }


          static IsTrajectorySmoothingEnabledPtr create()
          {
            return std::make_shared<IsTrajectorySmoothingEnabled>();
          }

      static IsTrajectorySmoothingEnabledPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<IsTrajectorySmoothingEnabled>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(IsTrajectorySmoothingEnabled);
  }
}

