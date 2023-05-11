#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get a spoofer transmitter. For set : the transmitter Id parameter is not set (empty string),
    /// Skydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the
    /// command will fail.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetSpoofTx;
    typedef std::shared_ptr<GetSpoofTx> GetSpoofTxPtr;
    
    
    class GetSpoofTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSpoofTx();

      GetSpoofTx(const std::string& id);

      static GetSpoofTxPtr create(const std::string& id);
      static GetSpoofTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

