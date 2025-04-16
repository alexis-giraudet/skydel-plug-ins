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
    /// Result of GetQzssL1SAugmentations.
    ///
    /// Name Type         Description
    /// ---- ------------ --------------------------------------
    /// Ids  array string List of IDs of QZSS L1S augmentations.
    ///

    class GetQzssL1SAugmentationsResult;
    typedef std::shared_ptr<GetQzssL1SAugmentationsResult> GetQzssL1SAugmentationsResultPtr;
    
    
    class GetQzssL1SAugmentationsResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetQzssL1SAugmentationsResult";
      inline static const char* const Documentation = "Result of GetQzssL1SAugmentations.\n"      "\n"      "Name Type         Description\n"      "---- ------------ --------------------------------------\n"      "Ids  array string List of IDs of QZSS L1S augmentations.";
      inline static const char* const TargetId = "";



          GetQzssL1SAugmentationsResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetQzssL1SAugmentationsResult(const std::vector<std::string>& ids)
            : CommandResult(CmdName, TargetId)
          {

            setIds(ids);
          }

          GetQzssL1SAugmentationsResult(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setIds(ids);
          }



          static GetQzssL1SAugmentationsResultPtr create(const std::vector<std::string>& ids)
          {
            return std::make_shared<GetQzssL1SAugmentationsResult>(ids);
          }

          static GetQzssL1SAugmentationsResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& ids)
          {
            return std::make_shared<GetQzssL1SAugmentationsResult>(relatedCommand, ids);
          }

      static GetQzssL1SAugmentationsResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetQzssL1SAugmentationsResult>(ptr);
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
    REGISTER_COMMAND_TO_FACTORY(GetQzssL1SAugmentationsResult);
  }
}

