#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNavICEphDoubleParamForEachSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- --------------------------------------------------------------------------------------------------
    /// ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names
    /// Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetNavICEphDoubleParamForEachSVResult;
    typedef std::shared_ptr<GetNavICEphDoubleParamForEachSVResult> GetNavICEphDoubleParamForEachSVResultPtr;
    typedef GetNavICEphDoubleParamForEachSVResult GetNavICEphemerisDoubleParamsResult;
    typedef std::shared_ptr<GetNavICEphemerisDoubleParamsResult> GetNavICEphemerisDoubleParamsResultPtr;
    
    class GetNavICEphDoubleParamForEachSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetNavICEphDoubleParamForEachSVResult";
      inline static const char* const Documentation = "Result of GetNavICEphDoubleParamForEachSV.\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- --------------------------------------------------------------------------------------------------\n"      "ParamName   string          Refer to SetNavICEphDoubleParamForSV for accepted names\n"      "Val         array double    Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetNavICEphDoubleParamForEachSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetNavICEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId)
          {

            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }

          GetNavICEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName = {})
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setParamName(paramName);
            setVal(val);
            setDataSetName(dataSetName);
          }



          static GetNavICEphDoubleParamForEachSVResultPtr create(const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetNavICEphDoubleParamForEachSVResult>(paramName, val, dataSetName);
          }

          static GetNavICEphDoubleParamForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetNavICEphDoubleParamForEachSVResult>(relatedCommand, paramName, val, dataSetName);
          }

      static GetNavICEphDoubleParamForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetNavICEphDoubleParamForEachSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["ParamName"])
                  && parse_json<std::vector<double>>::is_valid(m_values["Val"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"ParamName", "Val", "DataSetName"}; 
        return names; 
      }
      


          std::string paramName() const
          {
            return parse_json<std::string>::parse(m_values["ParamName"]);
          }

          void setParamName(const std::string& paramName)
          {
            m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::vector<double> val() const
          {
            return parse_json<std::vector<double>>::parse(m_values["Val"]);
          }

          void setVal(const std::vector<double>& val)
          {
            m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::optional<std::string> dataSetName() const
          {
            return parse_json<std::optional<std::string>>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::optional<std::string>& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetNavICEphDoubleParamForEachSVResult);
  }
}

