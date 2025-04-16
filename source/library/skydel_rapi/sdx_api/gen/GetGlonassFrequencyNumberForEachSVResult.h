#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassFrequencyNumberForEachSV
    ///
    /// Name            Type      Description
    /// --------------- --------- --------------------------------------------------------------------------------------------------
    /// FrequencyNumber array int Frequency number of each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetGlonassFrequencyNumberForEachSVResult;
    typedef std::shared_ptr<GetGlonassFrequencyNumberForEachSVResult> GetGlonassFrequencyNumberForEachSVResultPtr;
    
    
    class GetGlonassFrequencyNumberForEachSVResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGlonassFrequencyNumberForEachSVResult";
      inline static const char* const Documentation = "Result of GetGlonassFrequencyNumberForEachSV\n"      "\n"      "Name            Type      Description\n"      "--------------- --------- --------------------------------------------------------------------------------------------------\n"      "FrequencyNumber array int Frequency number of each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
      inline static const char* const TargetId = "";



          GetGlonassFrequencyNumberForEachSVResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGlonassFrequencyNumberForEachSVResult(const std::vector<int>& frequencyNumber)
            : CommandResult(CmdName, TargetId)
          {

            setFrequencyNumber(frequencyNumber);
          }

          GetGlonassFrequencyNumberForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setFrequencyNumber(frequencyNumber);
          }



          static GetGlonassFrequencyNumberForEachSVResultPtr create(const std::vector<int>& frequencyNumber)
          {
            return std::make_shared<GetGlonassFrequencyNumberForEachSVResult>(frequencyNumber);
          }

          static GetGlonassFrequencyNumberForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber)
          {
            return std::make_shared<GetGlonassFrequencyNumberForEachSVResult>(relatedCommand, frequencyNumber);
          }

      static GetGlonassFrequencyNumberForEachSVResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGlonassFrequencyNumberForEachSVResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<int>>::is_valid(m_values["FrequencyNumber"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"FrequencyNumber"}; 
        return names; 
      }
      


          std::vector<int> frequencyNumber() const
          {
            return parse_json<std::vector<int>>::parse(m_values["FrequencyNumber"]);
          }

          void setFrequencyNumber(const std::vector<int>& frequencyNumber)
          {
            m_values.AddMember("FrequencyNumber", parse_json<std::vector<int>>::format(frequencyNumber, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetGlonassFrequencyNumberForEachSVResult);
  }
}

