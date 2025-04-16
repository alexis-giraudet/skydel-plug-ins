#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetWFAntennaGain is deprecated since 25.4. You may use GetWFElement.
    /// 
    /// Get The CRPA LNA gain
    ///
    /// 
    ///

    class GetWFAntennaGain;
    typedef std::shared_ptr<GetWFAntennaGain> GetWFAntennaGainPtr;
    
    
    class GetWFAntennaGain : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetWFAntennaGain";
      inline static const char* const Documentation = "Please note the command GetWFAntennaGain is deprecated since 25.4. You may use GetWFElement.\n"      "\n"      "Get The CRPA LNA gain";
      inline static const char* const TargetId = "";

      inline static const char* const Deprecated = "Please note the command GetWFAntennaGain is deprecated since 25.4. You may use GetWFElement.";



          GetWFAntennaGain()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetWFAntennaGainPtr create()
          {
            return std::make_shared<GetWFAntennaGain>();
          }

      static GetWFAntennaGainPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetWFAntennaGain>(ptr);
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
      

          std::optional<std::string> deprecated() const { return std::optional<std::string>{Deprecated}; }



          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }
    };
    REGISTER_COMMAND_TO_FACTORY(GetWFAntennaGain);
  }
}

