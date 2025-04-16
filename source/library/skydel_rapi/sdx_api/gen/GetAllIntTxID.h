#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the ID of all interferences transmitters.
    ///
    /// 
    ///

    class GetAllIntTxID;
    typedef std::shared_ptr<GetAllIntTxID> GetAllIntTxIDPtr;
    
    
    class GetAllIntTxID : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetAllIntTxID";
      inline static const char* const Documentation = "Get the ID of all interferences transmitters.";
      inline static const char* const TargetId = "";



          GetAllIntTxID()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetAllIntTxIDPtr create()
          {
            return std::make_shared<GetAllIntTxID>();
          }

      static GetAllIntTxIDPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllIntTxID>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetAllIntTxID);
  }
}

