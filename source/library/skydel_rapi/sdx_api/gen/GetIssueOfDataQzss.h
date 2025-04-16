#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
    ///
    /// 
    ///

    class GetIssueOfDataQzss;
    typedef std::shared_ptr<GetIssueOfDataQzss> GetIssueOfDataQzssPtr;
    
    
    class GetIssueOfDataQzss : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetIssueOfDataQzss";
      inline static const char* const Documentation = "Get QZSS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)";
      inline static const char* const TargetId = "";



          GetIssueOfDataQzss()
            : CommandBase(CmdName, TargetId)
          {

          }


          static GetIssueOfDataQzssPtr create()
          {
            return std::make_shared<GetIssueOfDataQzss>();
          }

      static GetIssueOfDataQzssPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIssueOfDataQzss>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetIssueOfDataQzss);
  }
}

