#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGaussianNoiseSeed.
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------------
    /// Id        string Target identifier.
    /// OutputIdx int    RF Output index (zero-based).
    /// Seed      int    Gaussian Noise seed. Value must be a positive integer between 0 and 2147483647.
    ///

    class GetGaussianNoiseSeedResult;
    typedef std::shared_ptr<GetGaussianNoiseSeedResult> GetGaussianNoiseSeedResultPtr;
    
    
    class GetGaussianNoiseSeedResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetGaussianNoiseSeedResult";
      inline static const char* const Documentation = "Result of GetGaussianNoiseSeed.\n"      "\n"      "Name      Type   Description\n"      "--------- ------ -------------------------------------------------------------------------------\n"      "Id        string Target identifier.\n"      "OutputIdx int    RF Output index (zero-based).\n"      "Seed      int    Gaussian Noise seed. Value must be a positive integer between 0 and 2147483647.";
      inline static const char* const TargetId = "";



          GetGaussianNoiseSeedResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetGaussianNoiseSeedResult(const std::string& id, int outputIdx, int seed)
            : CommandResult(CmdName, TargetId)
          {

            setId(id);
            setOutputIdx(outputIdx);
            setSeed(seed);
          }

          GetGaussianNoiseSeedResult(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, int seed)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setId(id);
            setOutputIdx(outputIdx);
            setSeed(seed);
          }



          static GetGaussianNoiseSeedResultPtr create(const std::string& id, int outputIdx, int seed)
          {
            return std::make_shared<GetGaussianNoiseSeedResult>(id, outputIdx, seed);
          }

          static GetGaussianNoiseSeedResultPtr create(CommandBasePtr relatedCommand, const std::string& id, int outputIdx, int seed)
          {
            return std::make_shared<GetGaussianNoiseSeedResult>(relatedCommand, id, outputIdx, seed);
          }

      static GetGaussianNoiseSeedResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetGaussianNoiseSeedResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                  && parse_json<int>::is_valid(m_values["OutputIdx"])
                  && parse_json<int>::is_valid(m_values["Seed"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id", "OutputIdx", "Seed"}; 
        return names; 
      }
      


          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int outputIdx() const
          {
            return parse_json<int>::parse(m_values["OutputIdx"]);
          }

          void setOutputIdx(int outputIdx)
          {
            m_values.AddMember("OutputIdx", parse_json<int>::format(outputIdx, m_values.GetAllocator()), m_values.GetAllocator());
          }



          int seed() const
          {
            return parse_json<int>::parse(m_values["Seed"]);
          }

          void setSeed(int seed)
          {
            m_values.AddMember("Seed", parse_json<int>::format(seed, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetGaussianNoiseSeedResult);
  }
}

