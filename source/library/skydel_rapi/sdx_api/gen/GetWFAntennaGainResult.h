#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetWFAntennaGain.
    ///
    /// Name Type Description
    /// ---- ---- -----------------
    /// Gain int  The CRPA LNA gain
    ///

    class GetWFAntennaGainResult;
    typedef std::shared_ptr<GetWFAntennaGainResult> GetWFAntennaGainResultPtr;
    
    
    class GetWFAntennaGainResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetWFAntennaGainResult";
      inline static const char* const Documentation = "Result of GetWFAntennaGain.\n"      "\n"      "Name Type Description\n"      "---- ---- -----------------\n"      "Gain int  The CRPA LNA gain";
      inline static const char* const TargetId = "";



          GetWFAntennaGainResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetWFAntennaGainResult(int gain)
            : CommandResult(CmdName, TargetId)
          {

            setGain(gain);
          }

          GetWFAntennaGainResult(CommandBasePtr relatedCommand, int gain)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setGain(gain);
          }



          static GetWFAntennaGainResultPtr create(int gain)
          {
            return std::make_shared<GetWFAntennaGainResult>(gain);
          }

          static GetWFAntennaGainResultPtr create(CommandBasePtr relatedCommand, int gain)
          {
            return std::make_shared<GetWFAntennaGainResult>(relatedCommand, gain);
          }

      static GetWFAntennaGainResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetWFAntennaGainResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["Gain"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Gain"}; 
        return names; 
      }
      


          int gain() const
          {
            return parse_json<int>::parse(m_values["Gain"]);
          }

          void setGain(int gain)
          {
            m_values.AddMember("Gain", parse_json<int>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetWFAntennaGainResult);
  }
}

