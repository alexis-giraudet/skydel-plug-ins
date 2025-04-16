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
    /// Result of GetAllSpoofTxID.
    ///
    /// Name Type         Description
    /// ---- ------------ ------------------------------------
    /// Ids  array string ID list of all spoofer transmitters.
    ///

    class GetAllSpoofTxIDResult;
    typedef std::shared_ptr<GetAllSpoofTxIDResult> GetAllSpoofTxIDResultPtr;
    
    
    class GetAllSpoofTxIDResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetAllSpoofTxIDResult";
      inline static const char* const Documentation = "Result of GetAllSpoofTxID.\n"      "\n"      "Name Type         Description\n"      "---- ------------ ------------------------------------\n"      "Ids  array string ID list of all spoofer transmitters.";
      inline static const char* const TargetId = "";



          GetAllSpoofTxIDResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetAllSpoofTxIDResult(const std::vector<std::string>& ids)
            : CommandResult(CmdName, TargetId)
          {

            setIds(ids);
          }

          GetAllSpoofTxIDResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIds(ids);
          }



          static GetAllSpoofTxIDResultPtr create(const std::vector<std::string>& ids)
          {
            return std::make_shared<GetAllSpoofTxIDResult>(ids);
          }

          static GetAllSpoofTxIDResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
          {
            return std::make_shared<GetAllSpoofTxIDResult>(relatedCommand, ids);
          }

      static GetAllSpoofTxIDResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllSpoofTxIDResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetAllSpoofTxIDResult);
  }
}

