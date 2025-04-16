#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use GetGpsConfigurationForEachSV.
    /// 
    /// Get GPS SV configuration flag for each SVs
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsSVConfigurationForAllSat;
    typedef std::shared_ptr<GetGpsSVConfigurationForAllSat> GetGpsSVConfigurationForAllSatPtr;
    
    
    class GetGpsSVConfigurationForAllSat : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetGpsSVConfigurationForAllSat";
      inline static const char* const Documentation = "Please note the command GetGpsSVConfigurationForAllSat is deprecated since 21.3. You may use GetGpsConfigurationForEachSV.\n"      "\n"      "Get GPS SV configuration flag for each SVs\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          GetGpsSVConfigurationForAllSat(const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setDataSetName(dataSetName);
          }


          static GetGpsSVConfigurationForAllSatPtr create(const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<GetGpsSVConfigurationForAllSat>(dataSetName);
          }

      static GetGpsSVConfigurationForAllSatPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGpsSVConfigurationForAllSat>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"DataSetName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(GetGpsSVConfigurationForAllSat);
  }
}

