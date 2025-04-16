#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIonoGridMask.
    ///
    /// Name            Type   Description
    /// --------------- ------ -------------------------------
    /// ServiceProvider string The service provider
    /// Band            int    The ionospheric grid band index
    /// Point           int    The IGP index
    /// Flag            bool   Is the IGP monitored
    ///

    class GetIonoGridMaskResult;
    typedef std::shared_ptr<GetIonoGridMaskResult> GetIonoGridMaskResultPtr;
    
    
    class GetIonoGridMaskResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetIonoGridMaskResult";
      inline static const char* const Documentation = "Result of GetIonoGridMask.\n"      "\n"      "Name            Type   Description\n"      "--------------- ------ -------------------------------\n"      "ServiceProvider string The service provider\n"      "Band            int    The ionospheric grid band index\n"      "Point           int    The IGP index\n"      "Flag            bool   Is the IGP monitored";
      inline static const char* const TargetId = "";



          GetIonoGridMaskResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetIonoGridMaskResult(const std::string& serviceProvider, int band, int point, bool flag)
            : CommandResult(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setBand(band);
            setPoint(point);
            setFlag(flag);
          }

          GetIonoGridMaskResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int band, int point, bool flag)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setServiceProvider(serviceProvider);
            setBand(band);
            setPoint(point);
            setFlag(flag);
          }



          static GetIonoGridMaskResultPtr create(const std::string& serviceProvider, int band, int point, bool flag)
          {
            return std::make_shared<GetIonoGridMaskResult>(serviceProvider, band, point, flag);
          }

          static GetIonoGridMaskResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int band, int point, bool flag)
          {
            return std::make_shared<GetIonoGridMaskResult>(relatedCommand, serviceProvider, band, point, flag);
          }

      static GetIonoGridMaskResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIonoGridMaskResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
                  && parse_json<int>::is_valid(m_values["Band"])
                  && parse_json<int>::is_valid(m_values["Point"])
                  && parse_json<bool>::is_valid(m_values["Flag"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ServiceProvider", "Band", "Point", "Flag"}; 
        return names; 
      }
      


          std::string serviceProvider() const
          {
            return parse_json<std::string>::parse(m_values["ServiceProvider"]);
          }

          void setServiceProvider(const std::string& serviceProvider)
          {
            m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
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



          bool flag() const
          {
            return parse_json<bool>::parse(m_values["Flag"]);
          }

          void setFlag(bool flag)
          {
            m_values.AddMember("Flag", parse_json<bool>::format(flag, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIonoGridMaskResult);
  }
}

