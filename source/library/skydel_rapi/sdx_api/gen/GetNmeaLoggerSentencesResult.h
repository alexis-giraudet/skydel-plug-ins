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
    /// Result of GetNmeaLoggerSentences.
    ///
    /// Name      Type         Description
    /// --------- ------------ -------------------------------------------------------------------------------------------------------
    /// Sentences array string Identifiers of the NMEA sentences to generate, only "GGA", "GLL", "GSV", "RMC" and "ZDA" are supported.
    ///

    class GetNmeaLoggerSentencesResult;
    typedef std::shared_ptr<GetNmeaLoggerSentencesResult> GetNmeaLoggerSentencesResultPtr;
    
    
    class GetNmeaLoggerSentencesResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetNmeaLoggerSentencesResult";
      inline static const char* const Documentation = "Result of GetNmeaLoggerSentences.\n"      "\n"      "Name      Type         Description\n"      "--------- ------------ -------------------------------------------------------------------------------------------------------\n"      "Sentences array string Identifiers of the NMEA sentences to generate, only \"GGA\", \"GLL\", \"GSV\", \"RMC\" and \"ZDA\" are supported.";
      inline static const char* const TargetId = "";



          GetNmeaLoggerSentencesResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetNmeaLoggerSentencesResult(const std::vector<std::string>& sentences)
            : CommandResult(CmdName, TargetId)
          {

            setSentences(sentences);
          }

          GetNmeaLoggerSentencesResult(CommandBasePtr relatedCommand, const std::vector<std::string>& sentences)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setSentences(sentences);
          }



          static GetNmeaLoggerSentencesResultPtr create(const std::vector<std::string>& sentences)
          {
            return std::make_shared<GetNmeaLoggerSentencesResult>(sentences);
          }

          static GetNmeaLoggerSentencesResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& sentences)
          {
            return std::make_shared<GetNmeaLoggerSentencesResult>(relatedCommand, sentences);
          }

      static GetNmeaLoggerSentencesResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetNmeaLoggerSentencesResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::string>>::is_valid(m_values["Sentences"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Sentences"}; 
        return names; 
      }
      


          std::vector<std::string> sentences() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["Sentences"]);
          }

          void setSentences(const std::vector<std::string>& sentences)
          {
            m_values.AddMember("Sentences", parse_json<std::vector<std::string>>::format(sentences, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetNmeaLoggerSentencesResult);
  }
}

