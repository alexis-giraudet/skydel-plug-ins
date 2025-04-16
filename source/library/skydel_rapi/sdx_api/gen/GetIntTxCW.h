#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get informations about the CW signal of the transmitter.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string CW unique identifier.
    ///

    class GetIntTxCW;
    typedef std::shared_ptr<GetIntTxCW> GetIntTxCWPtr;
    
    
    class GetIntTxCW : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetIntTxCW";
      inline static const char* const Documentation = "Get informations about the CW signal of the transmitter.\n"      "\n"      "Name          Type   Description\n"      "------------- ------ ------------------------------\n"      "TransmitterId string Transmitter unique identifier.\n"      "SignalId      string CW unique identifier.";
      inline static const char* const TargetId = "";



          GetIntTxCW()
            : CommandBase(CmdName, TargetId)
          {}

          GetIntTxCW(const std::string& transmitterId, const std::string& signalId)
            : CommandBase(CmdName, TargetId)
          {

            setTransmitterId(transmitterId);
            setSignalId(signalId);
          }


          static GetIntTxCWPtr create(const std::string& transmitterId, const std::string& signalId)
          {
            return std::make_shared<GetIntTxCW>(transmitterId, signalId);
          }

      static GetIntTxCWPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetIntTxCW>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["TransmitterId"])
                  && parse_json<std::string>::is_valid(m_values["SignalId"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"TransmitterId", "SignalId"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string transmitterId() const
          {
            return parse_json<std::string>::parse(m_values["TransmitterId"]);
          }

          void setTransmitterId(const std::string& transmitterId)
          {
            m_values.AddMember("TransmitterId", parse_json<std::string>::format(transmitterId, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string signalId() const
          {
            return parse_json<std::string>::parse(m_values["SignalId"]);
          }

          void setSignalId(const std::string& signalId)
          {
            m_values.AddMember("SignalId", parse_json<std::string>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetIntTxCW);
  }
}

