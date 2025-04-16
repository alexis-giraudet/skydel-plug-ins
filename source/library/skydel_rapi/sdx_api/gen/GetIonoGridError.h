#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the error offset for a ionospheric grid point
    ///
    /// Name  Type Description
    /// ----- ---- -------------------------------
    /// Band  int  The ionospheric grid band index
    /// Point int  The IGP index
    ///

    class GetIonoGridError;
    typedef std::shared_ptr<GetIonoGridError> GetIonoGridErrorPtr;
    
    
    class GetIonoGridError : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetIonoGridError";
      inline static const char* const Documentation = "Get the error offset for a ionospheric grid point\n"      "\n"      "Name  Type Description\n"      "----- ---- -------------------------------\n"      "Band  int  The ionospheric grid band index\n"      "Point int  The IGP index";
      inline static const char* const TargetId = "";



          GetIonoGridError()
            : CommandBase(CmdName, TargetId)
          {}

          GetIonoGridError(int band, int point)
            : CommandBase(CmdName, TargetId)
          {

            setBand(band);
            setPoint(point);
          }


          static GetIonoGridErrorPtr create(int band, int point)
          {
            return std::make_shared<GetIonoGridError>(band, point);
          }

      static GetIonoGridErrorPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIonoGridError>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Band"])
                  && parse_json<int>::is_valid(m_values["Point"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Band", "Point"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int band() const
          {
            return parse_json<int>::parse(m_values["Band"]);
          }

          void setBand(int band)
          {
            m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int point() const
          {
            return parse_json<int>::parse(m_values["Point"]);
          }

          void setPoint(int point)
          {
            m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIonoGridError);
  }
}

