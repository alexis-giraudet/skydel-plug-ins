#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set QZSS L5 health (Health of L5 signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L5 health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class SetQzssL5HealthForSV;
    typedef std::shared_ptr<SetQzssL5HealthForSV> SetQzssL5HealthForSVPtr;
    
    
    class SetQzssL5HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetQzssL5HealthForSV();

      SetQzssL5HealthForSV(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static SetQzssL5HealthForSVPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static SetQzssL5HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

