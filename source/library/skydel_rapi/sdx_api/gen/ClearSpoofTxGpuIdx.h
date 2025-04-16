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
    /// Reset the spoofer's signal GPU index to default.
    ///
    /// Name     Type   Description
    /// -------- ------ -------------------------------
    /// SignalId int    Spoofer output number, 0-based.
    /// Id       string Transmitter unique identifier.
    ///

    class ClearSpoofTxGpuIdx;
    typedef std::shared_ptr<ClearSpoofTxGpuIdx> ClearSpoofTxGpuIdxPtr;
    
    
    class ClearSpoofTxGpuIdx : public CommandBase
    {
    public:
      inline static const char* const CmdName = "ClearSpoofTxGpuIdx";
      inline static const char* const Documentation = "Reset the spoofer's signal GPU index to default.\n"      "\n"      "Name     Type   Description\n"      "-------- ------ -------------------------------\n"      "SignalId int    Spoofer output number, 0-based.\n"      "Id       string Transmitter unique identifier.";
      inline static const char* const TargetId = "";



          ClearSpoofTxGpuIdx()
            : CommandBase(CmdName, TargetId)
          {}

          ClearSpoofTxGpuIdx(int signalId, const std::string& id)
            : CommandBase(CmdName, TargetId)
          {

            setSignalId(signalId);
            setId(id);
          }


          static ClearSpoofTxGpuIdxPtr create(int signalId, const std::string& id)
          {
            return std::make_shared<ClearSpoofTxGpuIdx>(signalId, id);
          }

      static ClearSpoofTxGpuIdxPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<ClearSpoofTxGpuIdx>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["SignalId"])
                  && parse_json<std::string>::is_valid(m_values["Id"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"SignalId", "Id"}; 
        return names; 
      }
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
          }


          int signalId() const
          {
            return parse_json<int>::parse(m_values["SignalId"]);
          }

          void setSignalId(int signalId)
          {
            m_values.AddMember("SignalId", parse_json<int>::format(signalId, m_values.GetAllocator()), m_values.GetAllocator());
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
    REGISTER_COMMAND_TO_FACTORY(ClearSpoofTxGpuIdx);
  }
}

