#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA MAC look-up table ID.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------------------------------------------------------------------------------------------
    /// MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36, 37, 38, 39, 40 and 41.
    ///              Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.
    ///

    class SetOsnmaMacLtId;
    typedef std::shared_ptr<SetOsnmaMacLtId> SetOsnmaMacLtIdPtr;
    
    
    class SetOsnmaMacLtId : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetOsnmaMacLtId";
      inline static const char* const Documentation = "Set OSNMA MAC look-up table ID.\n"      "\n"      "Name    Type Description\n"      "------- ---- ---------------------------------------------------------------------------------------------------------------------------\n"      "MacLtId int  MAC look-up table ID to get associated ADKD sequences. Accepted IDs are: 27, 28, 31, 33, 34, 35, 36, 37, 38, 39, 40 and 41.\n"      "             Note: The MAC look-up table can be found in Galileo OSNMA SIS ICD v1.1 - ANNEX C MAC Look-up Table.";
      inline static const char* const TargetId = "";



          SetOsnmaMacLtId()
            : CommandBase(CmdName, TargetId)
          {}

          SetOsnmaMacLtId(int macLtId)
            : CommandBase(CmdName, TargetId)
          {

            setMacLtId(macLtId);
          }


          static SetOsnmaMacLtIdPtr create(int macLtId)
          {
            return std::make_shared<SetOsnmaMacLtId>(macLtId);
          }

      static SetOsnmaMacLtIdPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetOsnmaMacLtId>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["MacLtId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"MacLtId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int macLtId() const
          {
            return parse_json<int>::parse(m_values["MacLtId"]);
          }

          void setMacLtId(int macLtId)
          {
            m_values.AddMember("MacLtId", parse_json<int>::format(macLtId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(SetOsnmaMacLtId);
  }
}

