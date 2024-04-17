#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get whether a transmitter should be hidden on the map.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Transmitter unique identifier.
    ///

    class GetIntTxHiddenOnMap;
    typedef std::shared_ptr<GetIntTxHiddenOnMap> GetIntTxHiddenOnMapPtr;
    
    
    class GetIntTxHiddenOnMap : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxHiddenOnMap();

      GetIntTxHiddenOnMap(const std::string& id);

      static GetIntTxHiddenOnMapPtr create(const std::string& id);
      static GetIntTxHiddenOnMapPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

