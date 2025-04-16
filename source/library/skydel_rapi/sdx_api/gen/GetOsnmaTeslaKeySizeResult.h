#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetOsnmaTeslaKeySize.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------
    /// KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.
    ///              Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.
    ///

    class GetOsnmaTeslaKeySizeResult;
    typedef std::shared_ptr<GetOsnmaTeslaKeySizeResult> GetOsnmaTeslaKeySizeResultPtr;
    
    
    class GetOsnmaTeslaKeySizeResult : public CommandResult
    {
    public:
      inline static const char* const CmdName = "GetOsnmaTeslaKeySizeResult";
      inline static const char* const Documentation = "Result of GetOsnmaTeslaKeySize.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------------------------------------\n"      "KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.\n"      "             Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.";
      inline static const char* const TargetId = "";



          GetOsnmaTeslaKeySizeResult()
            : CommandResult(CmdName, TargetId)
          {}

          GetOsnmaTeslaKeySizeResult(int keySize)
            : CommandResult(CmdName, TargetId)
          {

            setKeySize(keySize);
          }

          GetOsnmaTeslaKeySizeResult(CommandBasePtr relatedCommand, int keySize)
            : CommandResult(CmdName, TargetId, relatedCommand)
          {

            setKeySize(keySize);
          }



          static GetOsnmaTeslaKeySizeResultPtr create(int keySize)
          {
            return std::make_shared<GetOsnmaTeslaKeySizeResult>(keySize);
          }

          static GetOsnmaTeslaKeySizeResultPtr create(CommandBasePtr relatedCommand, int keySize)
          {
            return std::make_shared<GetOsnmaTeslaKeySizeResult>(relatedCommand, keySize);
          }

      static GetOsnmaTeslaKeySizeResultPtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<GetOsnmaTeslaKeySizeResult>(ptr);
      }

      virtual bool isValid() const override
      {

                return m_values.IsObject()
                  && parse_json<int>::is_valid(m_values["KeySize"])
                ;
      }

      virtual std::string documentation() const override { return Documentation; }

      virtual const std::vector<std::string>& fieldNames() const override
      { 
        static const std::vector<std::string> names {"KeySize"}; 
        return names; 
      }
      


          int keySize() const
          {
            return parse_json<int>::parse(m_values["KeySize"]);
          }

          void setKeySize(int keySize)
          {
            m_values.AddMember("KeySize", parse_json<int>::format(keySize, m_values.GetAllocator()), m_values.GetAllocator());
          }

    };
    REGISTER_COMMAND_TO_FACTORY(GetOsnmaTeslaKeySizeResult);
  }
}

