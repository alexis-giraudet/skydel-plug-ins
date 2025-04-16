#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get OSNMA MAC look-up table ID.
    ///
    /// 
    ///

    class GetOsnmaMacLtId;
    typedef std::shared_ptr<GetOsnmaMacLtId> GetOsnmaMacLtIdPtr;
    
    
    class GetOsnmaMacLtId : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetOsnmaMacLtId";
      inline static const char* const Documentation = "Get OSNMA MAC look-up table ID.";
      inline static const char* const TargetId = "";



          GetOsnmaMacLtId()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetOsnmaMacLtIdPtr create()
          {
            return std::make_shared<GetOsnmaMacLtId>();
          }

      static GetOsnmaMacLtIdPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetOsnmaMacLtId>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetOsnmaMacLtId);
  }
}

