#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetOsnmaTagSize.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------
    /// TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.
    ///

    class GetOsnmaTagSizeResult;
    typedef std::shared_ptr<GetOsnmaTagSizeResult> GetOsnmaTagSizeResultPtr;
    
    
    class GetOsnmaTagSizeResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetOsnmaTagSizeResult";
      inline static const char* const Documentation = "Result of GetOsnmaTagSize.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------\n"      "TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.";
      inline static const char* const TargetId = "";



          GetOsnmaTagSizeResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetOsnmaTagSizeResult(int tagSize)
            : CommandResult(CmdName, TargetId)
          {

            setTagSize(tagSize);
          }

          GetOsnmaTagSizeResult(CommandBasePtr relatedCommand, int tagSize)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setTagSize(tagSize);
          }



          static GetOsnmaTagSizeResultPtr create(int tagSize)
          {
            return std::make_shared<GetOsnmaTagSizeResult>(tagSize);
          }

          static GetOsnmaTagSizeResultPtr create(CommandBasePtr relatedCommand, int tagSize)
          {
            return std::make_shared<GetOsnmaTagSizeResult>(relatedCommand, tagSize);
          }

      static GetOsnmaTagSizeResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetOsnmaTagSizeResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["TagSize"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"TagSize"}; 
        return names; 
      }
      


          int tagSize() const
          {
            return parse_json<int>::parse(m_values["TagSize"]);
          }

          void setTagSize(int tagSize)
          {
            m_values.AddMember("TagSize", parse_json<int>::format(tagSize, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetOsnmaTagSizeResult);
  }
}

