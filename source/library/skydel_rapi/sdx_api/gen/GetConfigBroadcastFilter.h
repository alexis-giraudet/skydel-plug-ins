#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the filter for configuration broadcast.
    ///
    /// 
    ///

    class GetConfigBroadcastFilter;
    typedef std::shared_ptr<GetConfigBroadcastFilter> GetConfigBroadcastFilterPtr;
    
    
    class GetConfigBroadcastFilter : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetConfigBroadcastFilter";
      inline static const char* const Documentation = "Get the filter for configuration broadcast.";
      inline static const char* const TargetId = "";



          GetConfigBroadcastFilter()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetConfigBroadcastFilterPtr create()
          {
            return std::make_shared<GetConfigBroadcastFilter>();
          }

      static GetConfigBroadcastFilterPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetConfigBroadcastFilter>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetConfigBroadcastFilter);
  }
}

