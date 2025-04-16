#pragma once

#include <memory>
#include "command_base.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set OSNMA TESLA key size.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------
    /// KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.
    ///              Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.
    ///

    class SetOsnmaTeslaKeySize;
    typedef std::shared_ptr<SetOsnmaTeslaKeySize> SetOsnmaTeslaKeySizePtr;
    
    
    class SetOsnmaTeslaKeySize : public CommandBase
    {
    public:
      inline static const char* const CmdName = "SetOsnmaTeslaKeySize";
      inline static const char* const Documentation = "Set OSNMA TESLA key size.\n"      "\n"      "Name    Type Description\n"      "------- ---- ----------------------------------------------------------------------------------------------\n"      "KeySize int  TESLA key size in bits. Accepted key sizes are: 96, 104, 112, 120, 128, 160, 192, 224 and 256.\n"      "             Note: Only 128, 192 and 256 bits keys can be be used with CMAC-AES.";
      inline static const char* const TargetId = "";



          SetOsnmaTeslaKeySize()
            : CommandBase(CmdName, TargetId)
          {}

          SetOsnmaTeslaKeySize(int keySize)
            : CommandBase(CmdName, TargetId)
          {

            setKeySize(keySize);
          }


          static SetOsnmaTeslaKeySizePtr create(int keySize)
          {
            return std::make_shared<SetOsnmaTeslaKeySize>(keySize);
          }

      static SetOsnmaTeslaKeySizePtr dynamicCast(CommandBasePtr ptr)
      {
        return std::dynamic_pointer_cast<SetOsnmaTeslaKeySize>(ptr);
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
      


          int executePermission() const
          {
            return EXECUTE_IF_IDLE;
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
    REGISTER_COMMAND_TO_FACTORY(SetOsnmaTeslaKeySize);
  }
}

