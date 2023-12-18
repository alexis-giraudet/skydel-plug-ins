#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the NMEA sentences that will be generated by the logger.
    ///
    /// Name      Type         Description
    /// --------- ------------ -------------------------------------------------------------------------------------------------------
    /// Sentences array string Identifiers of the NMEA sentences to generate, only "GGA", "GLL", "GSV", "RMC" and "ZDA" are supported.
    ///

    class SetNmeaLoggerSentences;
    typedef std::shared_ptr<SetNmeaLoggerSentences> SetNmeaLoggerSentencesPtr;
    
    
    class SetNmeaLoggerSentences : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetNmeaLoggerSentences();

      SetNmeaLoggerSentences(const std::vector<std::string>& sentences);

      static SetNmeaLoggerSentencesPtr create(const std::vector<std::string>& sentences);
      static SetNmeaLoggerSentencesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** sentences ****
      std::vector<std::string> sentences() const;
      void setSentences(const std::vector<std::string>& sentences);
    };
    
  }
}

