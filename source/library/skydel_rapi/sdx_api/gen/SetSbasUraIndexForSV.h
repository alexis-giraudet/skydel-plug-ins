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
    /// Set the URA index of a Sbas satellite
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.
    /// Urai        int             URA index.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetSbasUraIndexForSV;
    typedef std::shared_ptr<SetSbasUraIndexForSV> SetSbasUraIndexForSVPtr;
    
    
    class SetSbasUraIndexForSV : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetSbasUraIndexForSV";
      inline static const char* const Documentation = "Set the URA index of a Sbas satellite\n"      "\n"      "Name        Type            Description\n"      "----------- --------------- -------------------------------------------------------------------------------------------\n"      "SvId        int             The satellite SV ID, or use 0 to apply new value to all satellites.\n"      "Urai        int             URA index.\n"      "DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.";
      inline static const char* const TargetId = "";



          SetSbasUraIndexForSV()
            : CommandBase(CmdName, TargetId)
          {}

          SetSbasUraIndexForSV(int svId, int urai, const std::optional<std::string>& dataSetName = {})
            : CommandBase(CmdName, TargetId)
          {

            setSvId(svId);
            setUrai(urai);
            setDataSetName(dataSetName);
          }


          static SetSbasUraIndexForSVPtr create(int svId, int urai, const std::optional<std::string>& dataSetName = {})
          {
            return std::make_shared<SetSbasUraIndexForSV>(svId, urai, dataSetName);
          }

      static SetSbasUraIndexForSVPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetSbasUraIndexForSV>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SvId"])
                  && parse_json<int>::is_valid(m_values["Urai"])
                  && parse_json<std::optional<std::string>>::is_valid(m_values["DataSetName"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SvId", "Urai", "DataSetName"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
          }


          int svId() const
          {
            return parse_json<int>::parse(m_values["SvId"]);
          }

          void setSvId(int svId)
          {
            m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int urai() const
          {
            return parse_json<int>::parse(m_values["Urai"]);
          }

          void setUrai(int urai)
          {
            m_values.AddMember("Urai", parse_json<int>::format(urai, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(SetSbasUraIndexForSV);
  }
}

