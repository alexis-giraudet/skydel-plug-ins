#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/AntennaPatternType.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSpoofTxAntenna.
    ///
    /// Name Type               Description
    /// ---- ------------------ -------------------------------------------------------------------------------------------------------------------------
    /// Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.
    /// Type AntennaPatternType Pattern type
    /// Id   string             Transmitter unique identifier.
    ///

    class GetSpoofTxAntennaResult;
    typedef std::shared_ptr<GetSpoofTxAntennaResult> GetSpoofTxAntennaResultPtr;
    
    
    class GetSpoofTxAntennaResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetSpoofTxAntennaResult";
      inline static const char* const Documentation = "Result of GetSpoofTxAntenna.\n"      "\n"      "Name Type               Description\n"      "---- ------------------ -------------------------------------------------------------------------------------------------------------------------\n"      "Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"      "Type AntennaPatternType Pattern type\n"      "Id   string             Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          GetSpoofTxAntennaResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetSpoofTxAntennaResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
            : CommandResult(CmdName, TargetId)
          {

            setGain(gain);
            setType(type);
            setId(id);
          }

          GetSpoofTxAntennaResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setGain(gain);
            setType(type);
            setId(id);
          }



          static GetSpoofTxAntennaResultPtr create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
          {
            return std::make_shared<GetSpoofTxAntennaResult>(gain, type, id);
          }

          static GetSpoofTxAntennaResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
          {
            return std::make_shared<GetSpoofTxAntennaResult>(relatedCommand, gain, type, id);
          }

      static GetSpoofTxAntennaResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSpoofTxAntennaResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
                  && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Gain", "Type", "Id"}; 
        return names; 
      }
      


          std::vector<std::vector<double>> gain() const
          {
            return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
          }

          void setGain(const std::vector<std::vector<double>>& gain)
          {
            m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
          }



          Sdx::AntennaPatternType type() const
          {
            return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
          }

          void setType(const Sdx::AntennaPatternType& type)
          {
            m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string id() const
          {
            return parse_json<std::string>::parse(m_values["Id"]);
          }

          void setId(const std::string& id)
          {
            m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSpoofTxAntennaResult);
  }
}

