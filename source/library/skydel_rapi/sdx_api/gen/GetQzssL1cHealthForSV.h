#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS L1C health (Health of L1C signal)
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssL1cHealthForSV;
    typedef std::shared_ptr<GetQzssL1cHealthForSV> GetQzssL1cHealthForSVPtr;
    
    
    class GetQzssL1cHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssL1cHealthForSV();

      GetQzssL1cHealthForSV(int svId, const Sdx::optional<std::string>& dataSetName = {});

      static GetQzssL1cHealthForSVPtr create(int svId, const Sdx::optional<std::string>& dataSetName = {});
      static GetQzssL1cHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    
  }
}

