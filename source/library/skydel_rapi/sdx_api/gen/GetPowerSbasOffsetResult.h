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
    /// Result of GetPowerSbasOffset.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------
    /// ServiceProvider string Service Provider key, allowed values: "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM"
    /// Offset          double Offset in dB (negative value will attenuate signal)
    ///

    class GetPowerSbasOffsetResult;
    typedef std::shared_ptr<GetPowerSbasOffsetResult> GetPowerSbasOffsetResultPtr;
    
    
    class GetPowerSbasOffsetResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetPowerSbasOffsetResult";
      inline static const char* const Documentation = "Result of GetPowerSbasOffset.\n"      "\n"      "Name            Type   Description\n"      "--------------- ------ ------------------------------------------------------------------------------\n"      "ServiceProvider string Service Provider key, allowed values: \"WAAS\", \"EGNOS\", \"MSAS\", \"GAGAN\", \"SDCM\"\n"      "Offset          double Offset in dB (negative value will attenuate signal)";
      inline static const char* const TargetId = "";



          GetPowerSbasOffsetResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetPowerSbasOffsetResult(const std::string& serviceProvider, double offset)
            : CommandResult(CmdName, TargetId)
          {

            setServiceProvider(serviceProvider);
            setOffset(offset);
          }

          GetPowerSbasOffsetResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, double offset)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setServiceProvider(serviceProvider);
            setOffset(offset);
          }



          static GetPowerSbasOffsetResultPtr create(const std::string& serviceProvider, double offset)
          {
            return std::make_shared<GetPowerSbasOffsetResult>(serviceProvider, offset);
          }

          static GetPowerSbasOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, double offset)
          {
            return std::make_shared<GetPowerSbasOffsetResult>(relatedCommand, serviceProvider, offset);
          }

      static GetPowerSbasOffsetResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetPowerSbasOffsetResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
                  && parse_json<double>::is_valid(m_values["Offset"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ServiceProvider", "Offset"}; 
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



          double offset() const
          {
            return parse_json<double>::parse(m_values["Offset"]);
          }

          void setOffset(double offset)
          {
            m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetPowerSbasOffsetResult);
  }
}

