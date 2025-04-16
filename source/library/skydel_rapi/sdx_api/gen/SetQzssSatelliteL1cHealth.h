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
    /// Please note the command SetQzssSatelliteL1cHealth is deprecated since 21.3. You may use SetQzssL1cHealthForSV.
    /// 
    /// Set QZSS L1C health (Health of L1C signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L1C health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssSatelliteL1cHealth;
    typedef std::shared_ptr<SetQzssSatelliteL1cHealth> SetQzssSatelliteL1cHealthPtr;
    
    
    class SetQzssSatelliteL1cHealth : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetQzssSatelliteL1cHealth";
      inline static const char* const Documentation = "Please note the command SetQzssSatelliteL1cHealth is deprecated since 21.3. You may use SetQzssL1cHealthForSV.\n"      "\n"      "Set QZSS L1C health (Health of L1C signal)\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.\n"      "Health      bool            L1C health, false = signal OK, true = signal bad\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          SetQzssSatelliteL1cHealth()
            : CommandBase(CmdName, TargetId)
          {}

          SetQzssSatelliteL1cHealth(int svId, bool health, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setHealth(health);
            setDataSetName(dataSetName);
          }


          static SetQzssSatelliteL1cHealthPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<SetQzssSatelliteL1cHealth>(svId, health, dataSetName);
          }

      static SetQzssSatelliteL1cHealthPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetQzssSatelliteL1cHealth>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<bool>::is_valid(m_values["Health"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Health", "DataSetName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
          }


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          bool health() const
          {
            return parse_json<bool>::parse(m_values["Health"]);
          }

          void setHealth(bool health)
          {
            m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetQzssSatelliteL1cHealth);
  }
}

