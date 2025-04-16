#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasEphParamsForSV.
    ///
    /// Name           Type               Description
    /// -------------- ------------------ --------------------------------------------------------------------------
    /// SvId           int                The satellite's SV ID
    /// ParamValueDict dict string:double A dictionary of param value pairs.
    ///                                   Accepted keys are: "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z",
    ///                                                      "VelocityX", "VelocityY", "VelocityZ", "AccelerationX",
    ///                                                      "AccelerationY", "AccelerationZ", "Health", "URA" and
    ///                                                      "UraIndex"
    ///

    class GetSbasEphParamsForSVResult;
    typedef std::shared_ptr<GetSbasEphParamsForSVResult> GetSbasEphParamsForSVResultPtr;
    
    
    class GetSbasEphParamsForSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSbasEphParamsForSVResult";
      inline static const char* const Documentation = "Result of GetSbasEphParamsForSV.\n"      "\n"      "Name           Type               Description\n"      "-------------- ------------------ --------------------------------------------------------------------------\n"      "SvId           int                The satellite's SV ID\n"      "ParamValueDict dict string:double A dictionary of param value pairs.\n"      "                                  Accepted keys are: \"ClockBias\", \"RelativeFrequencyBias\", \"X\", \"Y\", \"Z\",\n"      "                                                     \"VelocityX\", \"VelocityY\", \"VelocityZ\", \"AccelerationX\",\n"      "                                                     \"AccelerationY\", \"AccelerationZ\", \"Health\", \"URA\" and\n"      "                                                     \"UraIndex\"";
      inline static const char* const TargetId = "";



          GetSbasEphParamsForSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSbasEphParamsForSVResult(int svId, const std::map<std::string, double>& paramValueDict)
            : CommandResult(CmdName, TargetId)
          {

            setSvId(svId);
            setParamValueDict(paramValueDict);
          }

          GetSbasEphParamsForSVResult(CommandBasePtr relatedCommand, int svId, const std::map<std::string, double>& paramValueDict)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSvId(svId);
            setParamValueDict(paramValueDict);
          }



          static GetSbasEphParamsForSVResultPtr create(int svId, const std::map<std::string, double>& paramValueDict)
          {
            return std::make_shared<GetSbasEphParamsForSVResult>(svId, paramValueDict);
          }

          static GetSbasEphParamsForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::map<std::string, double>& paramValueDict)
          {
            return std::make_shared<GetSbasEphParamsForSVResult>(relatedCommand, svId, paramValueDict);
          }

      static GetSbasEphParamsForSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSbasEphParamsForSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<std::map<std::string, double>>::is_valid(m_values["ParamValueDict"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "ParamValueDict"}; 
        return names; 
      }
      


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::map<std::string, double> paramValueDict() const
          {
            return parse_json<std::map<std::string, double>>::parse(m_values["ParamValueDict"]);
          }

          void setParamValueDict(const std::map<std::string, double>& paramValueDict)
          {
            m_values.AddMember("ParamValueDict", parse_json<std::map<std::string, double>>::format(paramValueDict, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSbasEphParamsForSVResult);
  }
}

