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
    /// Please note the command SetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use SetNavICNavAlertFlagForSV.
    /// 
    /// Set NavIC NAV Alert Flag
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.
    /// Alert       bool            NavIC NAV Alert Flag, false = No Alert, true = Alert
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetNavICSatelliteNavAlertFlag;
    typedef std::shared_ptr<SetNavICSatelliteNavAlertFlag> SetNavICSatelliteNavAlertFlagPtr;
    
    
    class SetNavICSatelliteNavAlertFlag : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetNavICSatelliteNavAlertFlag";
      inline static const char* const Documentation = "Please note the command SetNavICSatelliteNavAlertFlag is deprecated since 21.3. You may use SetNavICNavAlertFlagForSV.\n"      "\n"      "Set NavIC NAV Alert Flag\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.\n"      "Alert       bool            NavIC NAV Alert Flag, false = No Alert, true = Alert\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          SetNavICSatelliteNavAlertFlag()
            : CommandBase(CmdName, TargetId)
          {}

          SetNavICSatelliteNavAlertFlag(int svId, bool alert, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setAlert(alert);
            setDataSetName(dataSetName);
          }


          static SetNavICSatelliteNavAlertFlagPtr create(int svId, bool alert, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<SetNavICSatelliteNavAlertFlag>(svId, alert, dataSetName);
          }

      static SetNavICSatelliteNavAlertFlagPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetNavICSatelliteNavAlertFlag>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<bool>::is_valid(m_values["Alert"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Alert", "DataSetName"}; 
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



          bool alert() const
          {
            return parse_json<bool>::parse(m_values["Alert"]);
          }

          void setAlert(bool alert)
          {
            m_values.AddMember("Alert", parse_json<bool>::format(alert, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetNavICSatelliteNavAlertFlag);
  }
}

