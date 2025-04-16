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
    /// Result of GetAllSignalsFromIntTx.
    ///
    /// Name      Type         Description
    /// --------- ------------ -----------------------------------------------------
    /// Id        string       Transmitter unique identifier.
    /// IdsSignal array string List of signal ID for this interferences transmitter.
    ///

    class GetAllSignalsFromIntTxResult;
    typedef std::shared_ptr<GetAllSignalsFromIntTxResult> GetAllSignalsFromIntTxResultPtr;
    
    
    class GetAllSignalsFromIntTxResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetAllSignalsFromIntTxResult";
      inline static const char* const Documentation = "Result of GetAllSignalsFromIntTx.\n"      "\n"      "Name      Type         Description\n"      "--------- ------------ -----------------------------------------------------\n"      "Id        string       Transmitter unique identifier.\n"      "IdsSignal array string List of signal ID for this interferences transmitter.";
      inline static const char* const TargetId = "";



          GetAllSignalsFromIntTxResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetAllSignalsFromIntTxResult(const std::string& id, const std::vector<std::string>& idsSignal)
            : CommandResult(CmdName, TargetId)
          {

            setId(id);
            setIdsSignal(idsSignal);
          }

          GetAllSignalsFromIntTxResult(CommandBasePtr relatedCommand, const std::string& id, const std::vector<std::string>& idsSignal)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setId(id);
            setIdsSignal(idsSignal);
          }



          static GetAllSignalsFromIntTxResultPtr create(const std::string& id, const std::vector<std::string>& idsSignal)
          {
            return std::make_shared<GetAllSignalsFromIntTxResult>(id, idsSignal);
          }

          static GetAllSignalsFromIntTxResultPtr create(CommandBasePtr relatedCommand, const std::string& id, const std::vector<std::string>& idsSignal)
          {
            return std::make_shared<GetAllSignalsFromIntTxResult>(relatedCommand, id, idsSignal);
          }

      static GetAllSignalsFromIntTxResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetAllSignalsFromIntTxResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<std::string>::is_valid(m_values["Id"])
                  && parse_json<std::vector<std::string>>::is_valid(m_values["IdsSignal"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"Id", "IdsSignal"}; 
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



          std::vector<std::string> idsSignal() const
          {
            return parse_json<std::vector<std::string>>::parse(m_values["IdsSignal"]);
          }

          void setIdsSignal(const std::vector<std::string>& idsSignal)
          {
            m_values.AddMember("IdsSignal", parse_json<std::vector<std::string>>::format(idsSignal, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetAllSignalsFromIntTxResult);
  }
}

