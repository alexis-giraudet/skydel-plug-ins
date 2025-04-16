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
    /// Result of GetActiveDataSet.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------
    /// System      string "GPS", "Galileo", "BeiDou", "QZSS", "NavIC" or "PULSAR"
    /// DataSetName string The name of the data set to set as active.
    ///

    class GetActiveDataSetResult;
    typedef std::shared_ptr<GetActiveDataSetResult> GetActiveDataSetResultPtr;
    
    
    class GetActiveDataSetResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetActiveDataSetResult";
      inline static const char* const Documentation = "Result of GetActiveDataSet.\n"      "\n"      "Name        Type   Description\n"      "----------- ------ -------------------------------------------------------\n"      "System      string \"GPS\", \"Galileo\", \"BeiDou\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"      "DataSetName string The name of the data set to set as active.";
      inline static const char* const TargetId = "";



          GetActiveDataSetResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetActiveDataSetResult(const std::string& system, const std::string& dataSetName)
            : CommandResult(CmdName, TargetId)
          {

            setSystem(system);
            setDataSetName(dataSetName);
          }

          GetActiveDataSetResult(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSystem(system);
            setDataSetName(dataSetName);
          }



          static GetActiveDataSetResultPtr create(const std::string& system, const std::string& dataSetName)
          {
            return std::make_shared<GetActiveDataSetResult>(system, dataSetName);
          }

          static GetActiveDataSetResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::string& dataSetName)
          {
            return std::make_shared<GetActiveDataSetResult>(relatedCommand, system, dataSetName);
          }

      static GetActiveDataSetResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetActiveDataSetResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["System"])
                  && parse_json<std::string>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"System", "DataSetName"}; 
        return names; 
      }
      


          std::string system() const
          {
            return parse_json<std::string>::parse(m_values["System"]);
          }

          void setSystem(const std::string& system)
          {
            m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string dataSetName() const
          {
            return parse_json<std::string>::parse(m_values["DataSetName"]);
          }

          void setDataSetName(const std::string& dataSetName)
          {
            m_values.AddMember("DataSetName", parse_json<std::string>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetActiveDataSetResult);
  }
}

