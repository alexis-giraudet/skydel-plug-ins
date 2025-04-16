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
    /// Get all signal ID from this interference transmitters and this signal type. If the signal type is invalid, get the IDs of CW type.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------------------------------------------------------------
    /// IdTransmitter string Transmitter unique identifier.
    /// SignalType    string Type of signal. Accepted signals are : "CW", "Chirp", "Pulse", "BPSK", "BOC", "AWGN"
    ///

    class GetSignalFromIntTx;
    typedef std::shared_ptr<GetSignalFromIntTx> GetSignalFromIntTxPtr;
    
    
    class GetSignalFromIntTx : public CommandBase
    {
    public:
      inline static const char* const CmdName = "GetSignalFromIntTx";
      inline static const char* const Documentation = "Get all signal ID from this interference transmitters and this signal type. If the signal type is invalid, get the IDs of CW type.\n"      "\n"      "Name          Type   Description\n"      "------------- ------ ------------------------------------------------------------------------------------\n"      "IdTransmitter string Transmitter unique identifier.\n"      "SignalType    string Type of signal. Accepted signals are : \"CW\", \"Chirp\", \"Pulse\", \"BPSK\", \"BOC\", \"AWGN\"";
      inline static const char* const TargetId = "";



          GetSignalFromIntTx()
            : CommandBase(CmdName, TargetId)
          {}

          GetSignalFromIntTx(const std::string& idTransmitter, const std::string& signalType)
            : CommandBase(CmdName, TargetId)
          {

            setIdTransmitter(idTransmitter);
            setSignalType(signalType);
          }


          static GetSignalFromIntTxPtr create(const std::string& idTransmitter, const std::string& signalType)
          {
            return std::make_shared<GetSignalFromIntTx>(idTransmitter, signalType);
          }

      static GetSignalFromIntTxPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetSignalFromIntTx>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["IdTransmitter"])
                  && parse_json<std::string>::is_valid(m_values["SignalType"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"IdTransmitter", "SignalType"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          std::string idTransmitter() const
          {
            return parse_json<std::string>::parse(m_values["IdTransmitter"]);
          }

          void setIdTransmitter(const std::string& idTransmitter)
          {
            m_values.AddMember("IdTransmitter", parse_json<std::string>::format(idTransmitter, m_values.GetAllocator()), m_values.GetAllocator());
          }



          std::string signalType() const
          {
            return parse_json<std::string>::parse(m_values["SignalType"]);
          }

          void setSignalType(const std::string& signalType)
          {
            m_values.AddMember("SignalType", parse_json<std::string>::format(signalType, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetSignalFromIntTx);
  }
}

