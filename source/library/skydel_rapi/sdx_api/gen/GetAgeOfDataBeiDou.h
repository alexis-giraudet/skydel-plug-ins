#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou Age of data, Ephemeris (AODE) and Age of data, Clock (AODC)
    ///
    /// 
    ///

    class GetAgeOfDataBeiDou;
    typedef std::shared_ptr<GetAgeOfDataBeiDou> GetAgeOfDataBeiDouPtr;
    
    
    class GetAgeOfDataBeiDou : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetAgeOfDataBeiDou";
      inline static const char* const Documentation = "Get BeiDou Age of data, Ephemeris (AODE) and Age of data, Clock (AODC)";
      inline static const char* const TargetId = "";



          GetAgeOfDataBeiDou()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetAgeOfDataBeiDouPtr create()
          {
            return std::make_shared<GetAgeOfDataBeiDou>();
          }

      static GetAgeOfDataBeiDouPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAgeOfDataBeiDou>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetAgeOfDataBeiDou);
  }
}

