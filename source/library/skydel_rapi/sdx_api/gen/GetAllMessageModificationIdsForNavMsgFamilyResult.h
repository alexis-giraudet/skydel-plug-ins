#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAllMessageModificationIdsForNavMsgFamily.
    ///
    /// Name Type         Description
    /// ---- ------------ -------------------------------------------------------------------------
    /// Ids  array string List of event IDs which will modify the navigation message for this SV ID
    ///

    class GetAllMessageModificationIdsForNavMsgFamilyResult;
    typedef std::shared_ptr<GetAllMessageModificationIdsForNavMsgFamilyResult> GetAllMessageModificationIdsForNavMsgFamilyResultPtr;
    
    
    class GetAllMessageModificationIdsForNavMsgFamilyResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetAllMessageModificationIdsForNavMsgFamilyResult";
      inline static const char* const Documentation = "Result of GetAllMessageModificationIdsForNavMsgFamily.\n"      "\n"      "Name Type         Description\n"      "---- ------------ -------------------------------------------------------------------------\n"      "Ids  array string List of event IDs which will modify the navigation message for this SV ID";
      inline static const char* const TargetId = "";



          GetAllMessageModificationIdsForNavMsgFamilyResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetAllMessageModificationIdsForNavMsgFamilyResult(const std::vector<std::string>& ids)
            : CommandResult(CmdName, TargetId)
          {

            setIds(ids);
          }

          GetAllMessageModificationIdsForNavMsgFamilyResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIds(ids);
          }



          static GetAllMessageModificationIdsForNavMsgFamilyResultPtr create(const std::vector<std::string>& ids)
          {
            return std::make_shared<GetAllMessageModificationIdsForNavMsgFamilyResult>(ids);
          }

          static GetAllMessageModificationIdsForNavMsgFamilyResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
          {
            return std::make_shared<GetAllMessageModificationIdsForNavMsgFamilyResult>(relatedCommand, ids);
          }

      static GetAllMessageModificationIdsForNavMsgFamilyResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllMessageModificationIdsForNavMsgFamilyResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["Ids"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Ids"}; 
        return names; 
      }
      


          std::vector<std::string> ids() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["Ids"]);
          }

          void setIds(const std::vector<std::string>& ids)
          {
            m_values.AddMember("Ids", parse_json<std::vector<std::string>>::format(ids, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetAllMessageModificationIdsForNavMsgFamilyResult);
  }
}

